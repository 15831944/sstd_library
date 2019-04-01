﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/contains.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/map.hpp>
#include <sstd/boost/hana/permutations.hpp>

#include <laws/base.hpp>
#include <support/minimal_product.hpp>
#include <support/seq.hpp>
namespace hana = boost::hana;


template <int i>
auto key() { return hana::test::ct_eq<i>{}; }

template <int i>
auto val() { return hana::test::ct_eq<-i>{}; }

template <int i, int j>
auto p() { return ::minimal_product(key<i>(), val<j>()); }

int main() {
    constexpr auto list = ::seq;

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::values(hana::make_map()),
        list()
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::equal(
        hana::values(hana::make_map(p<1, 1>())),
        list(val<1>())
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(
        hana::permutations(list(val<1>(), val<2>())),
        hana::values(hana::make_map(p<1, 1>(), p<2, 2>()))
    ));

    BOOST_HANA_CONSTANT_CHECK(hana::contains(
        hana::permutations(list(val<1>(), val<2>(), val<3>())),
        hana::values(hana::make_map(p<1, 1>(), p<2, 2>(), p<3, 3>()))
    ));
}

