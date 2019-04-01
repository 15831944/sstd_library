﻿/*
 * Copyright (C) 2017 James E. King III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_PREDEF_LIBRARY_C_CLOUDABI_H
#define BOOST_PREDEF_LIBRARY_C_CLOUDABI_H

#include <sstd/boost/predef/version_number.h>
#include <sstd/boost/predef/make.h>

#include <sstd/boost/predef/library/c/_prefix.h>

#if defined(__CloudABI__)
#include <stddef.h>
#endif

/*`
[heading `BOOST_LIB_C_CLOUDABI`]

[@https://github.com/NuxiNL/cloudlibc cloudlibc] - CloudABI's standard C library.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__cloudlibc__`] [__predef_detection__]]

    [[`__cloudlibc_major__`, `__cloudlibc_minor__`] [V.R.0]]
    ]
 */

#define BOOST_LIB_C_CLOUDABI BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__cloudlibc__)
#   undef BOOST_LIB_C_CLOUDABI
#   define BOOST_LIB_C_CLOUDABI \
            BOOST_VERSION_NUMBER(__cloudlibc_major__,__cloudlibc_minor__,0)
#endif

#if BOOST_LIB_C_CLOUDABI
#   define BOOST_LIB_C_CLOUDABI_AVAILABLE
#endif

#define BOOST_LIB_C_CLOUDABI_NAME "cloudlibc"

#endif

#include <sstd/boost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_LIB_C_CLOUDABI,BOOST_LIB_C_CLOUDABI_NAME)

