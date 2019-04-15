﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_SYNC_DETAIL_COMMON_ALGORITHMS_HPP
#define BOOST_INTERPROCESS_SYNC_DETAIL_COMMON_ALGORITHMS_HPP

#ifndef BOOST_CONFIG_HPP
#  include <sstd/boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include <sstd/boost/interprocess/detail/workaround.hpp>

#include <sstd/boost/interprocess/sync/spin/wait.hpp>

namespace boost {
namespace interprocess {
namespace ipcdetail {

template<class MutexType>
bool try_based_timed_lock(MutexType &m, const boost::posix_time::ptime &abs_time)
{
   //Same as lock()
   if(abs_time == boost::posix_time::pos_infin){
      m.lock();
      return true;
   }
   //Always try to lock to achieve POSIX guarantees:
   // "Under no circumstance shall the function fail with a timeout if the mutex
   //  can be locked immediately. The validity of the abs_timeout parameter need not
   //  be checked if the mutex can be locked immediately."
   else if(m.try_lock()){
      return true;
   }
   else{
      spin_wait swait;
      while(microsec_clock::universal_time() < abs_time){
         if(m.try_lock()){
            return true;
         }
         swait.yield();
      }
      return false;
   }
}

template<class MutexType>
void try_based_lock(MutexType &m)
{
   if(!m.try_lock()){
      spin_wait swait;
      do{
         if(m.try_lock()){
            break;
         }
         else{
            swait.yield();
         }
      }
      while(1);
   }
}

template<class MutexType>
void timed_based_lock(MutexType &m, unsigned const uCheckPeriodSec)
{
   const boost::posix_time::time_duration dur(0, 0, uCheckPeriodSec);
   boost::posix_time::ptime deadline(microsec_clock::universal_time()+dur);
   if(!m.timed_lock(deadline)){
      spin_wait swait;
      do{
         deadline = microsec_clock::universal_time()+dur;
         if(m.timed_lock(deadline)){
            break;
         }
         else{
            swait.yield();
         }
      }
      while(1);
   }
}

template<class MutexType>
void timed_based_timed_lock(MutexType &m, const boost::posix_time::ptime &abs_time, unsigned const uCheckPeriodSec)
{
   const boost::posix_time::time_duration dur(0, 0, uCheckPeriodSec);
   boost::posix_time::ptime deadline(microsec_clock::universal_time()+dur);
   if(abs_time <= deadline){
      m.timed_lock(abs_time);
   }
   else if(!m.timed_lock(deadline)){
      spin_wait swait;
      do{
         deadline = microsec_clock::universal_time()+dur;
         if(m.timed_lock(deadline)){
            break;
         }
         else{
            swait.yield();
         }
      }
      while(1);
   }
}

}  //namespace ipcdetail
}  //namespace interprocess
}  //namespace boost

#include <sstd/boost/interprocess/detail/config_end.hpp>

#endif   //BOOST_INTERPROCESS_SYNC_DETAIL_COMMON_ALGORITHMS_HPP
