﻿//Copyright (c) 2008-2017 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_QVM_9673ED9162F6768D4F74A4AD0576876
#define BOOST_QVM_9673ED9162F6768D4F74A4AD0576876

//This file was generated by a program. Do not edit manually.

#include <sstd/boost/qvm/detail/swizzle_traits.hpp>
#include <sstd/boost/qvm/enable_if.hpp>
#include <sstd/boost/qvm/inline.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::sw01_<qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<-2 > > > const &
        _11()
            {
            return *reinterpret_cast<qvm_detail::sw01_<qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<-2 > > > const *>(qvm_detail::get_null());
            }
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::sw01_<qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<-2 > > > const &
        _01()
            {
            return *reinterpret_cast<qvm_detail::sw01_<qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<-2 > > > const *>(qvm_detail::get_null());
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-2 > > > const &>::type
        W1( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-2 > > > &>::type
        W1( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-2 > > > const &>::type
        Z1( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-2 > > > &>::type
        Z1( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-2 > > > const &>::type
        Y1( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-2 > > > &>::type
        Y1( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > const &>::type
        X1( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > const &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > const &>::type
        X1( S const & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > &>::type
        X1( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > &>::type
        X1( S & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-2 > > > &>(a);
            }
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::sw01_<qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<-1 > > > const &
        _10()
            {
            return *reinterpret_cast<qvm_detail::sw01_<qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<-1 > > > const *>(qvm_detail::get_null());
            }
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::sw01_<qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<-1 > > > const &
        _00()
            {
            return *reinterpret_cast<qvm_detail::sw01_<qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<-1 > > > const *>(qvm_detail::get_null());
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-1 > > > const &>::type
        W0( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-1 > > > &>::type
        W0( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<-1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-1 > > > const &>::type
        Z0( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-1 > > > &>::type
        Z0( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<-1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-1 > > > const &>::type
        Y0( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-1 > > > &>::type
        Y0( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<-1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > const &>::type
        X0( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > const &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > const &>::type
        X0( S const & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > &>::type
        X0( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > &>::type
        X0( S & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<-1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<3 > > > const &>::type
        _1W( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<3 > > > &>::type
        _1W( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<3 > > > const &>::type
        _0W( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<3 > > > &>::type
        _0W( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<3 > > > const &>::type
        WW( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<3 > > > &>::type
        WW( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<3 > > > const &>::type
        ZW( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<3 > > > &>::type
        ZW( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<3 > > > const &>::type
        YW( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<3 > > > &>::type
        YW( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<3 > > > const &>::type
        XW( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<3 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<3 > > > &>::type
        XW( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<3 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<2 > > > const &>::type
        _1Z( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<2 > > > &>::type
        _1Z( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<2 > > > const &>::type
        _0Z( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<2 > > > &>::type
        _0Z( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<2 > > > const &>::type
        WZ( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<2 > > > &>::type
        WZ( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<2 > > > const &>::type
        ZZ( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<2 > > > &>::type
        ZZ( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<2 > > > const &>::type
        YZ( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<2 > > > &>::type
        YZ( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<2 > > > const &>::type
        XZ( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<2 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<2 > > > &>::type
        XZ( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<2 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<1 > > > const &>::type
        _1Y( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<1 > > > &>::type
        _1Y( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<1 > > > const &>::type
        _0Y( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<1 > > > &>::type
        _0Y( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<1 > > > const &>::type
        WY( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<1 > > > &>::type
        WY( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<1 > > > const &>::type
        ZY( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<1 > > > &>::type
        ZY( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<1 > > > const &>::type
        YY( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<1 > > > &>::type
        YY( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<1 > > > const &>::type
        XY( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<1 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<1 > > > &>::type
        XY( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<1 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > const &>::type
        _1X( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > const &>::type
        _1X( S const & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > &>::type
        _1X( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > &>::type
        _1X( S & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<-2,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > const &>::type
        _0X( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > const &>::type
        _0X( S const & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > &>::type
        _0X( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > &>::type
        _0X( S & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<-1,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<0 > > > const &>::type
        WX( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=4,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<0 > > > &>::type
        WX( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<3,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<0 > > > const &>::type
        ZX( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=3,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<0 > > > &>::type
        ZX( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<2,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<0 > > > const &>::type
        YX( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=2,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<0 > > > &>::type
        YX( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<1,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > const &>::type
        XX( V const & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > const &>::type
        XX( S const & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > const &>(a);
            }
        template <class V>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_vec<V>::value && vec_traits<V>::dim>=1,
            qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > &>::type
        XX( V & a )
            {
            return reinterpret_cast<qvm_detail::sw_<V,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        template <class S>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_scalar<S>::value,
            qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > &>::type
        XX( S & a )
            {
            return reinterpret_cast<qvm_detail::sws_<S,qvm_detail::swizzle_idx<0,qvm_detail::swizzle_idx<0 > > > &>(a);
            }
        }
    }

#endif
