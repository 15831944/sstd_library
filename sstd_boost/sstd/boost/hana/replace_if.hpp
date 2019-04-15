﻿/*!
@file
Defines `boost::hana::replace_if`.

@copyright Louis Dionne 2013-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_REPLACE_IF_HPP
#define BOOST_HANA_REPLACE_IF_HPP

#include <sstd/boost/hana/fwd/replace_if.hpp>

#include <sstd/boost/hana/adjust_if.hpp>
#include <sstd/boost/hana/concept/functor.hpp>
#include <sstd/boost/hana/config.hpp>
#include <sstd/boost/hana/core/dispatch.hpp>
#include <sstd/boost/hana/functional/always.hpp>


BOOST_HANA_NAMESPACE_BEGIN
    //! @cond
    template <typename Xs, typename Pred, typename Value>
    constexpr auto replace_if_t::operator()(Xs&& xs, Pred&& pred, Value&& value) const {
        using S = typename hana::tag_of<Xs>::type;
        using ReplaceIf = BOOST_HANA_DISPATCH_IF(replace_if_impl<S>,
            hana::Functor<S>::value
        );

    #ifndef BOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS
        static_assert(hana::Functor<S>::value,
        "hana::replace_if(xs, pred, value) requires 'xs' to be a Functor");
    #endif

        return ReplaceIf::apply(static_cast<Xs&&>(xs),
                                static_cast<Pred&&>(pred),
                                static_cast<Value&&>(value));
    }
    //! @endcond

    template <typename Fun, bool condition>
    struct replace_if_impl<Fun, when<condition>> : default_ {
        template <typename Xs, typename Pred, typename Value>
        static constexpr auto apply(Xs&& xs, Pred&& pred, Value&& v) {
            return hana::adjust_if(static_cast<Xs&&>(xs),
                static_cast<Pred&&>(pred),
                hana::always(static_cast<Value&&>(v))
            );
        }
    };
BOOST_HANA_NAMESPACE_END

#endif // !BOOST_HANA_REPLACE_IF_HPP
