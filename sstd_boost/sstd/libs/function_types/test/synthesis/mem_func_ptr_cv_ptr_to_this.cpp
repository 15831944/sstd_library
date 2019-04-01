﻿
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#include <sstd/boost/mpl/assert.hpp>
#include <sstd/boost/mpl/vector.hpp>
#include <sstd/boost/type_traits/is_same.hpp>
#include <sstd/boost/function_types/member_function_pointer.hpp>

namespace ft = boost::function_types;
namespace mpl = boost::mpl;
using boost::is_same;

class C;
typedef int (C::* expected)();

BOOST_MPL_ASSERT((
  is_same< ft::member_function_pointer< mpl::vector<int,C * const> >::type
         ,  expected >
));

BOOST_MPL_ASSERT((
  is_same< ft::member_function_pointer< mpl::vector<int,C * volatile> >::type
         ,  expected >
));

BOOST_MPL_ASSERT((
  is_same< ft::member_function_pointer< mpl::vector<int,C * const volatile> >::type
         ,  expected >
));




