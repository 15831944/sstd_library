﻿// (C) Copyright 2002-4 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.
#include <sstd/boost/config.hpp>
#ifdef BOOST_NO_STD_WSTREAMBUF
#error "wide char i/o not supported on this platform"
#else
#include <sstd/boost/archive/polymorphic_text_woarchive.hpp>
typedef boost::archive::polymorphic_text_woarchive test_oarchive;
typedef std::wofstream test_ostream;
#include <sstd/boost/archive/polymorphic_text_wiarchive.hpp>
typedef boost::archive::polymorphic_text_wiarchive test_iarchive;
typedef std::wifstream test_istream;
#define TEST_STREAM_FLAGS (std::ios_base::openmode)0
#endif

