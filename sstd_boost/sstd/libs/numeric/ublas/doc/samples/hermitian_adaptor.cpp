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

#include <sstd/boost/numeric/ublas/hermitian.hpp>
#include <sstd/boost/numeric/ublas/io.hpp>

int main () {
    using namespace boost::numeric::ublas;
    matrix<std::complex<double> > m (3, 3);
    hermitian_adaptor<matrix<std::complex<double> >, lower> hal (m);
    for (unsigned i = 0; i < hal.size1 (); ++ i) {
        for (unsigned j = 0; j < i; ++ j)
            hal (i, j) = std::complex<double> (3 * i + j, 3 * i + j);
        hal (i, i) = std::complex<double> (4 * i, 0);
    }
    std::cout << hal << std::endl;
    hermitian_adaptor<matrix<std::complex<double> >, upper> hau (m);
    for (unsigned i = 0; i < hau.size1 (); ++ i) {
        hau (i, i) = std::complex<double> (4 * i, 0);
        for (unsigned j = i + 1; j < hau.size2 (); ++ j)
            hau (i, j) = std::complex<double> (3 * i + j, 3 * i + j);
    }
    std::cout << hau << std::endl;
}
