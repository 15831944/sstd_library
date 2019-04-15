﻿// Copyright (C) 2016-2018 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//[ lazy_vector
// Defining this allows the assignment below of an expression to a double
// without writing any specific code to do so.
#include <sstd/boost/yap/expression.hpp>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


template<boost::yap::expr_kind Kind, typename Tuple>
struct lazy_vector_expr;


// This transform turns a terminal of std::vector<double> into a terminal
// containing the nth double in that vector.  Think of it as turning our
// expression of vectors into an expression of scalars.
struct take_nth
{
    boost::yap::terminal<lazy_vector_expr, double> operator()(
        boost::yap::terminal<lazy_vector_expr, std::vector<double>> const &
            expr);

    std::size_t n;
};

// A custom expression template that defines lazy + and - operators that
// produce expressions, and an eager [] operator that returns the nth element
// of the expression.
//[ lazy_vector_decl
template<boost::yap::expr_kind Kind, typename Tuple>
struct lazy_vector_expr
{
    static const boost::yap::expr_kind kind = Kind;

    Tuple elements;

    // Note that this does not return an expression; it is greedily evaluated.
    auto operator[](std::size_t n) const;
};

BOOST_YAP_USER_BINARY_OPERATOR(plus, lazy_vector_expr, lazy_vector_expr)
BOOST_YAP_USER_BINARY_OPERATOR(minus, lazy_vector_expr, lazy_vector_expr)
//]

template<boost::yap::expr_kind Kind, typename Tuple>
auto lazy_vector_expr<Kind, Tuple>::operator[](std::size_t n) const
{
    return boost::yap::evaluate(boost::yap::transform(*this, take_nth{n}));
}

boost::yap::terminal<lazy_vector_expr, double> take_nth::operator()(
    boost::yap::terminal<lazy_vector_expr, std::vector<double>> const & expr)
{
    double x = boost::yap::value(expr)[n];
    // This move is something of a hack.  The move indicates that the terminal
    // should keep the value of x (since, being an rvalue, it may be a
    // temporary), rather than a reference to x.  See the "How Expression
    // Operands Are Treated" section of the tutorial for details.
    return boost::yap::make_terminal<lazy_vector_expr, double>(std::move(x));
}

// In order to define the += operator with the semantics we want, it's
// convenient to derive a terminal type from a terminal instantiation of
// lazy_vector_expr.  note that we could have written a template
// specialization here instead -- either one would work.  That would of course
// have required more typing.
struct lazy_vector : lazy_vector_expr<
                         boost::yap::expr_kind::terminal,
                         boost::hana::tuple<std::vector<double>>>
{
    lazy_vector() {}

    explicit lazy_vector(std::vector<double> && vec)
    {
        elements = boost::hana::tuple<std::vector<double>>(std::move(vec));
    }

    template<boost::yap::expr_kind Kind, typename Tuple>
    lazy_vector & operator+=(lazy_vector_expr<Kind, Tuple> const & rhs)
    {
        std::vector<double> & this_vec = boost::yap::value(*this);
        for (int i = 0, size = (int)this_vec.size(); i < size; ++i) {
            this_vec[i] += rhs[i];
        }
        return *this;
    }
};

lazy_vector v1{std::vector<double>(4, 1.0)};
lazy_vector v2{std::vector<double>(4, 2.0)};
lazy_vector v3{std::vector<double>(4, 3.0)};

double get_d1_with_yap()
{
    double retval = (v2 + v3)[2];
    return retval;
}

double get_d1_by_hand()
{
    std::vector<double> & v2_ref = boost::yap::value(v2);
    std::vector<double> & v3_ref = boost::yap::value(v3);
    double retval = v2_ref[2] + v3_ref[2];
    return retval;
}

void update_v1_with_yap() { v1 += v2 - v3; }

void update_v1_by_hand()
{
    std::vector<double> & v1_ref = boost::yap::value(v1);
    std::vector<double> & v2_ref = boost::yap::value(v2);
    std::vector<double> & v3_ref = boost::yap::value(v3);
    for (int i = 0, size = (int)v1_ref.size(); i < size; ++i) {
        v1_ref[i] += v2_ref[i] - v3_ref[i];
    }
}

int main()
{
    double d1_1 = get_d1_with_yap();
    std::cout << d1_1 << "\n";

    double d1_2 = get_d1_by_hand();
    std::cout << d1_2 << "\n";

    update_v1_with_yap();
    std::cout << '{' << v1[0] << ',' << v1[1] << ',' << v1[2] << ',' << v1[3]
              << '}' << "\n";

    boost::yap::value(v1) = std::vector<double>(4, 1.0);

    update_v1_by_hand();
    std::cout << '{' << v1[0] << ',' << v1[1] << ',' << v1[2] << ',' << v1[3]
              << '}' << "\n";

    // This expression is disallowed because it does not conform to the
    // implicit grammar.  operator+= is only defined on terminals, not
    // arbitrary expressions.
    // (v2 + v3) += v1;

    return 0;
}
//]
