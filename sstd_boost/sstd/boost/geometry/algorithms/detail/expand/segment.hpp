﻿// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2015 Barend Gehrels, Amsterdam, the Netherlands.
// Copyright (c) 2008-2015 Bruno Lalande, Paris, France.
// Copyright (c) 2009-2015 Mateusz Loskot, London, UK.
// Copyright (c) 2014-2015 Samuel Debionne, Grenoble, France.

// This file was modified by Oracle on 2015, 2016, 2017.
// Modifications copyright (c) 2015-2017, Oracle and/or its affiliates.

// Contributed and/or modified by Vissarion Fysikopoulos, on behalf of Oracle
// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_SEGMENT_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_SEGMENT_HPP

#include <sstd/boost/mpl/assert.hpp>
#include <sstd/boost/type_traits/is_same.hpp>

#include <sstd/boost/geometry/core/coordinate_dimension.hpp>
#include <sstd/boost/geometry/core/tags.hpp>

#include <sstd/boost/geometry/algorithms/detail/envelope/box.hpp>
#include <sstd/boost/geometry/algorithms/detail/envelope/range_of_boxes.hpp>
#include <sstd/boost/geometry/algorithms/detail/envelope/segment.hpp>

#include <sstd/boost/geometry/algorithms/detail/expand/indexed.hpp>

#include <sstd/boost/geometry/algorithms/dispatch/expand.hpp>


namespace boost { namespace geometry
{

#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace expand
{

struct segment
{
    template <typename Box, typename Segment, typename Strategy>
    static inline void apply(Box& box,
                             Segment const& segment,
                             Strategy const& strategy)
    {
        Box mbrs[2];

        // compute the envelope of the segment
        typename point_type<Segment>::type p[2];
        detail::assign_point_from_index<0>(segment, p[0]);
        detail::assign_point_from_index<1>(segment, p[1]);
        detail::envelope::envelope_segment
            <
                dimension<Segment>::value
            >::apply(p[0], p[1], mbrs[0], strategy);

        // normalize the box
        detail::envelope::envelope_box_on_spheroid::apply(box, mbrs[1], strategy);

        // compute the envelope of the two boxes
        detail::envelope::envelope_range_of_boxes::apply(mbrs, box, strategy);
    }
};


}} // namespace detail::expand
#endif // DOXYGEN_NO_DETAIL

#ifndef DOXYGEN_NO_DISPATCH
namespace dispatch
{

template
<
    typename Box, typename Segment,
    typename CSTagOut, typename CSTag
>
struct expand
    <
        Box, Segment,
        box_tag, segment_tag,
        CSTagOut, CSTag
    >
{
    BOOST_MPL_ASSERT_MSG((false),
                         NOT_IMPLEMENTED_FOR_THESE_COORDINATE_SYSTEMS,
                         (types<CSTagOut, CSTag>()));
};

template
<
    typename Box, typename Segment
>
struct expand
    <
        Box, Segment,
        box_tag, segment_tag,
        cartesian_tag, cartesian_tag
    > : detail::expand::expand_indexed
        <
            0, dimension<Segment>::value
        >
{};

template <typename Box, typename Segment>
struct expand
    <
        Box, Segment,
        box_tag, segment_tag,
        spherical_polar_tag, spherical_polar_tag
    > : detail::expand::segment
{};

template <typename Box, typename Segment>
struct expand
    <
        Box, Segment,
        box_tag, segment_tag,
        spherical_equatorial_tag, spherical_equatorial_tag
    > : detail::expand::segment
{};

template <typename Box, typename Segment>
struct expand
    <
        Box, Segment,
        box_tag, segment_tag,
        geographic_tag, geographic_tag
    > : detail::expand::segment
{};

} // namespace dispatch
#endif // DOXYGEN_NO_DISPATCH

}} // namespace boost::geometry


#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_EXPAND_SEGMENT_HPP

