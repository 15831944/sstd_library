﻿//
//  Copyright (c) 2000-2002
//  Joerg Walter, Mathias Koch
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  The authors gratefully acknowledge the support of
//  GeNeSys mbH & Co. KG in producing this work.
//

#include <sstd/boost/numeric/ublas/banded.hpp>
#include <sstd/boost/numeric/ublas/io.hpp>

int main () {
    using namespace boost::numeric::ublas;
    banded_matrix<double> m (3, 3, 1, 1);
    for (signed i = 0; i < signed (m.size1 ()); ++ i)
        for (signed j = (std::max) (i - 1, 0); j < (std::min) (i + 2, signed (m.size2 ())); ++ j)
            m (i, j) = 3 * i + j;
    std::cout << m << std::endl;
}
