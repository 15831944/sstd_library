﻿// Boost.Range library
//
//  Copyright Neil Groves 2014. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#include <sstd/boost/range/difference_type.hpp>
#include <sstd/boost/static_assert.hpp>
#include <sstd/boost/type_traits/is_same.hpp>

#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>

#include <vector>

namespace boost_range_test
{
    namespace
    {

void test_difference()
{
    typedef std::vector<int> cont;

    BOOST_STATIC_ASSERT((
        boost::is_same<
            cont::difference_type,
            boost::range_difference<cont>::type
        >::value));

    BOOST_STATIC_ASSERT((
        boost::is_same<
            cont::difference_type,
            boost::range_difference<const cont>::type
        >::value));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
    BOOST_STATIC_ASSERT((
        boost::is_same<
            cont::difference_type,
            boost::range_difference<cont&&>::type
        >::value));
#endif
}

    } // anonymous namespace
} // namespace boost_range_test

boost::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    boost::unit_test::test_suite* test =
        BOOST_TEST_SUITE("Boost.Range range_difference meta-function");

    test->add(BOOST_TEST_CASE(&boost_range_test::test_difference));

    return test;
}
