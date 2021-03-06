﻿#include <set>
#include <list>
#include <cassert>
#include <optional>
#include <forward_list>
#include "sstd_library_gc_manager.hpp"

namespace sstd {

    using GrayListType = std::forward_list<GCMemoryNodeWatcher *,
        sstd::allocator< GCMemoryNodeWatcher * > >;

    class ReallyGCMemoryNodeWatcher final :
        public GCMemoryNodeWatcher {
    public:
        using WatcherList = std::list< ReallyGCMemoryNodeWatcher, sstd::allocator< ReallyGCMemoryNodeWatcher> >;
        using WatcherPointerList = std::list< GCMemoryNodeWatcher *, sstd::allocator< GCMemoryNodeWatcher * > >;
        inline ReallyGCMemoryNodeWatcher();
        inline ~ReallyGCMemoryNodeWatcher();
    public:
        std::int32_t rootCount{ 0 };
        WatcherList::iterator thePos;
        WatcherPointerList::iterator rootPos;
    };

    inline bool isRoot(GCMemoryNodeWatcher * arg) {
        return (reinterpret_cast<ReallyGCMemoryNodeWatcher *>(arg)
            ->rootCount) > 0;
    }

    GCMemoryNodeChildrenWalker::GCMemoryNodeChildrenWalker(void * arg) :
        data(arg) {
    }

    /*将未扫描到的（白）加入待扫描列表（灰）*/
    void GCMemoryNodeChildrenWalker::findChild(GCMemoryNode * arg) {

        auto varWatcher = arg->getGCMemoryWatcher();

        if (varWatcher->getState() == GCMemoryNodeState::White) {
            auto grayList = reinterpret_cast<GrayListType*>(data);
            varWatcher->state = GCMemoryNodeState::Gray;
            grayList->push_front(varWatcher);
        }

    }

    class GCMemoryManagerPrivate {
    public:
        constexpr const static std::size_t minGCItemsSize{ 512 };
        ReallyGCMemoryNodeWatcher::WatcherPointerList root;
        ReallyGCMemoryNodeWatcher::WatcherList allItems;
        std::size_t lastGCSize{ minGCItemsSize };
        std::int32_t pauseGCCount{ 0 };
        inline GCMemoryManagerPrivate() {
        }

        inline ~GCMemoryManagerPrivate() {
            for (auto & varI : allItems) {
                eraseANode(&varI);
            }
            for (auto & varI : root) {
                reinterpret_cast<ReallyGCMemoryNodeWatcher*>(varI)->rootCount = 0;
            }
            root.clear();
            allItems.clear();
        }

        inline void eraseANode(GCMemoryNodeWatcher * arg) {
            if (arg->state != GCMemoryNodeState::IsDeleted) {
                delete arg->node;
            }
        }

        /*gc算法很简单，相当于做一个深度最优先遍历*/
        inline void gc() {

            if (pauseGCCount > 0) {
                return;
            }

            GrayListType varGray;

            {
                auto varPos = root.begin();
            label_for_add_root_to_gray_list:
                auto varEndPos = root.end();
                for (; varPos != varEndPos; ++varPos) {
                    if ((*varPos)->state == GCMemoryNodeState::IsDeleted) {
                        {
                            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(*varPos)->rootCount = 0;
                        }
                        varPos = root.erase(varPos);
                        goto label_for_add_root_to_gray_list;
                    } else if ((*varPos)->state == GCMemoryNodeState::White) {
                        (*varPos)->state = GCMemoryNodeState::Gray;
                        varGray.push_front(*varPos);
                    }
                }
            }

            GCMemoryNodeChildrenWalker varWalker{ &varGray };

            while (!varGray.empty()) {
                auto * varItem = varGray.front();
                varGray.pop_front();

                assert(varItem->state != GCMemoryNodeState::IsDeleted);
                assert(varItem->state == GCMemoryNodeState::Gray);

                varItem->state = GCMemoryNodeState::Black;
                varItem->node->directChildren(&varWalker);

            }

            removeWhiteAndDeleted();

            this->lastGCSize = (allItems.size() > minGCItemsSize) ?
                (allItems.size()) : minGCItemsSize;

        }/*~gc()*/

        inline void removeWhiteAndDeleted() {
            auto varPos = allItems.begin();
        label_for:
            auto varEndPos = allItems.end();
            for (; varPos != varEndPos; ++varPos) {
                if (varPos->state == GCMemoryNodeState::IsDeleted) {
                    varPos = allItems.erase(varPos);
                    goto label_for;
                } else if (varPos->state == GCMemoryNodeState::White) {
                    delete varPos->node;
                    varPos = allItems.erase(varPos);
                    goto label_for;
                }
                varPos->state = GCMemoryNodeState::White;
            }
        }
    private:
        sstd_class(GCMemoryManagerPrivate);
    };

