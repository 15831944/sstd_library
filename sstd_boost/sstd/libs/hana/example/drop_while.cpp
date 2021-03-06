﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/drop_while.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/less.hpp>
#include <sstd/boost/hana/negate.hpp>
#include <sstd/boost/hana/range.hpp>
#include <sstd/boost/hana/tuple.hpp>
namespace hana = boost::hana;
using namespace hana::literals;


auto negative = [](auto x) {
    return x < hana::int_c<0>;
};

BOOST_HANA_CONSTANT_CHECK(
    hana::drop_while(hana::make_range(hana::int_c<-3>, hana::int_c<6>), negative)
        ==
    hana::make_range(hana::int_c<0>, hana::int_c<6>)
);

BOOST_HANA_CONSTANT_CHECK(
    hana::drop_while(hana::make_tuple(1_c, -2_c, 4_c, 5_c), negative)
        ==
    hana::make_tuple(1_c, -2_c, 4_c, 5_c)
);

int main() { }
