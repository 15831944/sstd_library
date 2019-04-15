﻿/*!
@file
Defines `boost::hana::Applicative`.

@copyright Louis Dionne 2013-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONCEPT_APPLICATIVE_HPP
#define BOOST_HANA_CONCEPT_APPLICATIVE_HPP

#include <sstd/boost/hana/fwd/concept/applicative.hpp>

#include <sstd/boost/hana/ap.hpp>
#include <sstd/boost/hana/config.hpp>
#include <sstd/boost/hana/core/default.hpp>
#include <sstd/boost/hana/core/tag_of.hpp>
#include <sstd/boost/hana/detail/integral_constant.hpp>
#include <sstd/boost/hana/lift.hpp>


BOOST_HANA_NAMESPACE_BEGIN
    template <typename A>
    struct Applicative
        : hana::integral_constant<bool,
            !is_default<ap_impl<typename tag_of<A>::type>>::value &&
            !is_default<lift_impl<typename tag_of<A>::type>>::value
        >
    { };
BOOST_HANA_NAMESPACE_END

#endif // !BOOST_HANA_CONCEPT_APPLICATIVE_HPP
