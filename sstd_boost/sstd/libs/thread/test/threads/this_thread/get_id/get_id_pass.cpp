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

// <sstd/boost/thread/thread.hpp>

// thread::id this_thread::get_id();

#include <sstd/boost/thread/thread_only.hpp>

#include <sstd/boost/detail/lightweight_test.hpp>

int main()
{
  boost::thread::id id = boost::this_thread::get_id();
  BOOST_TEST(id != boost::thread::id());
  return boost::report_errors();
}
