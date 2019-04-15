﻿/*==============================================================================
    Copyright (c) 2005 Peter Dimov
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <sstd/boost/config.hpp>

#if defined(BOOST_MSVC)
#pragma warning(disable: 4786)  // identifier truncated in debug info
#pragma warning(disable: 4710)  // function not inlined
#pragma warning(disable: 4711)  // function selected for automatic inline expansion
#pragma warning(disable: 4514)  // unreferenced inline removed
#endif

#include <sstd/boost/phoenix/core.hpp>
#include <sstd/boost/phoenix/bind.hpp>
#include <sstd/boost/phoenix/operator.hpp>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(push, 3)
#endif

#include <iostream>

#if defined(BOOST_MSVC) && (BOOST_MSVC < 1300)
#pragma warning(pop)
#endif

#include <sstd/boost/detail/lightweight_test.hpp>

int f( int x )
{
    return x + x;
}

int g( int x )
{
    return 2 * x;
}

int main()
{
    using boost::phoenix::bind;
    using boost::phoenix::ref;
    using boost::phoenix::placeholders::_1;
    using boost::phoenix::placeholders::_2;

    int x = 4;
    int y = x + x;

    // bind op value

    BOOST_TEST( ( bind( f, _1 ) == y )( x ) );
    BOOST_TEST( !( ( bind( f, _1 ) != y )( x ) ) );

    BOOST_TEST( !( ( bind( f, _1 ) < y )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) < y + 1 )( x ) );

    BOOST_TEST( !( ( bind( f, _1 ) > y )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) > y - 1 )( x ) );

    BOOST_TEST( !( ( bind( f, _1 ) <= y - 1 )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) <= y )( x ) );
    BOOST_TEST( ( bind( f, _1 ) <= y + 1 )( x ) );

    BOOST_TEST( !( ( bind( f, _1 ) >= y + 1 )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) >= y )( x ) );
    BOOST_TEST( ( bind( f, _1 ) >= y - 1 )( x ) );

    // bind op ref

    BOOST_TEST( ( bind( f, _1 ) == ref( y ) )( x ) );
    BOOST_TEST( !( ( bind( f, _1 ) != ref( y ) )( x ) ) );
    BOOST_TEST( !( ( bind( f, _1 ) < ref( y ) )( x ) ) );
    BOOST_TEST( !( ( bind( f, _1 ) > ref( y ) )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) <= ref( y ) )( x ) );
    BOOST_TEST( ( bind( f, _1 ) >= ref( y ) )( x ) );

    // bind op placeholder

    BOOST_TEST( ( bind( f, _1 ) == _2 )( x, y ) );
    BOOST_TEST( !( ( bind( f, _1 ) != _2 )( x, y ) ) );
    BOOST_TEST( !( ( bind( f, _1 ) < _2 )( x, y ) ) );
    BOOST_TEST( !( ( bind( f, _1 ) > _2 )( x, y ) ) );
    BOOST_TEST( ( bind( f, _1 ) <= _2 )( x, y ) );
    BOOST_TEST( ( bind( f, _1 ) >= _2 )( x, y ) );

    // bind op bind

    BOOST_TEST( ( bind( f, _1 ) == bind( g, _1 ) )( x ) );
    BOOST_TEST( !( ( bind( f, _1 ) != bind( g, _1 ) )( x ) ) );
    BOOST_TEST( !( ( bind( f, _1 ) < bind( g, _1 ) )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) <= bind( g, _1 ) )( x ) );
    BOOST_TEST( !( ( bind( f, _1 ) > bind( g, _1 ) )( x ) ) );
    BOOST_TEST( ( bind( f, _1 ) >= bind( g, _1 ) )( x ) );

    return boost::report_errors();
}
