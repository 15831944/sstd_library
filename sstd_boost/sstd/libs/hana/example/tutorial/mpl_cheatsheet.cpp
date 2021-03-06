﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/assert.hpp>
#include <sstd/boost/hana/config.hpp>
#include <sstd/boost/hana/equal.hpp>
#include <sstd/boost/hana/ext/boost/mpl/vector.hpp>
#include <sstd/boost/hana/ext/std/integral_constant.hpp>
#include <sstd/boost/hana/integral_constant.hpp>
#include <sstd/boost/hana/plus.hpp>
#include <sstd/boost/hana/tuple.hpp>

#include <sstd/boost/mpl/fold.hpp>
#include <sstd/boost/mpl/if.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/mpl/next.hpp>
#include <sstd/boost/mpl/placeholders.hpp>
#include <sstd/boost/mpl/vector.hpp>

#include <type_traits>
namespace hana = boost::hana;
namespace mpl = boost::mpl;


namespace with_mpl {
//! [mpl]
using types = mpl::vector<long, float, short, float, long, long double>;
using number_of_floats = mpl::fold<
    types,
    mpl::int_<0>,
    mpl::if_<std::is_floating_point<mpl::_2>,
        mpl::next<mpl::_1>,
        mpl::_1
    >
>::type;
static_assert(number_of_floats::value == 3, "");
//! [mpl]
}

namespace with_hana {
//! [hana]
constexpr auto types = hana::tuple_t<long, float, short, float, long, long double>;
BOOST_HANA_CONSTEXPR_LAMBDA auto number_of_floats = hana::fold_left(
    types,
    hana::int_c<0>,
    [](auto count, auto t) {
        return hana::if_(hana::trait<std::is_floating_point>(t),
            count + hana::int_c<1>,
            count
        );
    }
);
BOOST_HANA_CONSTANT_CHECK(number_of_floats == hana::int_c<3>);
//! [hana]
}

int main() { }
