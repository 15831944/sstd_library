﻿// Copyright 2015-2017 Hans Dembinski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/core/lightweight_test.hpp>
#include <sstd/boost/histogram/axis/integer.hpp>
#include <sstd/boost/histogram/axis/regular.hpp>
#include <sstd/boost/histogram/histogram.hpp>
#include <sstd/boost/histogram/literals.hpp>
#include <sstd/boost/histogram/storage_adaptor.hpp>
#include <sstd/boost/histogram/unlimited_storage.hpp>
#include "utility_histogram.hpp"

using namespace boost::histogram;

template <typename T1, typename T2>
void run_tests() {
  // compare
  {
    auto a = make(T1{}, axis::regular<>{3, 0, 3}, axis::integer<>(0, 2));
    auto b = make_s(T2{}, std::vector<unsigned>(), axis::regular<>{3, 0, 3},
                    axis::integer<>(0, 2));
    BOOST_TEST_EQ(a, b);
    auto b2 = make(T2{}, axis::integer<>{0, 3}, axis::integer<>(0, 2));
    BOOST_TEST_NE(a, b2);
    auto b3 = make(T2{}, axis::regular<>(3, 0, 4), axis::integer<>(0, 2));
    BOOST_TEST_NE(a, b3);
  }

  // operators
  {
    auto a = make(T1{}, axis::integer<int, use_default, axis::option::none_t>{0, 2});
    auto b = make(T2{}, axis::integer<int, use_default, axis::option::none_t>{0, 2});
    BOOST_TEST_EQ(a, b);
    a(0); // 1 0
    b(1); // 0 1
    a += b;
    BOOST_TEST_EQ(a[0], 1);
    BOOST_TEST_EQ(a[1], 1);
    a *= b;
    BOOST_TEST_EQ(a[0], 0);
    BOOST_TEST_EQ(a[1], 1);
    a -= b;
    BOOST_TEST_EQ(a[0], 0);
    BOOST_TEST_EQ(a[1], 0);
    a[0] = 2;
    a[1] = 4;
    b[0] = 2;
    b[1] = 2;
    a /= b;
    BOOST_TEST_EQ(a[0], 1);
    BOOST_TEST_EQ(a[1], 2);

    BOOST_TEST_THROWS(a += make(T2{}, axis::integer<>{0, 3}), std::invalid_argument);
    BOOST_TEST_THROWS(a -= make(T2{}, axis::integer<>{0, 3}), std::invalid_argument);
    BOOST_TEST_THROWS(a *= make(T2{}, axis::integer<>{0, 3}), std::invalid_argument);
    BOOST_TEST_THROWS(a /= make(T2{}, axis::integer<>{0, 3}), std::invalid_argument);
  }

  // copy_assign
  {
    auto a = make(T1{}, axis::regular<>{3, 0, 3}, axis::integer<>{0, 2});
    auto b = make_s(T2{}, std::vector<double>(), axis::regular<>{3, 0, 3},
                    axis::integer<>{0, 2});
    a(1, 1);
    BOOST_TEST_NE(a, b);
    b = a;
    BOOST_TEST_EQ(a, b);
  }
}

int main() {
  run_tests<static_tag, dynamic_tag>();
  run_tests<dynamic_tag, static_tag>();

  return boost::report_errors();
}