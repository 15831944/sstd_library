﻿//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <sstd/boost/thread/future.hpp>
// class packaged_task<R>

// packaged_task();


#define BOOST_THREAD_VERSION 4
#if BOOST_THREAD_VERSION == 4
#define BOOST_THREAD_DETAIL_SIGNATURE int()
#else
#define BOOST_THREAD_DETAIL_SIGNATURE int
#endif

#include <sstd/boost/thread/future.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include <string>

int main()
{
  {
    boost::packaged_task<BOOST_THREAD_DETAIL_SIGNATURE> p;
    BOOST_TEST(!p.valid());

  }

  return boost::report_errors();
}
