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
//[adjacent_filtered_example
#include <sstd/boost/range/adaptor/adjacent_filtered.hpp>
#include <sstd/boost/range/algorithm/copy.hpp>
#include <sstd/boost/assign.hpp>
#include <iterator>
#include <functional>
#include <iostream>
#include <vector>

//<-
#include <sstd/boost/range/algorithm_ext/push_back.hpp>

#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>

namespace
{
void adjacent_filtered_example_test()
//->
//=int main(int argc, const char* argv[])
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 1,1,2,2,2,3,4,5,6;

    boost::copy(
        input | adjacent_filtered(std::not_equal_to<int>()),
        std::ostream_iterator<int>(std::cout, ","));

//=    return 0;
//=}
//]
    std::vector<int> reference;
    reference += 1,2,3,4,5,6;

    std::vector<int> test;
    boost::push_back(test, input | adjacent_filtered(std::not_equal_to<int>()));

    BOOST_CHECK_EQUAL_COLLECTIONS( reference.begin(), reference.end(),
        test.begin(), test.end() );
}
}

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.adaptor.adjacent_filtered_example" );

    test->add( BOOST_TEST_CASE( &adjacent_filtered_example_test ) );

    return test;
}
