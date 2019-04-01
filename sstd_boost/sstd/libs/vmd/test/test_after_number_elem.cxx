﻿
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#include <sstd/boost/vmd/elem.hpp>
#include <sstd/boost/vmd/is_empty.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <sstd/boost/preprocessor/list/at.hpp>
#include <sstd/boost/preprocessor/punctuation/is_begin_parens.hpp>
#include <sstd/boost/preprocessor/seq/elem.hpp>
#include <sstd/boost/preprocessor/tuple/elem.hpp>

int main()
  {

#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)

  #define ANIDENTIFIER ggh
  #define ANUMBER 249
  #define ANUMBER2 25
  #define ANUMBER3 158
  #define ANUMBER5 73
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ANARRAY2 (5,(c,d,133,22,15))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER ANARRAY2 ASEQ ALIST ANUMBER2 ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER3 ANIDENTIFIER ATUPLE
  #define ASEQUENCE4
  #define ASEQUENCE5 ASEQ ANUMBER5 ATUPLE ANIDENTIFIER

  #define A_TUPLE (27,251,145 ())
  #define JDATA 43
  #define A_SEQ (73 (split) clear)(red)(green 44)
  #define A_LIST (17 (5),(grist,(yellow,BOOST_PP_NIL)))

  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ASEQUENCE,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(4,ASEQUENCE2,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(1,ASEQUENCE3,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(1,ASEQUENCE5,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));

  BOOST_TEST(BOOST_PP_IS_BEGIN_PARENS(BOOST_VMD_ELEM(0,BOOST_PP_TUPLE_ELEM(2,A_TUPLE),BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,JDATA,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(BOOST_PP_IS_BEGIN_PARENS(BOOST_VMD_ELEM(0,BOOST_PP_SEQ_ELEM(0,A_SEQ),BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,BOOST_PP_LIST_AT(A_LIST,0),BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)),5);
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,BOOST_PP_LIST_AT(A_LIST,1),BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,BOOST_PP_SEQ_ELEM(2,A_SEQ),BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));

  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,253 num,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,17 181 201 somevalue num,BOOST_VMD_RETURN_ONLY_AFTER,BOOST_VMD_TYPE_NUMBER)));

#else

BOOST_ERROR("No variadic macro support");

#endif

  return boost::report_errors();

  }

