﻿
// Copyright Bruno Dutra 2015
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#define BOOST_MPL_LIMIT_METAFUNCTION_ARITY 15
#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#include <sstd/boost/mpl/logical.hpp>
#include <sstd/boost/mpl/placeholders.hpp>
#include <sstd/boost/mpl/apply.hpp>

#include <sstd/boost/mpl/aux_/test.hpp>

#include <sstd/boost/preprocessor/inc.hpp>
#include <sstd/boost/preprocessor/repeat_from_to.hpp>
#include <sstd/boost/preprocessor/enum_params.hpp>
#include <sstd/boost/preprocessor/facilities/intercept.hpp>

#define TEST_N_ARY(unused1, N, unused2) \
    static_assert_< \
        apply< \
            and_<BOOST_PP_ENUM_PARAMS(N, _ BOOST_PP_INTERCEPT)>, \
            BOOST_PP_ENUM_PARAMS(N, true_ BOOST_PP_INTERCEPT) \
        > \
    >(); \
/**/

template<typename assertion>
void static_assert_(){
    MPL_ASSERT((typename assertion::type));
}

MPL_TEST_CASE()
{
    BOOST_PP_REPEAT_FROM_TO(
        2,
        BOOST_PP_INC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
        TEST_N_ARY,
        _
    )
}
