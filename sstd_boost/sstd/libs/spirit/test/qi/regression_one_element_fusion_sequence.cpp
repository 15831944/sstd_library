﻿// Copyright (c) 2001-2011 Hartmut Kaiser
// Copyright (c)      2010 Daniel James
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This compilation test fails if proto expressions are not properly
// distinguished from 'normal' Fusion sequences.

#include <sstd/boost/spirit/include/qi_operator.hpp>
#include <sstd/boost/spirit/include/qi_char.hpp>
#include <sstd/boost/spirit/include/qi_symbols.hpp>
#include <sstd/boost/spirit/include/qi_nonterminal.hpp>
#include <sstd/boost/spirit/include/qi_action.hpp>
#include <sstd/boost/spirit/include/phoenix_core.hpp>
#include <sstd/boost/spirit/include/phoenix_operator.hpp>
#include <string>

int main()
{
    namespace qi = boost::spirit::qi;
    typedef std::string::const_iterator iterator;

    qi::symbols<char, qi::rule<iterator> > phrase_keyword_rules;
    qi::rule<iterator, qi::locals<qi::rule<iterator> > > phrase_markup_impl;

    phrase_markup_impl
        =   (phrase_keyword_rules >> !qi::alnum) [qi::_a = qi::_1]
            ;

    return 0;
}
