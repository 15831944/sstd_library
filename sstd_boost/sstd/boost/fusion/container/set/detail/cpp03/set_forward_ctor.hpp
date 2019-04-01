﻿/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PP_IS_ITERATING
#if !defined(FUSION_SET_FORWARD_CTOR_09162005_1115)
#define FUSION_SET_FORWARD_CTOR_09162005_1115

#include <sstd/boost/preprocessor/iterate.hpp>
#include <sstd/boost/preprocessor/repetition/enum_params.hpp>
#include <sstd/boost/preprocessor/repetition/enum_binary_params.hpp>

#define BOOST_PP_FILENAME_1 \
    <sstd/boost/fusion/container/set/detail/cpp03/set_forward_ctor.hpp>
#define BOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_SET_SIZE)
#include BOOST_PP_ITERATE()

#endif
#else // defined(BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N BOOST_PP_ITERATION()

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
#if N == 1
    explicit
#endif
    set(BOOST_PP_ENUM_BINARY_PARAMS(
        N, typename detail::call_param<T, >::type arg))
        : data(BOOST_PP_ENUM_PARAMS(N, arg)) {}

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)


