﻿/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <sstd/boost/fusion/container/deque/deque.hpp>
#include <sstd/boost/fusion/container/deque/convert.hpp>
#include <sstd/boost/fusion/adapted/mpl.hpp>

#define BOOST_FUSION_SEQUENCE_CONVERSION_IS_NOT_SEQUENCE__TYPE_PRESERVING

#define FUSION_SEQUENCE deque
#include "misc.hpp"

int
main()
{
    test();
    return boost::report_errors();
}


