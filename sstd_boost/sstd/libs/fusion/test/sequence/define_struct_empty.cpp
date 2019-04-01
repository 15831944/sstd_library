﻿/*=============================================================================
    Copyright (c) 2016 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/fusion/container.hpp>
#include <sstd/boost/fusion/sequence.hpp>
#include <sstd/boost/fusion/sequence/io/out.hpp>
#include <sstd/boost/fusion/iterator/equal_to.hpp>
#include <sstd/boost/fusion/adapted/struct/define_struct.hpp>
#include <sstd/boost/mpl/assert.hpp>
#include <sstd/boost/mpl/is_sequence.hpp>
#include <sstd/boost/static_assert.hpp>
#include <iostream>

BOOST_FUSION_DEFINE_STRUCT(BOOST_PP_EMPTY(), empty_struct, )

int
main()
{
    using namespace boost;
    using namespace boost::fusion;

    std::cout << tuple_open('[');
    std::cout << tuple_close(']');
    std::cout << tuple_delimiter(", ");

    {
        BOOST_MPL_ASSERT_NOT((traits::is_view<empty_struct>));
        BOOST_STATIC_ASSERT(!traits::is_view<empty_struct>::value);
        empty_struct e;

        std::cout << e << std::endl;
        BOOST_TEST(e == make_vector());

        BOOST_STATIC_ASSERT(fusion::result_of::size<empty_struct>::value == 0);
        BOOST_STATIC_ASSERT(fusion::result_of::empty<empty_struct>::value);
    }

    {
        vector<> v;
        empty_struct e;
        BOOST_TEST(v == e);
        BOOST_TEST_NOT(v != e);
        BOOST_TEST_NOT(v < e);
        BOOST_TEST(v <= e);
        BOOST_TEST_NOT(v > e);
        BOOST_TEST(v >= e);
    }

    {
        empty_struct e;

        // conversion from empty_struct to vector
        vector<> v(e);
        v = e;

        // conversion from empty_struct to list
        //list<> l(e);
        //l = e;
    }

    { // begin/end
        typedef fusion::result_of::begin<empty_struct>::type b;
        typedef fusion::result_of::end<empty_struct>::type e;

        BOOST_MPL_ASSERT((fusion::result_of::equal_to<b, e>));
    }

    BOOST_MPL_ASSERT((mpl::is_sequence<empty_struct>));

    return boost::report_errors();
}

