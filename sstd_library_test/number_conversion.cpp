﻿#include <cassert>
#include <sstd_library_double_conversion/sstd_library_double_conversion.hpp>

extern void test_number_convert() {

    assert(1 == sstd::detail::toDouble("1"));
    assert(1 == sstd::detail::toDouble("1.0"));
    assert(1 == sstd::detail::toDouble(" 1.0"));
    assert(1 == sstd::detail::toDouble(" 1.0 "));
    assert((-1) == sstd::detail::toDouble("-1"));

    assert(sstd::detail::fromStringDouble(1) == "1"sv);
    assert(sstd::detail::fromStringFloat(1) == "1"sv);

    assert(1 == sstd::detail::toLongDouble(" 1.0 "));
    assert("1"sv == sstd::detail::fromStringLongDouble(1));

    {
        auto varTestString = sstd::print("432"sv, ' ', 23, ',', 23.0);
        assert(varTestString == "432 23,23"sv);
    }

    {
        const char * test1 = "bbb";
        auto varTestString = sstd::print("aaa", test1, "cccc");
        assert(varTestString == "aaabbbcccc"sv);
    }

}
