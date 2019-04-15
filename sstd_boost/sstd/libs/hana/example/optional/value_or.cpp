﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/optional.hpp>
namespace hana = boost::hana;


static_assert(hana::just(1).value_or('x') == 1, "");
static_assert(hana::nothing.value_or('x') == 'x', "");

int main() { }
