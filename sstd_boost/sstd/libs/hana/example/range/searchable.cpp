﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/find.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/optional.hpp>
#include <sstd/boost/hana/range.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::find(hana::make_range(hana::int_c<1>, hana::int_c<25>), hana::int_c<10>) == hana::just(hana::int_c<10>));
BOOST_HANA_CONSTANT_CHECK(hana::find(hana::make_range(hana::int_c<1>, hana::int_c<25>), hana::int_c<200>) == hana::nothing);

int main() { }