    void GCMemoryManager::moveToAnotherGCManager(GCMemoryNode * argFrom,
        GCMemoryManager * argTo) {
        if (this == argTo) {
            return;
        }
        auto varWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher *>(argFrom->thisWatcher);
        if (varWatcher->state == GCMemoryNodeState::IsDeleted) {
            return;
        }
        assert(varWatcher->manager == this);

        argTo->thisPrivate->allItems.splice(
            argTo->thisPrivate->allItems.begin(),
            thisPrivate->allItems,
            varWatcher->thePos);

        if (isRoot(varWatcher)) {
            argTo->thisPrivate->root.splice(
                argTo->thisPrivate->root.begin(),
                thisPrivate->root,
                varWatcher->rootPos);
        }

        varWatcher->manager = argTo;

        argTo->try_gc();
    }

    void GCMemoryManager::moveToAnotherGCManager(GCMemoryManager * arg) {
        if (this == arg) {
            return;
        }

        /*改变对象管理者...*/
        for (auto & varI : thisPrivate->allItems) {
            varI.manager = arg;
        }

        /*将所有数据移动到另一个管理器...*/
        arg->thisPrivate->allItems.splice(arg->thisPrivate->allItems.begin(),
            std::move(thisPrivate->allItems));
        assert(thisPrivate->allItems.empty());

        /*将所有根对象移动到另一个管理器...*/
        arg->thisPrivate->root.splice(arg->thisPrivate->root.begin(),
            std::move(thisPrivate->root));

        /*更新其余状态*/
        thisPrivate->lastGCSize = thisPrivate->minGCItemsSize;

        arg->try_gc();
    }

    void GCMemoryManager::markAsRoot(GCMemoryNode * arg) {
        assert(arg->thisWatcher->manager == this);
        auto argWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(arg->thisWatcher);
        ++(argWatcher->rootCount);
        if (argWatcher->rootCount!=1) {
            return/*mark to root only once...*/;
        }
        thisPrivate->root.push_front(arg->thisWatcher);
        argWatcher->rootPos = thisPrivate->root.begin();
    }

    void GCMemoryManager::removeFromRoot(GCMemoryNode * arg) {
        assert(arg->thisWatcher->manager == this);
        auto argWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(arg->thisWatcher);
        --(argWatcher->rootCount);
        if (argWatcher->rootCount > 0) {
            return;
        }
        thisPrivate->root.erase(argWatcher->rootPos);
        argWatcher->rootCount = 0;
    }

    /*对象数量比上一次加倍，进行gc*/
    void GCMemoryManager::try_gc() {

        if (thisPrivate->pauseGCCount > 0) {
            return;
        }

        if (thisPrivate->allItems.size() <= thisPrivate->lastGCSize) {
            return;
        }

        if ((thisPrivate->allItems.size() - thisPrivate->lastGCSize)
            >= thisPrivate->lastGCSize) {
            thisPrivate->gc();
        }
    }

    void GCMemoryManager::addNode(GCMemoryNode * arg) {
        assert(arg->thisWatcher == nullptr);
        auto & var = thisPrivate->allItems.emplace_front();
        var.thePos = thisPrivate->allItems.begin();
        arg->thisWatcher = &var;
        assert(arg->thisWatcher->manager == nullptr);
        arg->thisWatcher->manager = this;
        assert(arg->thisWatcher->node == nullptr);
        arg->thisWatcher->node = arg;
        arg->thisWatcher->state = GCMemoryNodeState::Black;
        this->try_gc();
    }

    void GCMemoryManager::gc() {
        thisPrivate->gc();
    }

    void GCMemoryManager::markAsDeleted(GCMemoryNode * arg) {
        arg->thisWatcher->state = GCMemoryNodeState::IsDeleted;
    }

    void GCMemoryManager::lock()  {
        ++thisPrivate->pauseGCCount;
    }

    void GCMemoryManager::unlock() {
        --thisPrivate->pauseGCCount;
        try_gc();
    }

    GCMemoryManager::~GCMemoryManager() {
        delete thisPrivate;
    }

    GCMemoryManager::GCMemoryManager() :
        thisPrivate{ sstd_new< GCMemoryManagerPrivate >() } {
    }

    GCMemoryNode::GCMemoryNode(const gc_lock & arg) {
        arg.mutex()->addNode(this);
    }

    void GCMemoryNode::directChildren(GCMemoryNodeChildrenWalker *) {
    }

    GCMemoryNode::~GCMemoryNode() {
        thisWatcher->state = GCMemoryNodeState::IsDeleted;
    }

    inline ReallyGCMemoryNodeWatcher::ReallyGCMemoryNodeWatcher() {
    }

    inline ReallyGCMemoryNodeWatcher::~ReallyGCMemoryNodeWatcher() {
        if (isRoot(this)) {
            getManager()->thisPrivate->root.erase(rootPos);
        }
    }

    GCMemoryNodeWatcher::~GCMemoryNodeWatcher() {
    }

    GCMemoryNodeWatcher::GCMemoryNodeWatcher() :
        manager(nullptr),
        node(nullptr) {
    }

}/*namespace sstd*/
