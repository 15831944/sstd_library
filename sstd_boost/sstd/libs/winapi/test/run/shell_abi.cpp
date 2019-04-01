﻿/*
 *             Copyright Andrey Semashev 2018.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   shell_abi.cpp
 * \author Andrey Semashev
 * \date   10.03.2018
 *
 * \brief  This file contains ABI test for shell.hpp
 */

#include <sstd/boost/winapi/shell.hpp>
#include <windows.h>
#include <shellapi.h>
#include "abi_test_tools.hpp"

int main()
{
#if BOOST_WINAPI_PARTITION_DESKTOP

    BOOST_WINAPI_TEST_TYPE_SAME(HICON);

    BOOST_WINAPI_TEST_CONSTANT(SHGFI_ICON);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_DISPLAYNAME);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_TYPENAME);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_ATTRIBUTES);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_ICONLOCATION);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_EXETYPE);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_SYSICONINDEX);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_LINKOVERLAY);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_SELECTED);
#if (BOOST_USE_WINAPI_VERSION >= BOOST_WINAPI_VERSION_WIN2K)
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_ATTR_SPECIFIED);
#endif
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_LARGEICON);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_SMALLICON);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_OPENICON);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_SHELLICONSIZE);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_PIDL);
    BOOST_WINAPI_TEST_CONSTANT(SHGFI_USEFILEATTRIBUTES);

    BOOST_WINAPI_TEST_STRUCT(SHFILEINFOA, (hIcon)(iIcon)(dwAttributes)(szDisplayName)(szTypeName));
    BOOST_WINAPI_TEST_STRUCT(SHFILEINFOW, (hIcon)(iIcon)(dwAttributes)(szDisplayName)(szTypeName));

#endif // BOOST_WINAPI_PARTITION_DESKTOP

    return boost::report_errors();
}

