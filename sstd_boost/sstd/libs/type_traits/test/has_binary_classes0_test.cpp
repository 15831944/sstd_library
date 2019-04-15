﻿//  (C) Copyright 2009-2011 Frederic Bron.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/type_traits/has_operator.hpp>
#include "test.hpp"
#include "check_integral_constant.hpp"
#include "has_binary_classes.hpp"

TT_TEST_BEGIN(BOOST_TT_TRAIT_NAME)
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000, C000, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000, C000 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000, C000 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000, C000 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000, C000 const &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const, C000, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const, C000 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const, C000 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const, C000 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const, C000 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000 const, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 &, C000 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const &, C000, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const &, C000 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const &, C000 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const &, C000 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C000 const &, C000 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001, C001, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001, C001 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001, C001 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001, C001 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const, C001 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const, C001 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const, C001 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const, C001 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const, C001 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 &, C001 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C001 const &, C001 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002, C002 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const, C002 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 &, C002 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C002 const &, C002 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005, C005 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const, C005 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 &, C005 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C005 const &, C005 const &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006, C006, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006, C006 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006, C006 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const, C006 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 &, C006 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C006 const &, C006 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009 const, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009, C009 const &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const, C009 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009 const, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 &, C009 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 const, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 &, void >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 const &, ret >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 const &, ret const >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C009 const &, C009 const &, ret const & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010, C010 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const, C010 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 &, C010, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 &, C010, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 &, C010 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 &, C010 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 &, C010 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C010 const &, C010 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011, C011 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const, C011 const &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 const, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 const, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 const &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 &, C011 const &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 &, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 &, ret & >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C011 const &, C011 const &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014, ret >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 const, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 const, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 &, void >::value), 0);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 &, ret const >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 &, ret & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014, C014 const &, ret const & >::value), 1);
   BOOST_CHECK_INTEGRAL_CONSTANT((::boost::has_plus< C014 const, C014, ret const >::value), 1);

TT_TEST_END
