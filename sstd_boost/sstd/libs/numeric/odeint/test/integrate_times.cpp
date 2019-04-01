﻿/*
 [auto_generated]
 libs/numeric/odeint/test/integrate_times.cpp

 [begin_description]
 This file tests the integrate_times function and its variants.
 [end_description]

 Copyright 2011-2012 Karsten Ahnert
 Copyright 2011-2012 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#define BOOST_TEST_MODULE odeint_integrate_times

#include <sstd/boost/test/unit_test.hpp>

#include <utility>
#include <iostream>
#include <vector>

#include <sstd/boost/ref.hpp>
#include <sstd/boost/iterator/counting_iterator.hpp>

#ifndef ODEINT_INTEGRATE_ITERATOR
#include <sstd/boost/numeric/odeint/integrate/integrate_times.hpp>
#include <sstd/boost/numeric/odeint/integrate/integrate_adaptive.hpp>
#else
#include <sstd/boost/numeric/odeint/iterator/integrate/integrate_times.hpp>
#include <sstd/boost/numeric/odeint/iterator/integrate/integrate_adaptive.hpp>
#endif
#include <sstd/boost/numeric/odeint/stepper/runge_kutta4.hpp>
#include <sstd/boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp>
#include <sstd/boost/numeric/odeint/stepper/runge_kutta_cash_karp54.hpp>
#include <sstd/boost/numeric/odeint/stepper/controlled_runge_kutta.hpp>
#include <sstd/boost/numeric/odeint/stepper/bulirsch_stoer.hpp>
#include <sstd/boost/numeric/odeint/stepper/bulirsch_stoer_dense_out.hpp>
#include <sstd/boost/numeric/odeint/stepper/dense_output_runge_kutta.hpp>

using namespace boost::unit_test;
using namespace boost::numeric::odeint;

typedef double value_type;
typedef std::vector< value_type > state_type;


void lorenz( const state_type &x , state_type &dxdt , const value_type t )
{
    BOOST_CHECK( t >= 0.0 );

    const value_type sigma( 10.0 );
    const value_type R( 28.0 );
    const value_type b( value_type( 8.0 ) / value_type( 3.0 ) );

    dxdt[0] = sigma * ( x[1] - x[0] );
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = -b * x[2] + x[0] * x[1];
}

struct push_back_time
{
    std::vector< double >& m_times;

    push_back_time( std::vector< double > &times )
    :  m_times( times ) { }

    void operator()( const state_type &x , double t )
    {
        m_times.push_back( t );
    }
};

BOOST_AUTO_TEST_SUITE( integrate_times_test )

BOOST_AUTO_TEST_CASE( test_integrate_times )
{

    state_type x( 3 );
    x[0] = x[1] = x[2] = 10.0;

    const value_type dt = 0.03;

    std::vector< double > times;

    std::cout << "test rk4 stepper" << std::endl;

    // simple stepper
    integrate_times( runge_kutta4< state_type >() , lorenz , x , boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();

    std::cout << "test dopri5 stepper" << std::endl;

    // controlled stepper
    integrate_times( controlled_runge_kutta< runge_kutta_dopri5< state_type > >() , lorenz , x ,
                boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();

    std::cout << "test BS stepper" << std::endl;

    //another controlled stepper
    integrate_times( bulirsch_stoer< state_type >() , lorenz , x ,
                boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();

    std::cout << "test dense_out stepper" << std::endl;

    // dense output stepper
    integrate_times( dense_output_runge_kutta< controlled_runge_kutta< runge_kutta_dopri5< state_type > > >() ,
                     lorenz , x ,
                     boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ,
                     dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );

    std::cout << "test BS_do stepper" << std::endl;

    integrate_times( bulirsch_stoer_dense_out< state_type >() , lorenz , x ,
                boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );

}


BOOST_AUTO_TEST_CASE( test_integrate_times_ranges )
{

    state_type x( 3 );
    x[0] = x[1] = x[2] = 10.0;

    const value_type dt = 0.03;

    std::vector< double > times;

    // simple stepper
    integrate_times( runge_kutta4< state_type >() , lorenz , x ,
                std::make_pair( boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();

    // controlled stepper
    integrate_times( controlled_runge_kutta< runge_kutta_dopri5< state_type > >() , lorenz , x ,
                std::make_pair( boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();

    //another controlled stepper
    integrate_times( bulirsch_stoer< state_type >() , lorenz , x ,
                std::make_pair( boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );
    times.clear();


    // dense output stepper
    integrate_times( bulirsch_stoer_dense_out< state_type >() , lorenz , x ,
                std::make_pair( boost::counting_iterator<int>(0) , boost::counting_iterator<int>(10) ) ,
                dt , push_back_time( times ) );

    for( int i=0 ; i<10 ; ++i )
        // check if observer was called at times 0,1,2,...
        BOOST_CHECK_EQUAL( times[i] , static_cast<double>(i) );

}

BOOST_AUTO_TEST_CASE( test_integrate_times_overshoot )
{
    state_type x( 3 );
    x[0] = x[1] = x[2] = 10.0;
    double dt = -0.1;

    std::vector<double> times( 10 );
    for( int i=0 ; i<10 ; ++i )
            times[i] = 1.0-i*1.0/9.0;

    std::cout << "test rk4 stepper" << std::endl;
    // simple stepper
    std::vector<double> obs_times;
    int steps = integrate_times( runge_kutta4< state_type >() , lorenz , x ,
                                 times.begin() , times.end() ,
                                 dt , push_back_time( obs_times ) );
// different behavior for the iterator based integrate implementaton
#ifndef ODEINT_INTEGRATE_ITERATOR
    BOOST_CHECK_EQUAL( steps , 18 ); // we really need 18 steps because dt and
                                     // the difference of the observation times
                                     // are so out of sync
#else
    // iterator based implementation can only return the number of iteration steps
    BOOST_CHECK_EQUAL( steps , 9 );
#endif
    for( int i=0 ; i<10 ; ++i )
        BOOST_CHECK_EQUAL( times[i] , obs_times[i] );

    std::cout << "test rk_ck stepper" << std::endl;
    // controlled stepper
    obs_times.clear();
    integrate_times( controlled_runge_kutta< runge_kutta_cash_karp54< state_type > >() , lorenz , x ,
                     times.begin() , times.end() ,
                     dt , push_back_time( obs_times ) );
    for( int i=0 ; i<10 ; ++i )
        BOOST_CHECK_EQUAL( times[i] , obs_times[i] );

    std::cout << "test dopri5 stepper" << std::endl;
    // controlled stepper
    obs_times.clear();
    integrate_times( dense_output_runge_kutta< controlled_runge_kutta< runge_kutta_dopri5< state_type > > >() , lorenz , x ,
                     times.begin() , times.end() ,
                     dt , push_back_time( obs_times ) );
    for( int i=0 ; i<10 ; ++i )
        BOOST_CHECK_EQUAL( times[i] , obs_times[i] );
}

BOOST_AUTO_TEST_SUITE_END()

