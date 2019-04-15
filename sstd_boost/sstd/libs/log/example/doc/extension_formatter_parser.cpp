﻿/*
 *          Copyright Andrey Semashev 2007 - 2015.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstd/boost/smart_ptr/shared_ptr.hpp>
#include <sstd/boost/smart_ptr/make_shared_object.hpp>
#include <sstd/boost/format.hpp>
#include <sstd/boost/phoenix.hpp>
#include <sstd/boost/log/core.hpp>
#include <sstd/boost/log/expressions.hpp>
#include <sstd/boost/log/attributes/attribute_name.hpp>
#include <sstd/boost/log/sources/logger.hpp>
#include <sstd/boost/log/sources/record_ostream.hpp>
#include <sstd/boost/log/utility/value_ref.hpp>
#include <sstd/boost/log/utility/formatting_ostream.hpp>
#include <sstd/boost/log/utility/manipulators/add_value.hpp>
#include <sstd/boost/log/utility/setup/formatter_parser.hpp>
#include <sstd/boost/log/utility/setup/common_attributes.hpp>
#include <sstd/boost/log/utility/setup/console.hpp>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

//[ example_extension_formatter_parser_point_definition
struct point
{
    float m_x, m_y;

    point() : m_x(0.0f), m_y(0.0f) {}
    point(float x, float y) : m_x(x), m_y(y) {}
};

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<< (std::basic_ostream< CharT, TraitsT >& strm, point const& p)
{
    strm << "(" << p.m_x << ", " << p.m_y << ")";
    return strm;
}
//]

#if 0
//[ example_extension_simple_formatter_factory
void init_factories()
{
    logging::register_simple_formatter_factory< point, char >("Coordinates");
}
//]
#endif

//[ example_extension_custom_formatter_factory
// Custom point formatter
class point_formatter
{
public:
    typedef void result_type;

public:
    explicit point_formatter(std::string const& fmt) : m_format(fmt)
    {
    }

    void operator() (logging::formatting_ostream& strm, logging::value_ref< point > const& value) const
    {
        if (value)
        {
            point const& p = value.get();
            m_format % p.m_x % p.m_y;
            strm << m_format;
            m_format.clear();
        }
    }

private:
    mutable boost::format m_format;
};

// Custom point formatter factory
class point_formatter_factory :
    public logging::basic_formatter_factory< char, point >
{
public:
    formatter_type create_formatter(logging::attribute_name const& name, args_map const& args)
    {
        args_map::const_iterator it = args.find("format");
        if (it != args.end())
            return boost::phoenix::bind(point_formatter(it->second), expr::stream, expr::attr< point >(name));
        else
            return expr::stream << expr::attr< point >(name);
    }
};

void init_factories()
{
    logging::register_formatter_factory("Coordinates", boost::make_shared< point_formatter_factory >());
}
//]

void init_logging()
{
    init_factories();

    logging::add_console_log(std::clog, keywords::format = "%TimeStamp% %Coordinates(format=\"{%0.3f; %0.3f}\")% %Message%");

    logging::add_common_attributes();
}

int main(int, char*[])
{
    init_logging();

    src::logger lg;
    BOOST_LOG(lg) << logging::add_value("Coordinates", point(10.5f, 20.2f)) << "Hello, world with coordinates!";

    return 0;
}
