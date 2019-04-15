﻿// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id$

#include <sstd/boost/type_erasure/any.hpp>
#include <sstd/boost/type_erasure/builtin.hpp>
#include <sstd/boost/type_erasure/any_cast.hpp>
#include <sstd/boost/mpl/vector.hpp>

using namespace boost::type_erasure;

int main()
{
    int i = 2;
    any< ::boost::mpl::vector<copy_constructible<>, typeid_<> >, const _self&> y(i);
    int j = *any_cast<int*>(&y);
}
