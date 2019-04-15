﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/experimental/view.hpp>
#include <sstd/boost/hana/unpack.hpp>

#include <laws/base.hpp>
namespace hana = boost::hana;


int main() {
    auto f = hana::test::_injection<0>{};

    {
        auto empty = hana::experimental::empty_view();
        BOOST_HANA_CONSTANT_CHECK(hana::equal(
            hana::unpack(empty, f),
            f()
        ));
    }
}
