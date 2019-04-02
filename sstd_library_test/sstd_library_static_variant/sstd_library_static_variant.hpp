﻿#pragma once

#include <sstd_library.hpp>
#include <typeinfo>
#include <typeindex>

namespace _theSSTDLibraryStaticVariantFile {

    typedef std::pair<void*,void(*)(void *)> (*ConvertFunction)(void *);
    extern std::size_t registerTypeID(const std::type_index &);
    extern bool registerCastFunction( std::size_t/*from*/,std::size_t/*to*/,ConvertFunction/*function*/);
    extern ConvertFunction findCastFunction(std::size_t /*from*/,std::size_t /*to*/);
    extern bool registerTypeName(std::size_t,std::string_view);

}/**/

namespace sstd {

    template<typename T1>
    class RegisterStaticClass{
        using T = std::remove_cv_t< std::remove_reference_t<T1> >;
    public:
        using ConvertFunction = _theSSTDLibraryStaticVariantFile::ConvertFunction;
    public:
        using TheType = T;
        constexpr inline static bool isRegistered() noexcept {
            return true;
        }

        inline static std::size_t typeIndex() noexcept {
            const static auto varAns =
                _theSSTDLibraryStaticVariantFile::registerTypeID( typeid ( TheType ) );
            return varAns;
        }

        template<typename To>
        inline static bool registerConvertFunction(ConvertFunction arg){
            using TheTypeTo = RegisterStaticClass< typename RegisterStaticClass<To>::TheType >;
            if constexpr( std::is_same_v< typename TheTypeTo::TheType , TheType > ){
                return true;
            }else{
                auto varFromTypeIndex = typeIndex();
                auto varToTypeIndex = TheTypeTo::typeIndex();
                return
                _theSSTDLibraryStaticVariantFile::registerCastFunction( varFromTypeIndex,
                                                                        varToTypeIndex,
                                                                        arg );
            }
        }

        template<typename To>
        inline static ConvertFunction convertFunction(std::size_t argFrom,std::size_t argTo){
            using TheTypeTo = RegisterStaticClass< typename RegisterStaticClass<To>::TheType >;
            if constexpr( std::is_same_v< typename TheTypeTo::TheType , TheType > ){
                return [](void * arg)->std::pair<void *,void(*)(void *)>{
                    return {arg,nullptr};
                };
            }else{
                 return _theSSTDLibraryStaticVariantFile::findCastFunction(argFrom,argTo);
            }
        }

    };


}/*namespace sstd*/














