﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/chain.hpp>
#include <sstd/boost/hana/config.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/flatten.hpp>
#include <sstd/boost/hana/optional.hpp>
namespace hana = boost::hana;


int main() {
    BOOST_HANA_CONSTEXPR_LAMBDA auto inc = [](auto x) {
        return hana::just(x + 1);
    };

    BOOST_HANA_CONSTEXPR_CHECK(hana::chain(hana::just(1), inc) == hana::just(2));
    BOOST_HANA_CONSTANT_CHECK(hana::chain(hana::nothing, inc) == hana::nothing);

    BOOST_HANA_CONSTEXPR_CHECK(hana::flatten(hana::just(hana::just(2))) == hana::just(2));
}

