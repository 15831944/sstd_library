﻿// Boost.Geometry (aka GGL, Generic Geometry Library)
// Unit Test

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2012 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2012 Mateusz Loskot, London, UK.

// Parts of Boost.Geometry are redesigned from Geodan's Geographic Library
// (geolib/GGL), copyright (c) 1995-2010 Geodan, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#include <geometry_test_common.hpp>


#include <sstd/boost/geometry/arithmetic/arithmetic.hpp>

#include <sstd/boost/geometry/algorithms/assign.hpp>

#include <sstd/boost/geometry/geometries/point.hpp>
#include <sstd/boost/geometry/geometries/adapted/c_array.hpp>
#include <sstd/boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <test_common/test_point.hpp>

BOOST_GEOMETRY_REGISTER_C_ARRAY_CS(cs::cartesian)
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)


template <typename P, typename P2>
void test_addition()
{
    P p1;
    bg::assign_values(p1, 1, 2, 3);
    bg::add_value(p1, 10);
    BOOST_CHECK(bg::get<0>(p1) == 11);
    BOOST_CHECK(bg::get<1>(p1) == 12);
    BOOST_CHECK(bg::get<2>(p1) == 13);

    P2 p2(4, 5, 6);
    bg::add_point(p1, p2);
    BOOST_CHECK(bg::get<0>(p1) == 15);
    BOOST_CHECK(bg::get<1>(p1) == 17);
    BOOST_CHECK(bg::get<2>(p1) == 19);
}

template <typename P, typename P2>
void test_subtraction()
{
    P p1;
    bg::assign_values(p1, 1, 2, 3);
    bg::subtract_value(p1, 10);
    BOOST_CHECK(bg::get<0>(p1) == -9);
    BOOST_CHECK(bg::get<1>(p1) == -8);
    BOOST_CHECK(bg::get<2>(p1) == -7);

    P2 p2(4, 6, 8);
    bg::subtract_point(p1, p2);
    BOOST_CHECK(bg::get<0>(p1) == -13);
    BOOST_CHECK(bg::get<1>(p1) == -14);
    BOOST_CHECK(bg::get<2>(p1) == -15);
}

template <typename P, typename P2>
void test_multiplication()
{
    P p1;
    bg::assign_values(p1, 1, 2, 3);
    bg::multiply_value(p1, 5);
    BOOST_CHECK(bg::get<0>(p1) == 5);
    BOOST_CHECK(bg::get<1>(p1) == 10);
    BOOST_CHECK(bg::get<2>(p1) == 15);

    P2 p2(4, 5, 6);
    bg::multiply_point(p1, p2);
    BOOST_CHECK(bg::get<0>(p1) == 20);
    BOOST_CHECK(bg::get<1>(p1) == 50);
    BOOST_CHECK(bg::get<2>(p1) == 90);
}

template <typename P, typename P2>
void test_division()
{
    P p1;
    bg::assign_values(p1, 50, 100, 150);
    bg::divide_value(p1, 5);
    BOOST_CHECK(bg::get<0>(p1) == 10);
    BOOST_CHECK(bg::get<1>(p1) == 20);
    BOOST_CHECK(bg::get<2>(p1) == 30);

    P2 p2(2, 4, 6);
    bg::divide_point(p1, p2);
    BOOST_CHECK(bg::get<0>(p1) == 5);
    BOOST_CHECK(bg::get<1>(p1) == 5);
    BOOST_CHECK(bg::get<2>(p1) == 5);
}

template <typename P, typename P2>
void test_assign()
{
    P p1;
    P2 p2(12, 34, 56);
    bg::assign_values(p1, 12, 34, 56);
    bg::assign_point(p1, p2);
    BOOST_CHECK(bg::get<0>(p1) == 12);
    BOOST_CHECK(bg::get<1>(p1) == 34);
    BOOST_CHECK(bg::get<2>(p1) == 56);

    bg::assign_value(p1, 78);
    BOOST_CHECK(bg::get<0>(p1) == 78);
    BOOST_CHECK(bg::get<1>(p1) == 78);
    BOOST_CHECK(bg::get<2>(p1) == 78);
}


template <typename P>
void test_all()
{
    typedef test::test_const_point P2;

    test_addition<P, P2>();
    test_subtraction<P, P2>();
    test_multiplication<P, P2>();
    test_division<P, P2>();
    test_assign<P, P2>();
}


int test_main(int, char* [])
{
    test_all<int[3]>();
    test_all<float[3]>();
    test_all<double[3]>();
    test_all<test::test_point>();
    test_all<bg::model::point<int, 3, bg::cs::cartesian> >();
    test_all<bg::model::point<float, 3, bg::cs::cartesian> >();
    test_all<bg::model::point<double, 3, bg::cs::cartesian> >();

    return 0;
}
