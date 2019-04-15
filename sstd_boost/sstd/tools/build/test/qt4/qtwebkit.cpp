﻿// (c) Copyright Juergen Hunold 2008
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MODULE QtWebKit

#include <QWebPage>
#include <QApplication>

#include <sstd/boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( defines)
{
    BOOST_CHECK_EQUAL(BOOST_IS_DEFINED(QT_CORE_LIB), true);
    BOOST_CHECK_EQUAL(BOOST_IS_DEFINED(QT_GUI_LIB), true);
    BOOST_CHECK_EQUAL(BOOST_IS_DEFINED(QT_WEBKIT_LIB), true);
}

BOOST_AUTO_TEST_CASE( webkit )
{
    QWebPage page;
    BOOST_CHECK_EQUAL(page.isModified(), false);
}
