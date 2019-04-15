﻿//  This file was automatically generated on Fri Dec 03 18:04:00 2004
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.

// Test file for macro BOOST_HAS_LONG_LONG
// This file should not compile, if it does then
// BOOST_HAS_LONG_LONG should be defined.
// See file boost_has_long_long.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <sstd/boost/config.hpp>
#include "test.hpp"

#ifndef BOOST_HAS_LONG_LONG
#include "boost_has_long_long.ipp"
#else
#error "this file should not compile"
#endif

int main( int, char *[] )
{
   return boost_has_long_long::test();
}
