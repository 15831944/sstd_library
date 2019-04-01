﻿// Copyright (C) 2015 Andrzej Krzemienski.
//
// Use, modification, and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/lib/optional for documentation.
//
// You are welcome to contact the author at: akrzemi1@gmail.com


#include "sstd/boost/optional/optional.hpp"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#include "sstd/boost/core/addressof.hpp"
#include "sstd/boost/core/enable_if.hpp"
#include "sstd/boost/core/lightweight_test.hpp"
#include "testable_classes.hpp"
#include "optional_ref_assign_test_defs.hpp"

int main()
{
#ifdef BOOST_OPTIONAL_CONFIG_NO_PROPER_ASSIGN_FROM_CONST_INT
  test_converting_assignment<const int, const int>();
#else
  BOOST_STATIC_ASSERT_MSG(false, "EXPECTED TEST COMPILE-TIME FAILURE");
#endif
  return boost::report_errors();
}

