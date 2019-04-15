﻿//  Copyright John Maddock 2005.
//  Copyright Paul A. Bristow 2010
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <pch_light.hpp>

// Requires MS extensions permitted or fails to link.


#define BOOST_MATH_OVERFLOW_ERROR_POLICY ignore_error

#include <sstd/boost/math/concepts/real_concept.hpp>
#define BOOST_TEST_MAIN
#include <sstd/boost/test/unit_test.hpp>
#include <sstd/boost/test/floating_point_comparison.hpp>
#include <sstd/boost/math/special_functions/math_fwd.hpp>
#include "log1p_expm1_test.hpp"

//
// DESCRIPTION:
// ~~~~~~~~~~~~
//
// This file tests the functions log1p and expm1.  The accuracy tests
// use values generated with NTL::RR at 1000-bit precision
// and our generic versions of these functions.
//
// Note that when this file is first run on a new platform many of
// these tests will fail: the default accuracy is 1 epsilon which
// is too tight for most platforms.  In this situation you will
// need to cast a human eye over the error rates reported and make
// a judgement as to whether they are acceptable.  Either way please
// report the results to the Boost mailing list.  Acceptable rates of
// error are marked up below as a series of regular expressions that
// identify the compiler/stdlib/platform/data-type/test-data/test-function
// along with the maximum expected peek and RMS mean errors for that
// test.
//

void expected_results()
{
   //
   // Define the max and mean errors expected for
   // various compilers and platforms.
   //

   //
   // Catch all cases come last:
   //
   add_expected_result(
      ".*",                          // compiler
      ".*",                          // stdlib
      ".*",                          // platform
      ".*",                          // test type(s)
      ".*",                          // test data group
      ".*",                          // test function
      4,                             // Max Peek error
      3);                            // Max mean error

   //
   // Finish off by printing out the compiler/stdlib/platform names,
   // we do this to make it easier to mark up expected error rates.
   //
   std::cout << "Tests run with " << BOOST_COMPILER << ", "
      << BOOST_STDLIB << ", " << BOOST_PLATFORM << std::endl;
}


BOOST_AUTO_TEST_CASE( test_main )
{
   expected_results();
   BOOST_MATH_CONTROL_FP;
   test(float(0), "float");
   test(double(0), "double");
   //
   // The long double version of these tests fails on some platforms
   // due to poor std lib support (not enough digits returned from
   // std::log and std::exp):
   //
#if !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
   test((long double)(0), "long double");
#ifndef BOOST_MATH_NO_REAL_CONCEPT_TESTS
   test((boost::math::concepts::real_concept)(0), "real_concept");
#endif
#else
   std::cout << "<note>The long double tests have been disabled on this platform "
      "either because the long double overloads of the usual math functions are "
      "not available at all, or because they are too inaccurate for these tests "
      "to pass.</note>" << std::endl;
#endif
}
