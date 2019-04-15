﻿
//          Copyright Oliver Kowalke 2009.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <sstd/boost/assert.hpp>
#include <sstd/boost/config.hpp>
#include <sstd/boost/coroutine/all.hpp>
#include <sstd/boost/thread.hpp>

int count = 384;

#ifdef BOOST_MSVC //MS VisualStudio
__declspec(noinline) void access( char *buf);
#else // GCC
void access( char *buf) __attribute__ ((noinline));
#endif
void access( char *buf)
{
  buf[0] = '\0';
}

void bar( int i)
{
    char buf[4 * 1024];

    if ( i > 0)
    {
        access( buf);
        std::cout << i << ". iteration" << std::endl;
        bar( i - 1);
    }
}

void foo( boost::coroutines::symmetric_coroutine< void >::yield_type &)
{
    bar( count);
}

void thread_fn()
{
    {
        boost::coroutines::symmetric_coroutine< void >::call_type coro( foo);
        coro();
    }
}

int main( int argc, char * argv[])
{
#if defined(BOOST_USE_SEGMENTED_STACKS)
    std::cout << "using segmented stacks: allocates " << count << " * 4kB == " << 4 * count << "kB on stack, ";
    std::cout << "initial stack size = " << boost::coroutines::stack_allocator::traits_type::default_size() / 1024 << "kB" << std::endl;
    std::cout << "application should not fail" << std::endl;
#else
    std::cout << "using standard stacks: allocates " << count << " * 4kB == " << 4 * count << "kB on stack, ";
    std::cout << "initial stack size = " << boost::coroutines::stack_allocator::traits_type::default_size() / 1024 << "kB" << std::endl;
    std::cout << "application might fail" << std::endl;
#endif

    boost::thread( thread_fn).join();

    return 0;
}
