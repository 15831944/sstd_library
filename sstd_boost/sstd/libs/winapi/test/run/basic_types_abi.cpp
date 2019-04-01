﻿/*
 *             Copyright Andrey Semashev 2018.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   basic_types_abi.cpp
 * \author Andrey Semashev
 * \date   09.03.2018
 *
 * \brief  This file contains ABI test for basic WinAPI types
 */

#include <sstd/boost/winapi/basic_types.hpp>
#include <windows.h>
#include <sstd/boost/predef/platform/windows_uwp.h>
#include "abi_test_tools.hpp"

int main()
{
    BOOST_WINAPI_TEST_TYPE_SAME(BOOL);
    BOOST_WINAPI_TEST_TYPE_SAME(PBOOL);
    BOOST_WINAPI_TEST_TYPE_SAME(LPBOOL);
    BOOST_WINAPI_TEST_TYPE_SAME(BOOLEAN);
    BOOST_WINAPI_TEST_TYPE_SAME(PBOOLEAN);
    BOOST_WINAPI_TEST_TYPE_SAME(BYTE);
    BOOST_WINAPI_TEST_TYPE_SAME(PBYTE);
    BOOST_WINAPI_TEST_TYPE_SAME(LPBYTE);
    BOOST_WINAPI_TEST_TYPE_SAME(UCHAR);
    BOOST_WINAPI_TEST_TYPE_SAME(PUCHAR);
    BOOST_WINAPI_TEST_TYPE_SAME(WORD);
    BOOST_WINAPI_TEST_TYPE_SAME(PWORD);
    BOOST_WINAPI_TEST_TYPE_SAME(LPWORD);
    BOOST_WINAPI_TEST_TYPE_SAME(DWORD);
    BOOST_WINAPI_TEST_TYPE_SAME(PDWORD);
    BOOST_WINAPI_TEST_TYPE_SAME(LPDWORD);
    BOOST_WINAPI_TEST_TYPE_SAME(HANDLE);
    BOOST_WINAPI_TEST_TYPE_SAME(PHANDLE);
    BOOST_WINAPI_TEST_TYPE_SAME(SHORT);
    BOOST_WINAPI_TEST_TYPE_SAME(PSHORT);
    BOOST_WINAPI_TEST_TYPE_SAME(USHORT);
    BOOST_WINAPI_TEST_TYPE_SAME(PUSHORT);
    BOOST_WINAPI_TEST_TYPE_SAME(INT);
    BOOST_WINAPI_TEST_TYPE_SAME(PINT);
    BOOST_WINAPI_TEST_TYPE_SAME(LPINT);
    BOOST_WINAPI_TEST_TYPE_SAME(UINT);
    BOOST_WINAPI_TEST_TYPE_SAME(PUINT);
    BOOST_WINAPI_TEST_TYPE_SAME(LONG);
    BOOST_WINAPI_TEST_TYPE_SAME(PLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(LPLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(ULONG);
    BOOST_WINAPI_TEST_TYPE_SAME(PULONG);
    BOOST_WINAPI_TEST_TYPE_SAME(LONGLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(ULONGLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(LONGLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(ULONGLONG);
    BOOST_WINAPI_TEST_TYPE_SAME(INT_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(UINT_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(LONG_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(ULONG_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(DWORD_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(PDWORD_PTR);
    BOOST_WINAPI_TEST_TYPE_SAME(SIZE_T);
    BOOST_WINAPI_TEST_TYPE_SAME(PSIZE_T);
    BOOST_WINAPI_TEST_TYPE_SAME(SSIZE_T);
    BOOST_WINAPI_TEST_TYPE_SAME(PSSIZE_T);
    BOOST_WINAPI_TEST_TYPE_SAME(PVOID);
    BOOST_WINAPI_TEST_TYPE_SAME(LPVOID);
    BOOST_WINAPI_TEST_TYPE_SAME(LPCVOID);
    BOOST_WINAPI_TEST_TYPE_SAME(CHAR);
    BOOST_WINAPI_TEST_TYPE_SAME(LPSTR);
    BOOST_WINAPI_TEST_TYPE_SAME(LPCSTR);
    BOOST_WINAPI_TEST_TYPE_SAME(WCHAR);
    BOOST_WINAPI_TEST_TYPE_SAME(LPWSTR);
    BOOST_WINAPI_TEST_TYPE_SAME(LPCWSTR);

    BOOST_WINAPI_TEST_TYPE_SAME(VOID);

#if BOOST_PLAT_WINDOWS_SDK_VERSION >= BOOST_WINAPI_WINDOWS_SDK_6_0 && BOOST_WINAPI_PARTITION_APP_SYSTEM
    // Windows SDK that comes with MSVC-7.1 and 8 does not define NTSTATUS. Up until Windows SDK 10 NTSTATUS is only defined in Desktop API partition.
    BOOST_WINAPI_TEST_TYPE_SAME(NTSTATUS);
    BOOST_WINAPI_TEST_TYPE_SAME(PNTSTATUS);
#endif

    BOOST_WINAPI_TEST_TYPE_SAME(HMODULE);

    BOOST_WINAPI_TEST_STRUCT(LARGE_INTEGER, (LowPart)(HighPart)(u.LowPart)(u.HighPart)(QuadPart));
    BOOST_WINAPI_TEST_STRUCT(SECURITY_ATTRIBUTES, (nLength)(lpSecurityDescriptor)(bInheritHandle));

    return boost::report_errors();
}

