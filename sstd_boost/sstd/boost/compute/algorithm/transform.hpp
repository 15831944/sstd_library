﻿//---------------------------------------------------------------------------//
// Copyright (c) 2013 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://boostorg.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_ALGORITHM_TRANSFORM_HPP
#define BOOST_COMPUTE_ALGORITHM_TRANSFORM_HPP

#include <sstd/boost/static_assert.hpp>

#include <sstd/boost/compute/system.hpp>
#include <sstd/boost/compute/command_queue.hpp>
#include <sstd/boost/compute/algorithm/copy.hpp>
#include <sstd/boost/compute/iterator/transform_iterator.hpp>
#include <sstd/boost/compute/iterator/zip_iterator.hpp>
#include <sstd/boost/compute/functional/detail/unpack.hpp>
#include <sstd/boost/compute/type_traits/is_device_iterator.hpp>

namespace boost {
namespace compute {

/// Transforms the elements in the range [\p first, \p last) using
/// operator \p op and stores the results in the range beginning at
/// \p result.
///
/// For example, to calculate the absolute value for each element in a vector:
///
/// \snippet test/test_transform.cpp transform_abs
///
/// Space complexity: \Omega(1)
///
/// \see copy()
template<class InputIterator, class OutputIterator, class UnaryOperator>
inline OutputIterator transform(InputIterator first,
                                InputIterator last,
                                OutputIterator result,
                                UnaryOperator op,
                                command_queue &queue = system::default_queue())
{
    BOOST_STATIC_ASSERT(is_device_iterator<InputIterator>::value);
    BOOST_STATIC_ASSERT(is_device_iterator<OutputIterator>::value);
    return copy(
               ::boost::compute::make_transform_iterator(first, op),
               ::boost::compute::make_transform_iterator(last, op),
               result,
               queue
           );
}

/// \overload
template<class InputIterator1,
         class InputIterator2,
         class OutputIterator,
         class BinaryOperator>
inline OutputIterator transform(InputIterator1 first1,
                                InputIterator1 last1,
                                InputIterator2 first2,
                                OutputIterator result,
                                BinaryOperator op,
                                command_queue &queue = system::default_queue())
{
    BOOST_STATIC_ASSERT(is_device_iterator<InputIterator1>::value);
    BOOST_STATIC_ASSERT(is_device_iterator<InputIterator2>::value);
    BOOST_STATIC_ASSERT(is_device_iterator<OutputIterator>::value);

    typedef typename std::iterator_traits<InputIterator1>::difference_type difference_type;

    difference_type n = std::distance(first1, last1);

    return transform(
               ::boost::compute::make_zip_iterator(boost::make_tuple(first1, first2)),
               ::boost::compute::make_zip_iterator(boost::make_tuple(last1, first2 + n)),
               result,
               detail::unpack(op),
               queue
           );
}

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_ALGORITHM_TRANSFORM_HPP

