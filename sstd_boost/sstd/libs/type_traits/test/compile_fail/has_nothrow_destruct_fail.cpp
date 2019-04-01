﻿
//  (C) Copyright John Maddock 2017.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#  include <sstd/boost/type_traits/has_nothrow_destructor.hpp>
#include "../test.hpp"

int main()
{
   return boost::has_nothrow_destructor<incomplete_type>::value;
}



