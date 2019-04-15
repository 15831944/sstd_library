﻿// Copyright (c) 2016 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MAIN
#define BOOST_TEST_IGNORE_SIGCHLD
#include <sstd/boost/test/included/unit_test.hpp>

#include <sstd/boost/process/error.hpp>
#include <sstd/boost/process/io.hpp>
#include <sstd/boost/process/async.hpp>
#include <sstd/boost/process/child.hpp>
#include <sstd/boost/process/async_system.hpp>

#include <string>
#include <sstd/boost/asio/io_context.hpp>
#include <sstd/boost/asio/spawn.hpp>
#include <sstd/boost/asio/coroutine.hpp>
#include <sstd/boost/asio/use_future.hpp>
#include <sstd/boost/asio/yield.hpp>

#include <vector>
#include <array>

namespace bp = boost::process;
BOOST_AUTO_TEST_CASE(stackful, *boost::unit_test::timeout(15))
{
    using boost::unit_test::framework::master_test_suite;

    bool did_something_else = false;

    boost::asio::io_context ios;
    auto stackful =
            [&](boost::asio::yield_context yield_)
            {
                int ret =
                    bp::async_system(
                        ios, yield_,
                        master_test_suite().argv[1],
                        "test", "--exit-code", "123");

                BOOST_CHECK_EQUAL(ret, 123);
                BOOST_CHECK(did_something_else);
            };

    boost::asio::spawn(ios, stackful);
    ios.post([&]{did_something_else = true;});

    ios.run();
    BOOST_CHECK(did_something_else);
}
