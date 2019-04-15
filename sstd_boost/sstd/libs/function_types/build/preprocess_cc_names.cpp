﻿
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef __WAVE__
#   error "Boost.Wave preprocessor required"
#endif

#pragma wave option(line: 0, preserve: 2)
timestamp file
#pragma wave option(output: null)

#define BOOST_FT_PREPROCESSING_MODE


#define BOOST_FT_OUT_FILE \
      "../../../boost/function_types/detail/pp_cc_loop/preprocessed.hpp"
#pragma message(generating BOOST_FT_OUT_FILE)
#pragma wave option(output: BOOST_FT_OUT_FILE, preserve: 2)
#include <sstd/boost/function_types/detail/pp_cc_loop/master.hpp>
#pragma wave option(output: null)
#undef  BOOST_FT_OUT_FILE
