﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/experimental/view.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/length.hpp>
namespace hana = boost::hana;


int main() {
    {
        auto empty = hana::experimental::empty_view();
        BOOST_HANA_CONSTANT_CHECK(hana::equal(
            hana::length(empty),
            hana::size_c<0>
        ));
    }
}
