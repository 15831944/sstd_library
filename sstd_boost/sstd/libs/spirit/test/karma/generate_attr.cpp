﻿//  Copyright (c) 2001-2011 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//#define KARMA_FAIL_COMPILATION

#define SPIRIT_ARGUMENTS_LIMIT 10

#include <sstd/boost/config/warning_disable.hpp>
#include <sstd/boost/detail/lightweight_test.hpp>

#include <sstd/boost/spirit/include/karma_char.hpp>
#include <sstd/boost/spirit/include/karma_operator.hpp>
#include <sstd/boost/spirit/include/karma_generate_attr.hpp>

#include "test_attr.hpp"

using namespace spirit_test;

///////////////////////////////////////////////////////////////////////////////
int
main()
{
    using namespace boost::spirit;

    {
        using namespace boost::spirit::ascii;

        BOOST_TEST(test("1", char_, '1'));
        BOOST_TEST(test("12", char_ << char_, '1', '2'));
        BOOST_TEST(test("123", char_ << char_ << char_, '1', '2', '3'));
        BOOST_TEST(test("1234"
          , char_ << char_ << char_ << char_
          , '1', '2', '3', '4'));
        BOOST_TEST(test("12345"
          , char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5'));
        BOOST_TEST(test("123456"
          , char_ << char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5', '6'));
        BOOST_TEST(test("1234567"
          , char_ << char_ << char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5', '6', '7'));
        BOOST_TEST(test("12345678"
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5', '6', '7', '8'));
        BOOST_TEST(test("123456789"
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5', '6', '7', '8', '9'));
        BOOST_TEST(test("1234567890"
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'));
    }

    {
        using namespace boost::spirit::ascii;

        BOOST_TEST(test_delimited("1 ", char_, space, '1'));
        BOOST_TEST(test_delimited("1 2 "
          , char_ << char_, space, '1', '2'));
        BOOST_TEST(test_delimited("1 2 3 "
          , char_ << char_ << char_, space, '1', '2', '3'));
        BOOST_TEST(test_delimited("1 2 3 4 "
          , char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4'));
        BOOST_TEST(test_delimited("1 2 3 4 5 "
          , char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5'));
        BOOST_TEST(test_delimited("1 2 3 4 5 6 "
          , char_ << char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5', '6'));
        BOOST_TEST(test_delimited("1 2 3 4 5 6 7 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5', '6', '7'));
        BOOST_TEST(test_delimited("1 2 3 4 5 6 7 8 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5', '6', '7', '8'));
        BOOST_TEST(test_delimited("1 2 3 4 5 6 7 8 9 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5', '6', '7', '8', '9'));
        BOOST_TEST(test_delimited("1 2 3 4 5 6 7 8 9 0 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'));
    }

    {
        using namespace boost::spirit::ascii;
        using boost::spirit::karma::delimit_flag;

        BOOST_TEST(test_predelimited(" 1 ", char_, space
          , delimit_flag::predelimit, '1'));
        BOOST_TEST(test_predelimited(" 1 2 "
          , char_ << char_, space, delimit_flag::predelimit
          , '1', '2'));
        BOOST_TEST(test_predelimited(" 1 2 3 "
          , char_ << char_ << char_, space
          , delimit_flag::predelimit, '1', '2', '3'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 "
          , char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit, '1', '2', '3', '4'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 "
          , char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit, '1', '2', '3', '4', '5'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 6 "
          , char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit
          , '1', '2', '3', '4', '5', '6'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 6 7 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit
          , '1', '2', '3', '4', '5', '6', '7'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 6 7 8 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 6 7 8 9 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8', '9'));
        BOOST_TEST(test_predelimited(" 1 2 3 4 5 6 7 8 9 0 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'));
    }

    {
        using namespace boost::spirit::ascii;
        using boost::spirit::karma::delimit_flag;

        BOOST_TEST(test_predelimited("1 ", char_, space
          , delimit_flag::dont_predelimit, '1'));
        BOOST_TEST(test_predelimited("1 2 "
          , char_ << char_, space, delimit_flag::dont_predelimit
          , '1', '2'));
        BOOST_TEST(test_predelimited("1 2 3 "
          , char_ << char_ << char_, space
          , delimit_flag::dont_predelimit, '1', '2', '3'));
        BOOST_TEST(test_predelimited("1 2 3 4 "
          , char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit, '1', '2', '3', '4'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 "
          , char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit, '1', '2', '3', '4', '5'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 6 "
          , char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit
          , '1', '2', '3', '4', '5', '6'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 6 7 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit
          , '1', '2', '3', '4', '5', '6', '7'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 6 7 8 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 6 7 8 9 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8', '9'));
        BOOST_TEST(test_predelimited("1 2 3 4 5 6 7 8 9 0 "
          , char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_ << char_
          , space, delimit_flag::dont_predelimit
          , '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'));
    }

    return boost::report_errors();
}


