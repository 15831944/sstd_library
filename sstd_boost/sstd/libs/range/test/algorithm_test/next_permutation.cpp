﻿//  Copyright Neil Groves 2009. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <sstd/boost/assign.hpp>
#include <sstd/boost/range/algorithm/permutation.hpp>
#include <sstd/boost/test/test_tools.hpp>
#include <sstd/boost/test/unit_test.hpp>
#include <algorithm>
#include <deque>
#include <functional>
#include <list>
#include <vector>

namespace boost
{
    namespace
    {
        template<class Container>
        void test_next_permutation_impl(const Container& cont)
        {
            Container reference(cont);
            Container test(cont);

            const bool reference_ret
                = std::next_permutation(reference.begin(), reference.end());

            const bool test_ret = boost::next_permutation(test);

            BOOST_CHECK( reference_ret == test_ret );

            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                test.begin(), test.end()
                );

            test = cont;

            BOOST_CHECK( test_ret == boost::next_permutation(boost::make_iterator_range(test)) );

            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                test.begin(), test.end()
                );
        }

        template<class Container, class BinaryPredicate>
        void test_next_permutation_pred_impl(const Container& cont,
                                             BinaryPredicate  pred)
        {
            Container reference(cont);
            Container test(cont);

            const bool reference_ret
                = std::next_permutation(reference.begin(), reference.end(),
                                        pred);

            const bool test_ret
                = boost::next_permutation(test, pred);

            BOOST_CHECK( reference_ret == test_ret );

            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                test.begin(), test.end()
                );

            test = cont;

            BOOST_CHECK( test_ret == boost::next_permutation(boost::make_iterator_range(test), pred) );

            BOOST_CHECK_EQUAL_COLLECTIONS(
                reference.begin(), reference.end(),
                test.begin(), test.end()
                );
        }

        template<class Container>
        void test_next_permutation_(const Container& cont)
        {
            test_next_permutation_impl(cont);
            test_next_permutation_pred_impl(cont, std::less<int>());
            test_next_permutation_pred_impl(cont, std::greater<int>());
        }

        template<class Container>
        void run_tests()
        {
            using namespace boost::assign;

            Container cont;
            test_next_permutation_(cont);

            cont.clear();
            cont += 1;
            test_next_permutation_(cont);

            cont.clear();
            cont += 1,2,3,4,5,6,7,8,9;
            test_next_permutation_(cont);
        }

        void test_next_permutation()
        {
            run_tests< std::vector<int> >();
            run_tests< std::list<int> >();
            run_tests< std::deque<int> >();
        }
    }
}

boost::unit_test::test_suite*
init_unit_test_suite(int argc, char* argv[])
{
    boost::unit_test::test_suite* test
        = BOOST_TEST_SUITE( "RangeTestSuite.algorithm.next_permutation" );

    test->add( BOOST_TEST_CASE( &boost::test_next_permutation ) );

    return test;
}

