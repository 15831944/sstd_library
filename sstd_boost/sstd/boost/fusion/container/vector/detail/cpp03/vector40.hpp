﻿/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VECTOR40_05052005_0208)
#define FUSION_VECTOR40_05052005_0208

#include <sstd/boost/fusion/support/config.hpp>
#include <sstd/boost/fusion/container/vector/detail/cpp03/vector40_fwd.hpp>
#include <sstd/boost/fusion/support/sequence_base.hpp>
#include <sstd/boost/fusion/support/is_sequence.hpp>
#include <sstd/boost/fusion/support/detail/access.hpp>
#include <sstd/boost/fusion/iterator/next.hpp>
#include <sstd/boost/fusion/iterator/deref.hpp>
#include <sstd/boost/fusion/sequence/intrinsic/begin.hpp>
#include <sstd/boost/fusion/container/vector/detail/at_impl.hpp>
#include <sstd/boost/fusion/container/vector/detail/value_at_impl.hpp>
#include <sstd/boost/fusion/container/vector/detail/begin_impl.hpp>
#include <sstd/boost/fusion/container/vector/detail/end_impl.hpp>

#include <sstd/boost/mpl/void.hpp>
#include <sstd/boost/mpl/int.hpp>
#include <sstd/boost/mpl/at.hpp>
#include <sstd/boost/mpl/bool.hpp>
#include <sstd/boost/mpl/vector/vector40.hpp>
#include <sstd/boost/type_traits/is_convertible.hpp>
#include <sstd/boost/utility/enable_if.hpp>

#include <sstd/boost/preprocessor/dec.hpp>
#include <sstd/boost/preprocessor/iteration/iterate.hpp>
#include <sstd/boost/preprocessor/repetition/enum.hpp>
#include <sstd/boost/preprocessor/repetition/enum_shifted.hpp>
#include <sstd/boost/preprocessor/repetition/enum_params.hpp>
#include <sstd/boost/preprocessor/repetition/enum_binary_params.hpp>
#include <sstd/boost/preprocessor/repetition/repeat_from_to.hpp>

#if !defined(BOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <sstd/boost/fusion/container/vector/detail/cpp03/preprocessed/vector40.hpp>
#else
#if defined(__WAVE__) && defined(BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vector40.hpp")
#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace boost { namespace fusion
{
    struct vector_tag;
    struct fusion_sequence_tag;
    struct random_access_traversal_tag;

#define FUSION_HASH #
// expand vector31 to vector40
#define BOOST_PP_FILENAME_1 <sstd/boost/fusion/container/vector/detail/cpp03/vector_n.hpp>
#define BOOST_PP_ITERATION_LIMITS (31, 40)
#include BOOST_PP_ITERATE()
#undef FUSION_HASH
}}

#if defined(__WAVE__) && defined(BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif
