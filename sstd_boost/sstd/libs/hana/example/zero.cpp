﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/zero.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::zero<hana::integral_constant_tag<int>>() == hana::int_c<0>);
static_assert(hana::zero<long>() == 0l, "");

int main() { }

