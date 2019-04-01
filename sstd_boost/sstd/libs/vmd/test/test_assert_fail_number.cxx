﻿
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/assert.hpp>
#include <sstd/boost/vmd/elem.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/preprocessor/comparison/equal.hpp>
#include <sstd/boost/preprocessor/seq/elem.hpp>
#include <sstd/boost/preprocessor/tuple/elem.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

  #define A_SEQ (73 (split) clear)(red)(green 44)

  BOOST_VMD_ASSERT(BOOST_PP_EQUAL(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,BOOST_PP_SEQ_ELEM(0,A_SEQ),BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_NUMBER)),72),BOOST_VMD_TEST_FAIL_NUMBER)

#endif

  return boost::report_errors();

  }

