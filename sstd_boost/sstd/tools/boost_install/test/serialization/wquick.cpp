﻿
// Copyright 2018 Peter Dimov.
//
// Distributed under the Boost Software License, Version 1.0.
//
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <sstd/boost/archive/text_wiarchive.hpp>
#include <sstd/boost/archive/text_woarchive.hpp>
#include <sstd/boost/core/lightweight_test.hpp>
#include <sstream>
#include <string>

int main()
{
    std::wostringstream os;
    std::string s1( "pumpkin pie" );

    {
        boost::archive::text_woarchive oa( os );
        oa << s1;
    }

    std::wistringstream is( os.str() );
    std::string s2;

    {
        boost::archive::text_wiarchive ia( is );
        ia >> s2;
    }

    BOOST_TEST_EQ( s1, s2 );

    return boost::report_errors();
}