﻿
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/elem.hpp>
#include <sstd/boost/vmd/equal.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

 #define BOOST_VMD_REGISTER_ANAME (ANAME)
 #define BOOST_VMD_REGISTER_APLACE (APLACE)
 #define BOOST_VMD_REGISTER_ACOUNTRY (ACOUNTRY)

 #define BOOST_VMD_DETECT_ANAME_ANAME
 #define BOOST_VMD_DETECT_APLACE_APLACE

 #define A_SEQUENCE (1,2,3) ANAME (1)(2) 46

 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER),ANAME));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,APLACE,ACOUNTRY),));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,APLACE,ACOUNTRY),(,)));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,ANAME,APLACE,ACOUNTRY),(ANAME,0)));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,(APLACE,ACOUNTRY,ANAME)),(ANAME,2)));

 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,APLACE,ACOUNTRY,BOOST_VMD_RETURN_AFTER),(,,)));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,ANAME,APLACE,ACOUNTRY,BOOST_VMD_RETURN_AFTER),(ANAME,(1)(2) 46,0)));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,(APLACE,ACOUNTRY,ANAME),BOOST_VMD_RETURN_AFTER),(ANAME,(1)(2) 46,2)));
 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(1,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,(APLACE,ACOUNTRY,ANAME),BOOST_VMD_RETURN_ONLY_AFTER),(1)(2) 46));

 BOOST_TEST(BOOST_VMD_EQUAL(BOOST_VMD_ELEM(3,A_SEQUENCE,BOOST_VMD_TYPE_IDENTIFIER,BOOST_VMD_RETURN_INDEX,0,3,46,7),(46,2)));

#else

BOOST_ERROR("No variadic macro support");

#endif

  return boost::report_errors();

  }

