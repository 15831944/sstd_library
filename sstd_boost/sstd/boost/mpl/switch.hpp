﻿
#ifndef BOOST_MPL_SWITCH_HPP_INCLUDED
#define BOOST_MPL_SWITCH_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sstd/boost/mpl/find_if.hpp>
#include <sstd/boost/mpl/deref.hpp>
#include <sstd/boost/mpl/lambda.hpp>
#include <sstd/boost/mpl/apply.hpp>
#include <sstd/boost/mpl/pair.hpp>
#include <sstd/boost/mpl/aux_/na_spec.hpp>
#include <sstd/boost/mpl/aux_/lambda_support.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Body)
    , typename BOOST_MPL_AUX_NA_PARAM(T)
    >
struct switch_
{
    typedef typename find_if<
          Body
        , apply1< lambda< first<_1> >, T >
        >::type iter_;

    typedef typename deref<iter_>::type pair_;
    typedef typename lambda< typename second<pair_>::type >::type f_;
    typedef typename apply1<f_,T>::type type;

    BOOST_MPL_AUX_LAMBDA_SUPPORT(2,switch_,(Body,T))
};

BOOST_MPL_AUX_NA_SPEC(2, switch_)

}}

#endif // BOOST_MPL_SWITCH_HPP_INCLUDED

