﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2007-2012.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_DELETER_HPP
#define BOOST_INTERPROCESS_DELETER_HPP

#ifndef BOOST_CONFIG_HPP
#  include <sstd/boost/config.hpp>
#endif
#
#if defined(BOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include <sstd/boost/interprocess/interprocess_fwd.hpp>
#include <sstd/boost/interprocess/detail/utilities.hpp>
#include <sstd/boost/intrusive/pointer_traits.hpp>

//!\file
//!Describes the functor to delete objects from the segment.

namespace boost {
namespace interprocess {

//!A deleter that uses the segment manager's destroy_ptr
//!function to destroy the passed pointer resource.
//!
//!This deleter is used
template<class T, class SegmentManager>
class deleter
{
   public:
   typedef typename boost::intrusive::
      pointer_traits<typename SegmentManager::void_pointer>::template
         rebind_pointer<T>::type                pointer;

   private:
   typedef typename boost::intrusive::
      pointer_traits<pointer>::template
         rebind_pointer<SegmentManager>::type                segment_manager_pointer;

   segment_manager_pointer mp_mngr;

   public:
   deleter(segment_manager_pointer pmngr)
      :  mp_mngr(pmngr)
   {}

   void operator()(const pointer &p)
   {  mp_mngr->destroy_ptr(ipcdetail::to_raw_pointer(p));   }
};

}  //namespace interprocess {
}  //namespace boost {

#include <sstd/boost/interprocess/detail/config_end.hpp>

#endif   //#ifndef BOOST_INTERPROCESS_DELETER_HPP
