﻿// Boost.Range library
//
//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <sstd/boost/range/algorithm/copy_n.hpp>

#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>

#include <sstd/boost/assign.hpp>
#include <sstd/boost/range/iterator.hpp>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

namespace
{
    template< class Container >
    void test_copy_n_impl()
    {
        Container source;
        typedef BOOST_DEDUCED_TYPENAME Container::value_type value_t;

        std::vector<value_t> target;
        target.resize(source.size());

        typedef BOOST_DEDUCED_TYPENAME range_iterator< std::vector<value_t> >::type iterator_t;
        iterator_t it = boost::copy(source, target.begin());

        BOOST_CHECK( it == target.end() );

        BOOST_CHECK_EQUAL_COLLECTIONS(
            target.begin(), target.end(),
            source.begin(), source.end()
            );

        it = boost::copy(boost::make_iterator_range(source), target.begin());

        BOOST_CHECK( it == target.end() );

        BOOST_CHECK_EQUAL_COLLECTIONS(target.begin(), target.end(),
                                      source.begin(), source.end());
    }

    void test_copy_n()
    {
        test_copy_n_impl< std::vector<int> >();
        test_copy_n_impl< std::list<int> >();
        test_copy_n_impl< std::set<int> >();
        test_copy_n_impl< std::multiset<int> >();
    }
}

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.copy_n" );

    test->add( BOOST_TEST_CASE( &::test_copy_n ) );

    return test;
}
