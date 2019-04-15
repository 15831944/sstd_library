﻿//
// Copyright 2005-2007 Adobe Systems Incorporated
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_CMYK_HPP
#define BOOST_GIL_CMYK_HPP

#include <sstd/boost/gil/metafunctions.hpp>

#include <sstd/boost/mpl/range_c.hpp>
#include <sstd/boost/mpl/vector_c.hpp>

#include <cstddef>

namespace boost { namespace gil {

/// \addtogroup ColorNameModel
/// \{

/// \brief Cyan
struct cyan_t {};

/// \brief Magenta
struct magenta_t {};

/// \brief Yellow
struct yellow_t {};

/// \brief Black
struct black_t {};
/// \}

/// \ingroup ColorSpaceModel
typedef mpl::vector4<cyan_t,magenta_t,yellow_t,black_t>  cmyk_t;

/// \ingroup LayoutModel
typedef layout<cmyk_t> cmyk_layout_t;

/// \ingroup ImageViewConstructors
/// \brief from raw CMYK planar data
template <typename IC>
inline typename type_from_x_iterator<planar_pixel_iterator<IC,cmyk_t> >::view_t
planar_cmyk_view(std::size_t width, std::size_t height, IC c, IC m, IC y, IC k, std::ptrdiff_t rowsize_in_bytes) {
    typedef typename type_from_x_iterator<planar_pixel_iterator<IC,cmyk_t> >::view_t RView;
    return RView(width, height, typename RView::locator(planar_pixel_iterator<IC,cmyk_t>(c,m,y,k), rowsize_in_bytes));
}

} }  // namespace gil

#endif
