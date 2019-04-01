﻿//
//  weak_from_raw_test4.cpp
//
//  As weak_from_raw_test2.cpp, but uses weak_from_raw
//  in the constructor
//
//  Copyright (c) 2014, 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#include <sstd/boost/smart_ptr/enable_shared_from_raw.hpp>
#include <sstd/boost/weak_ptr.hpp>
#include <sstd/boost/core/lightweight_test.hpp>

class X;

static boost::weak_ptr< X > r_;

void register_( boost::weak_ptr< X > const & r )
{
    r_ = r;
}

void check_( boost::weak_ptr< X > const & r )
{
    BOOST_TEST( !( r < r_ ) && !( r_ < r ) );
}

void unregister_( boost::weak_ptr< X > const & r )
{
    BOOST_TEST( !( r < r_ ) && !( r_ < r ) );
    r_.reset();
}

class X: public boost::enable_shared_from_raw
{
public:

    X()
    {
        register_( boost::weak_from_raw( this ) );
    }

    ~X()
    {
        unregister_( boost::weak_from_raw( this ) );
    }

    void check()
    {
        check_( boost::weak_from_raw( this ) );
    }
};

int main()
{
    {
        boost::shared_ptr< X > px( new X );
        px->check();
    }

    return boost::report_errors();
}

