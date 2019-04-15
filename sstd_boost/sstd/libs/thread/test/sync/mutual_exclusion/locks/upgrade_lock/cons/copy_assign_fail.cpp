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

// <sstd/boost/thread/locks.hpp>

// template <class Mutex> class upgrade_lock;

// upgrade_lock& operator=(upgrade_lock const&) = delete;

#include <sstd/boost/thread/lock_types.hpp>
#include <sstd/boost/thread/shared_mutex.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

boost::shared_mutex m0;
boost::shared_mutex m1;

int main()
{
  boost::upgrade_lock<boost::shared_mutex> lk0(m0);
  boost::upgrade_lock<boost::shared_mutex> lk1(m1);
  lk1 = lk0;
  BOOST_TEST(lk1.mutex() == &m0);
  BOOST_TEST(lk1.owns_lock() == true);
  BOOST_TEST(lk0.mutex() == 0);
  BOOST_TEST(lk0.owns_lock() == false);

}

#include "../../../../../remove_error_code_unused_warning.hpp"
