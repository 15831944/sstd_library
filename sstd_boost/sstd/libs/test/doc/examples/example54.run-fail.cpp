﻿//  (C) Copyright Gennadiy Rozental 2011-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

//[example_code
#define BOOST_TEST_MODULE example
#include <sstd/boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test )
{
  int i = 3;
  int j = 3;
  BOOST_CHECK_NE( i, j );
}
//]
