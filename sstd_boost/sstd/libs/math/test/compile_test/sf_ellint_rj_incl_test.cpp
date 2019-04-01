﻿//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Basic sanity check that header <sstd/boost/math/special_functions/ellint_rj.hpp>
// #includes all the files that it needs to.
//
#include <sstd/boost/math/special_functions/ellint_rj.hpp>
//
// Note this header includes no other headers, this is
// important if this test is to be meaningful:
//
#include "test_compile_result.hpp"

void compile_and_link_test()
{
   check_result<float>(boost::math::ellint_rj<float>(f, f, f, f));
   check_result<double>(boost::math::ellint_rj<double>(d, d, d, d));
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
   check_result<long double>(boost::math::ellint_rj<long double>(l, l, l, l));
#endif
}

