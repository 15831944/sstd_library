﻿
//  (C) Copyright Edward Diener 2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/tuple/to_array.hpp>
#include <sstd/boost/vmd/is_empty_array.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/preprocessor/array/elem.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

  #define A_TUPLE (1,2,3,4)
  #define AN_EMPTY_TUPLE

  BOOST_TEST_EQ(BOOST_PP_ARRAY_ELEM(3,BOOST_VMD_TUPLE_TO_ARRAY(A_TUPLE)),4);
  BOOST_TEST(BOOST_VMD_IS_EMPTY_ARRAY(BOOST_VMD_TUPLE_TO_ARRAY(AN_EMPTY_TUPLE)));

#else

BOOST_ERROR("No variadic macro support");

#endif

  return boost::report_errors();

  }

