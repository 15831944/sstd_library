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

// template <class Mutex> class unique_lock;

// unique_lock(mutex_type& m, try_to_lock_t);


#include <sstd/boost/thread/lock_types.hpp>
#include <sstd/boost/thread/mutex.hpp>
#include <sstd/boost/thread/thread.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>
#include "../../../../../timming.hpp"


boost::mutex m;

#if defined BOOST_THREAD_USES_CHRONO
typedef boost::chrono::high_resolution_clock Clock;
typedef Clock::time_point time_point;
typedef Clock::duration duration;
typedef boost::chrono::milliseconds ms;
typedef boost::chrono::nanoseconds ns;
time_point t0;
time_point t1;
#else
#endif

const ms max_diff(BOOST_THREAD_TEST_TIME_MS);

void f()
{
#if defined BOOST_THREAD_USES_CHRONO
  t0 = Clock::now();
  {
    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
    BOOST_TEST(lk.owns_lock() == false);
  }
  {
    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
    BOOST_TEST(lk.owns_lock() == false);
  }
  {
    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
    BOOST_TEST(lk.owns_lock() == false);
  }
  for (;;)
  {
    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
    if (lk.owns_lock()) {
      t1 = Clock::now();
      break;
    }
  }
  //m.unlock();
#else
//  time_point t0 = Clock::now();
//  {
//    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
//    BOOST_TEST(lk.owns_lock() == false);
//  }
//  {
//    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
//    BOOST_TEST(lk.owns_lock() == false);
//  }
//  {
//    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
//    BOOST_TEST(lk.owns_lock() == false);
//  }
  for (;;)
  {
    boost::unique_lock<boost::mutex> lk(m, boost::try_to_lock);
    if (lk.owns_lock()) break;
  }
  //time_point t1 = Clock::now();
  //ns d = t1 - t0 - ms(250);
  //BOOST_TEST(d < max_diff);
#endif
}

int main()
{
  m.lock();
  boost::thread t(f);
#if defined BOOST_THREAD_USES_CHRONO
  time_point t2 = Clock::now();
  boost::this_thread::sleep_for(ms(250));
  time_point t3 = Clock::now();
#else
#endif
  m.unlock();
  t.join();

#if defined BOOST_THREAD_USES_CHRONO
  ns sleep_time = t3 - t2;
  ns d_ns = t1 - t0 - sleep_time;
  ms d_ms = boost::chrono::duration_cast<boost::chrono::milliseconds>(d_ns);
  std::cout << "d_ns: " << d_ns.count() << std::endl;
  std::cout << "d_ms: " << d_ms.count() << std::endl;
  // BOOST_TEST_GE(d_ms.count(), 0);
  BOOST_THREAD_TEST_IT(d_ms, max_diff);
  BOOST_THREAD_TEST_IT(d_ns, ns(max_diff));
#endif

  return boost::report_errors();
}
