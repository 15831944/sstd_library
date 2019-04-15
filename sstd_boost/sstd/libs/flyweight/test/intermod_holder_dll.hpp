﻿/* Boost.Flyweight test of intermodule_holder.
 *
 * Copyright 2006-2018 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#ifndef BOOST_FLYWEIGHT_TEST_INTERMOD_HOLDER_DLL_HPP
#define BOOST_FLYWEIGHT_TEST_INTERMOD_HOLDER_DLL_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <sstd/boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <sstd/boost/flyweight/flyweight.hpp>
#include <sstd/boost/flyweight/hashed_factory.hpp>
#include <sstd/boost/flyweight/intermodule_holder.hpp>
#include <sstd/boost/flyweight/refcounted.hpp>
#include <sstd/boost/flyweight/simple_locking.hpp>
#include <string>

#ifdef BOOST_FLYWEIGHT_TEST_INTERMOD_HOLDER_DLL_SOURCE
#define BOOST_FLYWEIGHT_DLL_DECL BOOST_SYMBOL_EXPORT
#else
#define BOOST_FLYWEIGHT_DLL_DECL BOOST_SYMBOL_IMPORT
#endif

typedef boost::flyweights::flyweight<
  std::string,
  boost::flyweights::intermodule_holder> intermodule_flyweight_string;

BOOST_FLYWEIGHT_DLL_DECL intermodule_flyweight_string
create_intermodule_flyweight_string(const std::string&);

#undef BOOST_FLYWEIGHT_DLL_DECL

#endif
