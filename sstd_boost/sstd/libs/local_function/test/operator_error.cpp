﻿
// Copyright (C) 2009-2012 Lorenzo Caminiti
// Distributed under the Boost Software License, Version 1.0
// (see accompanying file LICENSE_1_0.txt or a copy at
// http://www.boost.org/LICENSE_1_0.txt)
// Home at http://www.boost.org/libs/local_function

#include <sstd/boost/config.hpp>
#ifdef BOOST_NO_CXX11_VARIADIC_MACROS
#   error "variadic macros required"
#else

#include <sstd/boost/local_function.hpp>
#include <sstd/boost/typeof/typeof.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
#include <sstd/boost/detail/lightweight_test.hpp>

struct point {
    int x;
    int y;
};
BOOST_TYPEOF_REGISTER_TYPE(point) // Register for `NAME` below.

int main(void) {
    //[operator_error
    bool BOOST_LOCAL_FUNCTION(const point& p, const point& q) {
        return p.x == q.x && p.y == q.y;
    } BOOST_LOCAL_FUNCTION_NAME(operator==) // Error: Cannot use `operator...`.
    //]

    point a; a.x = 1; a.y = 2;
    point b = a;
    BOOST_TEST(a == b);
    return boost::report_errors();
}

#endif // VARIADIC_MACROS


