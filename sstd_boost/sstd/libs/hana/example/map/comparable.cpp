﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/map.hpp>
#include <sstd/boost/hana/pair.hpp>
#include <sstd/boost/hana/type.hpp>

#include <string>
namespace hana = boost::hana;
using namespace std::literals;


int main() {
    BOOST_HANA_RUNTIME_CHECK(
        hana::make_map(
            hana::make_pair(hana::char_c<'a'>, "foobar"s),
            hana::make_pair(hana::type_c<int&&>, nullptr)
        )
        ==
        hana::make_map(
            hana::make_pair(hana::type_c<int&&>, (void*)0),
            hana::make_pair(hana::char_c<'a'>, "foobar"s)
        )
    );
}
