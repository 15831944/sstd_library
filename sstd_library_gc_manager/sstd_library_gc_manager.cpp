﻿#include <set>
#include <list>
#include <cassert>
#include <optional>
#include "sstd_library_gc_manager.hpp"

namespace sstd {

    class ReallyGCMemoryNodeWatcher final :
        public GCMemoryNodeWatcher {
    public:
        using WatcherList = std::list< ReallyGCMemoryNodeWatcher >;
        using WatcherPointerList = std::list< GCMemoryNodeWatcher * >;
        WatcherList::iterator thePos;
        std::optional< WatcherPointerList::iterator > rootPos;
        inline ReallyGCMemoryNodeWatcher();
        inline ~ReallyGCMemoryNodeWatcher();
    };

    GCMemoryNodeChildrenWalker::GCMemoryNodeChildrenWalker(void * arg) :
        data(arg) {
    }

    /*将未扫描到的（白）加入待扫描列表（灰）*/
    void GCMemoryNodeChildrenWalker::findChild(GCMemoryNode * arg) {

        auto varWatcher = arg->getGCMemoryWatcher();
        auto grayList = reinterpret_cast<
            ReallyGCMemoryNodeWatcher::WatcherPointerList*>(data);

        if (varWatcher->getState() == GCMemoryNodeState::White) {
            varWatcher->state = GCMemoryNodeState::Gray;
            grayList->push_back(varWatcher);
        }

    }

    class GCMemoryManagerPrivate {
    public:
        constexpr const static std::size_t minGCItemsSize{ 512 };
        ReallyGCMemoryNodeWatcher::WatcherPointerList root;
        ReallyGCMemoryNodeWatcher::WatcherList allItems;
        std::size_t lastGCSize{ minGCItemsSize };

        inline GCMemoryManagerPrivate() {
        }

        inline ~GCMemoryManagerPrivate() {
            for (auto & varI : allItems) {
                eraseANode(&varI);
            }
            for (auto & varI : root) {
                reinterpret_cast<ReallyGCMemoryNodeWatcher*>(varI)
                    ->rootPos.reset();
            }
            root.clear();
            allItems.clear();
        }

        inline void eraseANode(GCMemoryNodeWatcher * arg) {
            if (arg->state != GCMemoryNodeState::IsDeleted) {
                delete arg->node;
            }
        }

        inline void gc() {

            using GrayListType = ReallyGCMemoryNodeWatcher::WatcherPointerList;
            GrayListType varGray;

            {
                auto varPos = root.begin();
            label_for_add_root_to_gray_list:
                auto varEndPos = root.end();
                for (; varPos != varEndPos; ++varPos) {
                    if ((*varPos)->state == GCMemoryNodeState::IsDeleted) {
                        {
                            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(*varPos)
                                ->rootPos.reset();
                        }
                        varPos = root.erase(varPos);
                        goto label_for_add_root_to_gray_list;
                    } else if ((*varPos)->state == GCMemoryNodeState::White) {
                        (*varPos)->state = GCMemoryNodeState::Gray;
                        varGray.push_back(*varPos);
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

    };

    void GCMemoryManager::moveToAnotherGCManager(GCMemoryNode * argFrom, 
        GCMemoryManager * argTo) {
        if (this==argTo) {
            return;
        }
        auto varWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher *>(argFrom->thisWatcher);
        if (varWatcher->state == GCMemoryNodeState::IsDeleted) {
            return;
        }
        assert( varWatcher->manager == this );
        bool varIsRoot = static_cast<bool>( varWatcher->rootPos );
        thisPrivate->allItems.erase( varWatcher->thePos );
        argFrom->thisWatcher = nullptr;
        argTo->addNode(argFrom);
        if (varIsRoot) {
            argTo->markAsRoot(argFrom);
        }
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
    }

    void GCMemoryManager::markAsRoot(GCMemoryNode * arg) {
        assert(arg->thisWatcher->manager == this);
        auto argWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(arg->thisWatcher);
        if (argWatcher->rootPos) {
            return/*it is root , do not need mark again ... */;
        }
        thisPrivate->root.push_front(arg->thisWatcher);
        argWatcher->rootPos.emplace(thisPrivate->root.begin());
    }

    void GCMemoryManager::removeFromRoot(GCMemoryNode * arg) {
        assert(arg->thisWatcher->manager == this);
        auto argWatcher =
            reinterpret_cast<ReallyGCMemoryNodeWatcher*>(arg->thisWatcher);
        if (!(argWatcher->rootPos)) {
            return/*it is not root , do not need remove from root ...*/;
        }
        thisPrivate->root.erase(*(argWatcher->rootPos));
        argWatcher->rootPos.reset();
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

        if (thisPrivate->allItems.size() <= thisPrivate->lastGCSize) {
            return;
        }

        if ((thisPrivate->allItems.size() - thisPrivate->lastGCSize)
            >= thisPrivate->lastGCSize) {
            thisPrivate->gc();
        }

    }

    void GCMemoryManager::gc() {
        thisPrivate->gc();
    }

    void GCMemoryManager::markAsDeleted(GCMemoryNode * arg) {
        arg->thisWatcher->state = GCMemoryNodeState::IsDeleted;
    }

    GCMemoryManager::~GCMemoryManager() {
        delete thisPrivate;
    }

    GCMemoryManager::GCMemoryManager() :
        thisPrivate{ new GCMemoryManagerPrivate } {
    }

    GCMemoryNode::GCMemoryNode(GCMemoryNode *parent) :
        GCMemoryNode(parent->thisWatcher->manager) {
    }

    GCMemoryNode::GCMemoryNode(GCMemoryManager * arg) {
        arg->addNode(this);
    }

    void GCMemoryNode::directChildren(GCMemoryNodeChildrenWalker *) {
    }

    GCMemoryNode::~GCMemoryNode() {
        thisWatcher->state = GCMemoryNodeState::IsDeleted;
    }

    inline ReallyGCMemoryNodeWatcher::ReallyGCMemoryNodeWatcher() {
    }

    inline ReallyGCMemoryNodeWatcher::~ReallyGCMemoryNodeWatcher() {
        if (rootPos) {
            getManager()->thisPrivate->root.erase(*rootPos);
        }
    }

    GCMemoryNodeWatcher::~GCMemoryNodeWatcher() {
    }

    GCMemoryNodeWatcher::GCMemoryNodeWatcher() :
        manager(nullptr),
        node(nullptr) {
    }

}/*namespace sstd*/
