﻿/*-----------------------------------------------------------------------------+
Copyright (c) 2008-2011: Joachim Faulhaber
+------------------------------------------------------------------------------+
   Distributed under the Boost Software License, Version 1.0.
      (See accompanying file LICENCE.txt or copy at
           http://www.boost.org/LICENSE_1_0.txt)
+-----------------------------------------------------------------------------*/
#define BOOST_TEST_MODULE icl::interval_map unit test
#include <libs/icl/test/disable_test_warnings.hpp>
#include <string>
#include <sstd/boost/mpl/list.hpp>
#include "../unit_test_unwarned.hpp"

#define BOOST_ICL_USE_STATIC_BOUNDED_INTERVALS
//#define BOOST_ICL_CONTINUOUS_STATIC_INTERVAL_DEFAULT left_open_interval

// interval instance types
#include "../test_type_lists.hpp"
#include "../test_value_maker.hpp"
#include "../test_functions.hpp"

#include <sstd/boost/icl/interval_map.hpp>
#include <sstd/boost/icl/separate_interval_set.hpp>
#include <sstd/boost/icl/split_interval_set.hpp>

using namespace std;
using namespace boost;
using namespace unit_test;
using namespace boost::icl;

// -----------------------------------------------------------------------------
// test_interval_set_shared are tests that should give identical results for all
// interval_sets: interval_set, separate_interval_set and split_interval_set.
#include "../test_interval_map_shared.hpp"

#define INTERVAL_MAP interval_map
#include "../fast_stat_interval_map_cases.hpp"



