﻿//  (C) Copyright Gennadiy Rozental 2011-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

//[example_code
#define BOOST_TEST_MODULE example
#include <sstd/boost/test/included/unit_test.hpp>

boost::test_tools::predicate_result
  compare_lists( std::list<int> const& l1, std::list<int> const& l2 )
{
  if( l1.size() != l2.size() )
  {
    boost::test_tools::predicate_result res( false );

    res.message() << "Different sizes [" << l1.size() << "!=" << l2.size() << "]";

    return res;
  }
  return true;
}

BOOST_AUTO_TEST_CASE( test_list_comparison )
{
  std::list<int> l1, l2;
  l1.push_back( 1 );
  l1.push_back( 2 );

  BOOST_TEST( compare_lists( l1, l2 ) );
}
//]
