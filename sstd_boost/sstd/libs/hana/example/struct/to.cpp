﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/core/to.hpp>
#include <sstd/boost/hana/define_struct.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/map.hpp>
#include <sstd/boost/hana/pair.hpp>
#include <sstd/boost/hana/string.hpp>

#include <string>
namespace hana = boost::hana;


struct Person {
    BOOST_HANA_DEFINE_STRUCT(Person,
        (std::string, name),
        (unsigned short, age)
    );
};

int main() {
    Person john{"John", 30u};
    BOOST_HANA_RUNTIME_CHECK(hana::to<hana::map_tag>(john) == hana::make_map(
        hana::make_pair(BOOST_HANA_STRING("name"), "John"),
        hana::make_pair(BOOST_HANA_STRING("age"), 30u)
    ));
}
