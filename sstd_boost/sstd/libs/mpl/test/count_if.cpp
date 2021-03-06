﻿
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sstd/boost/mpl/count_if.hpp>
#include <sstd/boost/mpl/vector.hpp>
#include <sstd/boost/mpl/vector_c.hpp>
#include <sstd/boost/mpl/comparison.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/mpl/aux_/test.hpp>

#include <sstd/boost/type_traits/is_float.hpp>
#include <sstd/boost/type_traits/is_same.hpp>

MPL_TEST_CASE()
{
    typedef vector<int,char&,long,short,char&,long,double,long> types;
    typedef vector_c<int,1,0,5,1,7,5,0,5> values;

    MPL_ASSERT_RELATION( (count_if< types, boost::is_float<_> >::value), ==, 1 );
    MPL_ASSERT_RELATION( (count_if< types, boost::is_same<_,char&> >::value), ==, 2 );
    MPL_ASSERT_RELATION( (count_if< types, boost::is_same<_,void*> >::value), ==, 0 );

    MPL_ASSERT_RELATION( (count_if< values, less<_,int_<5> > >::value), ==, 4 );
    MPL_ASSERT_RELATION( (count_if< values, equal_to<int_<0>,_>  >::value), ==, 2 );
    MPL_ASSERT_RELATION( (count_if< values, equal_to<int_<-1>,_> >::value), ==, 0 );
}
