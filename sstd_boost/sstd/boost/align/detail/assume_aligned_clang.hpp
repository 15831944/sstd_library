﻿/*
Copyright 2015 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ASSUME_ALIGNED_CLANG_HPP
#define BOOST_ALIGN_DETAIL_ASSUME_ALIGNED_CLANG_HPP

#if __has_builtin(__builtin_assume_aligned)
#define BOOST_ALIGN_ASSUME_ALIGNED(p, n) \
(p) = static_cast<__typeof__(p)>(__builtin_assume_aligned((p), (n)))
#else
#define BOOST_ALIGN_ASSUME_ALIGNED(p, n)
#endif

#endif

