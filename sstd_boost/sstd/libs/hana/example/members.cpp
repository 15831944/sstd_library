﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/define_struct.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/members.hpp>
#include <sstd/boost/hana/tuple.hpp>

#include <string>
namespace hana = boost::hana;


struct Person {
    BOOST_HANA_DEFINE_STRUCT(Person,
        (std::string, name),
        (unsigned short, age)
    );
};

int main() {
    Person john{"John", 30};
    BOOST_HANA_RUNTIME_CHECK(hana::members(john) == hana::make_tuple("John", 30));
}

