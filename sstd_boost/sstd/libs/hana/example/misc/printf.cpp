﻿// Copyright Louis Dionne 2013-2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <sstd/boost/hana/adjust_if.hpp>
#include <sstd/boost/hana/at_key.hpp>
#include <sstd/boost/hana/core/is_a.hpp>
#include <sstd/boost/hana/core/to.hpp>
#include <sstd/boost/hana/filter.hpp>
#include <sstd/boost/hana/functional/compose.hpp>
#include <sstd/boost/hana/functional/partial.hpp>
#include <sstd/boost/hana/map.hpp>
#include <sstd/boost/hana/not.hpp>
#include <sstd/boost/hana/pair.hpp>
#include <sstd/boost/hana/prepend.hpp>
#include <sstd/boost/hana/string.hpp>
#include <sstd/boost/hana/sum.hpp>
#include <sstd/boost/hana/tuple.hpp>
#include <sstd/boost/hana/type.hpp>
#include <sstd/boost/hana/unpack.hpp>

#include <cstdio>
namespace hana = boost::hana;


constexpr auto formats = hana::make_map(
    hana::make_pair(hana::type_c<int>, hana::string_c<'%', 'd'>),
    hana::make_pair(hana::type_c<float>, hana::string_c<'%', 'f'>),
    hana::make_pair(hana::type_c<char const*>, hana::string_c<'%', 's'>)
);

template <typename ...Tokens>
constexpr auto format(Tokens ...tokens_) {
    auto tokens = hana::make_tuple(tokens_...);

    // If you don't care about constexpr-ness of `format`, you can use
    // this lambda instead of `compose(partial(...), typeid_)`:
    //
    // [](auto token) {
    //     return formats[typeid_(token)];
    // }
    auto format_string_tokens = hana::adjust_if(tokens,
        hana::compose(hana::not_, hana::is_a<hana::string_tag>),
        hana::compose(hana::partial(hana::at_key, formats), hana::typeid_)
    );

    auto format_string = hana::sum<hana::string_tag>(format_string_tokens);
    auto variables = hana::filter(tokens, hana::compose(hana::not_, hana::is_a<hana::string_tag>));
    return hana::prepend(variables, format_string);
}

int main() {
    int a = 1;
    float b = 1.3;
    char const* c = "abcdef";

    auto args = format(
          BOOST_HANA_STRING("first="), a
        , BOOST_HANA_STRING(" second="), b
        , BOOST_HANA_STRING(" third="), c
    );

    hana::unpack(args, [](auto fmt, auto ...args) {
        std::printf(hana::to<char const*>(fmt), args...);
    });
}
