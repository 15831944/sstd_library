﻿
// Copyright 2006-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <sstd/boost/unordered_set.hpp>
#include <sstd/boost/core/lightweight_test.hpp>

//[point_example1
    struct point {
        int x;
        int y;
    };

    bool operator==(point const& p1, point const& p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }

    struct point_hash
    {
        std::size_t operator()(point const& p) const
        {
            std::size_t seed = 0;
            boost::hash_combine(seed, p.x);
            boost::hash_combine(seed, p.y);
            return seed;
        }
    };

    boost::unordered_multiset<point, point_hash> points;
//]

int main() {
    point x[] = {{1,2}, {3,4}, {1,5}, {1,2}};
    for(int i = 0; i < sizeof(x) / sizeof(point); ++i)
        points.insert(x[i]);
    BOOST_TEST(points.count(x[0]) == 2);
    BOOST_TEST(points.count(x[1]) == 1);
    point y = {10, 2};
    BOOST_TEST(points.count(y) == 0);

    return boost::report_errors();
}
