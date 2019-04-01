﻿// Copyright Justinas Vygintas Daugmaudis, 2010-2018.
// Use, modification and distribution is subject to the
// Boost Software License, Version 1.0. (See accompanying
// file LICENSE-1.0 or http://www.boost.org/LICENSE-1.0)

#include <sstd/boost/random/sobol.hpp>

#include <sstd/boost/utility.hpp>

#define BOOST_TEST_MAIN
#include <sstd/boost/test/unit_test.hpp>

#include "test_qrng_functions.hpp"


//
// DESCRIPTION:
// ~~~~~~~~~~~~
//
// This file tests the sobol quasi-random number generator.
// These tests compare our results with values produced by the
// original sobol.cc program http://web.maths.unsw.edu.au/~fkuo/sobol/,
// using the new-joe-kuo-6.21201 direction polynomials and direction vectors.
//
// Generally, the command line used to generate the datasets was
// sobol SKIP+N+1 DIMENSION new-joe-kuo-6.21201 | tail -n N
// Note that we asked to show +1 sample from sobol.cc program, because
// it outputs trivial zeros as the first sample.

// Spatial dimension: 2
// N: 99
// Vectors skipped: 0
static const double sobol_02_99[99][2] =
{
  { 0.5000000002, 0.5000000002 },
  { 0.7500000003, 0.2500000001 },
  { 0.2500000001, 0.7500000003 },
  { 0.3750000002, 0.3750000002 },
  { 0.8750000004, 0.8750000004 },
  { 0.6250000003, 0.1250000001 },
  { 0.1250000001, 0.6250000003 },
  { 0.1875000001, 0.3125000001 },
  { 0.6875000003, 0.8125000004 },
  { 0.9375000004, 0.0625000000 },
  { 0.4375000002, 0.5625000003 },
  { 0.3125000001, 0.1875000001 },
  { 0.8125000004, 0.6875000003 },
  { 0.5625000003, 0.4375000002 },
  { 0.0625000000, 0.9375000004 },
  { 0.0937500000, 0.4687500002 },
  { 0.5937500003, 0.9687500005 },
  { 0.8437500004, 0.2187500001 },
  { 0.3437500002, 0.7187500003 },
  { 0.4687500002, 0.0937500000 },
  { 0.9687500005, 0.5937500003 },
  { 0.7187500003, 0.3437500002 },
  { 0.2187500001, 0.8437500004 },
  { 0.1562500001, 0.1562500001 },
  { 0.6562500003, 0.6562500003 },
  { 0.9062500004, 0.4062500002 },
  { 0.4062500002, 0.9062500004 },
  { 0.2812500001, 0.2812500001 },
  { 0.7812500004, 0.7812500004 },
  { 0.5312500002, 0.0312500000 },
  { 0.0312500000, 0.5312500002 },
  { 0.0468750000, 0.2656250001 },
  { 0.5468750003, 0.7656250004 },
  { 0.7968750004, 0.0156250000 },
  { 0.2968750001, 0.5156250002 },
  { 0.4218750002, 0.1406250001 },
  { 0.9218750004, 0.6406250003 },
  { 0.6718750003, 0.3906250002 },
  { 0.1718750001, 0.8906250004 },
  { 0.2343750001, 0.0781250000 },
  { 0.7343750003, 0.5781250003 },
  { 0.9843750005, 0.3281250002 },
  { 0.4843750002, 0.8281250004 },
  { 0.3593750002, 0.4531250002 },
  { 0.8593750004, 0.9531250004 },
  { 0.6093750003, 0.2031250001 },
  { 0.1093750001, 0.7031250003 },
  { 0.0781250000, 0.2343750001 },
  { 0.5781250003, 0.7343750003 },
  { 0.8281250004, 0.4843750002 },
  { 0.3281250002, 0.9843750005 },
  { 0.4531250002, 0.3593750002 },
  { 0.9531250004, 0.8593750004 },
  { 0.7031250003, 0.1093750001 },
  { 0.2031250001, 0.6093750003 },
  { 0.1406250001, 0.4218750002 },
  { 0.6406250003, 0.9218750004 },
  { 0.8906250004, 0.1718750001 },
  { 0.3906250002, 0.6718750003 },
  { 0.2656250001, 0.0468750000 },
  { 0.7656250004, 0.5468750003 },
  { 0.5156250002, 0.2968750001 },
  { 0.0156250000, 0.7968750004 },
  { 0.0234375000, 0.3984375002 },
  { 0.5234375002, 0.8984375004 },
  { 0.7734375004, 0.1484375001 },
  { 0.2734375001, 0.6484375003 },
  { 0.3984375002, 0.0234375000 },
  { 0.8984375004, 0.5234375002 },
  { 0.6484375003, 0.2734375001 },
  { 0.1484375001, 0.7734375004 },
  { 0.2109375001, 0.2109375001 },
  { 0.7109375003, 0.7109375003 },
  { 0.9609375004, 0.4609375002 },
  { 0.4609375002, 0.9609375004 },
  { 0.3359375002, 0.3359375002 },
  { 0.8359375004, 0.8359375004 },
  { 0.5859375003, 0.0859375000 },
  { 0.0859375000, 0.5859375003 },
  { 0.1171875001, 0.1171875001 },
  { 0.6171875003, 0.6171875003 },
  { 0.8671875004, 0.3671875002 },
  { 0.3671875002, 0.8671875004 },
  { 0.4921875002, 0.4921875002 },
  { 0.9921875005, 0.9921875005 },
  { 0.7421875003, 0.2421875001 },
  { 0.2421875001, 0.7421875003 },
  { 0.1796875001, 0.3046875001 },
  { 0.6796875003, 0.8046875004 },
  { 0.9296875004, 0.0546875000 },
  { 0.4296875002, 0.5546875003 },
  { 0.3046875001, 0.1796875001 },
  { 0.8046875004, 0.6796875003 },
  { 0.5546875003, 0.4296875002 },
  { 0.0546875000, 0.9296875004 },
  { 0.0390625000, 0.1328125001 },
  { 0.5390625003, 0.6328125003 },
  { 0.7890625004, 0.3828125002 },
  { 0.2890625001, 0.8828125004 }
};

// Spatial dimension: 7
// N: 100
// Vectors skipped: 127
static const double sobol_07_100[100][7] =
{
  { 0.0117187500, 0.3320312500, 0.2929687500, 0.1914062500, 0.9023437500, 0.6757812500, 0.8632812500 },
  { 0.5117187500, 0.8320312500, 0.7929687500, 0.6914062500, 0.4023437500, 0.1757812500, 0.3632812500 },
  { 0.7617187500, 0.0820312500, 0.0429687500, 0.4414062500, 0.1523437500, 0.4257812500, 0.6132812500 },
  { 0.2617187500, 0.5820312500, 0.5429687500, 0.9414062500, 0.6523437500, 0.9257812500, 0.1132812500 },
  { 0.3867187500, 0.2070312500, 0.9179687500, 0.8164062500, 0.5273437500, 0.5507812500, 0.7382812500 },
  { 0.8867187500, 0.7070312500, 0.4179687500, 0.3164062500, 0.0273437500, 0.0507812500, 0.2382812500 },
  { 0.6367187500, 0.4570312500, 0.6679687500, 0.5664062500, 0.2773437500, 0.3007812500, 0.9882812500 },
  { 0.1367187500, 0.9570312500, 0.1679687500, 0.0664062500, 0.7773437500, 0.8007812500, 0.4882812500 },
  { 0.1992187500, 0.0195312500, 0.7304687500, 0.2539062500, 0.4648437500, 0.9882812500, 0.6757812500 },
  { 0.6992187500, 0.5195312500, 0.2304687500, 0.7539062500, 0.9648437500, 0.4882812500, 0.1757812500 },
  { 0.9492187500, 0.2695312500, 0.9804687500, 0.0039062500, 0.7148437500, 0.2382812500, 0.9257812500 },
  { 0.4492187500, 0.7695312500, 0.4804687500, 0.5039062500, 0.2148437500, 0.7382812500, 0.4257812500 },
  { 0.3242187500, 0.3945312500, 0.1054687500, 0.6289062500, 0.0898437500, 0.8632812500, 0.8007812500 },
  { 0.8242187500, 0.8945312500, 0.6054687500, 0.1289062500, 0.5898437500, 0.3632812500, 0.3007812500 },
  { 0.5742187500, 0.1445312500, 0.3554687500, 0.8789062500, 0.8398437500, 0.1132812500, 0.5507812500 },
  { 0.0742187500, 0.6445312500, 0.8554687500, 0.3789062500, 0.3398437500, 0.6132812500, 0.0507812500 },
  { 0.1054687500, 0.1757812500, 0.1992187500, 0.5976562500, 0.6835937500, 0.3320312500, 0.3320312500 },
  { 0.6054687500, 0.6757812500, 0.6992187500, 0.0976562500, 0.1835937500, 0.8320312500, 0.8320312500 },
  { 0.8554687500, 0.4257812500, 0.4492187500, 0.8476562500, 0.4335937500, 0.5820312500, 0.0820312500 },
  { 0.3554687500, 0.9257812500, 0.9492187500, 0.3476562500, 0.9335937500, 0.0820312500, 0.5820312500 },
  { 0.4804687500, 0.3007812500, 0.5742187500, 0.4726562500, 0.8085937500, 0.4570312500, 0.2070312500 },
  { 0.9804687500, 0.8007812500, 0.0742187500, 0.9726562500, 0.3085937500, 0.9570312500, 0.7070312500 },
  { 0.7304687500, 0.0507812500, 0.8242187500, 0.2226562500, 0.0585937500, 0.7070312500, 0.4570312500 },
  { 0.2304687500, 0.5507812500, 0.3242187500, 0.7226562500, 0.5585937500, 0.2070312500, 0.9570312500 },
  { 0.1679687500, 0.4882812500, 0.7617187500, 0.9101562500, 0.2460937500, 0.0195312500, 0.1445312500 },
  { 0.6679687500, 0.9882812500, 0.2617187500, 0.4101562500, 0.7460937500, 0.5195312500, 0.6445312500 },
  { 0.9179687500, 0.2382812500, 0.5117187500, 0.6601562500, 0.9960937500, 0.7695312500, 0.3945312500 },
  { 0.4179687500, 0.7382812500, 0.0117187500, 0.1601562500, 0.4960937500, 0.2695312500, 0.8945312500 },
  { 0.2929687500, 0.1132812500, 0.3867187500, 0.0351562500, 0.3710937500, 0.1445312500, 0.2695312500 },
  { 0.7929687500, 0.6132812500, 0.8867187500, 0.5351562500, 0.8710937500, 0.6445312500, 0.7695312500 },
  { 0.5429687500, 0.3632812500, 0.1367187500, 0.2851562500, 0.6210937500, 0.8945312500, 0.0195312500 },
  { 0.0429687500, 0.8632812500, 0.6367187500, 0.7851562500, 0.1210937500, 0.3945312500, 0.5195312500 },
  { 0.0585937500, 0.0664062500, 0.9960937500, 0.7382812500, 0.7617187500, 0.2539062500, 0.0664062500 },
  { 0.5585937500, 0.5664062500, 0.4960937500, 0.2382812500, 0.2617187500, 0.7539062500, 0.5664062500 },
  { 0.8085937500, 0.3164062500, 0.7460937500, 0.9882812500, 0.0117187500, 0.5039062500, 0.3164062500 },
  { 0.3085937500, 0.8164062500, 0.2460937500, 0.4882812500, 0.5117187500, 0.0039062500, 0.8164062500 },
  { 0.4335937500, 0.4414062500, 0.3710937500, 0.3632812500, 0.6367187500, 0.3789062500, 0.4414062500 },
  { 0.9335937500, 0.9414062500, 0.8710937500, 0.8632812500, 0.1367187500, 0.8789062500, 0.9414062500 },
  { 0.6835937500, 0.1914062500, 0.1210937500, 0.1132812500, 0.3867187500, 0.6289062500, 0.1914062500 },
  { 0.1835937500, 0.6914062500, 0.6210937500, 0.6132812500, 0.8867187500, 0.1289062500, 0.6914062500 },
  { 0.2460937500, 0.2539062500, 0.0585937500, 0.8007812500, 0.3242187500, 0.0664062500, 0.3789062500 },
  { 0.7460937500, 0.7539062500, 0.5585937500, 0.3007812500, 0.8242187500, 0.5664062500, 0.8789062500 },
  { 0.9960937500, 0.0039062500, 0.3085937500, 0.5507812500, 0.5742187500, 0.8164062500, 0.1289062500 },
  { 0.4960937500, 0.5039062500, 0.8085937500, 0.0507812500, 0.0742187500, 0.3164062500, 0.6289062500 },
  { 0.3710937500, 0.1289062500, 0.6835937500, 0.1757812500, 0.1992187500, 0.1914062500, 0.0039062500 },
  { 0.8710937500, 0.6289062500, 0.1835937500, 0.6757812500, 0.6992187500, 0.6914062500, 0.5039062500 },
  { 0.6210937500, 0.3789062500, 0.9335937500, 0.4257812500, 0.9492187500, 0.9414062500, 0.2539062500 },
  { 0.1210937500, 0.8789062500, 0.4335937500, 0.9257812500, 0.4492187500, 0.4414062500, 0.7539062500 },
  { 0.0898437500, 0.4101562500, 0.5273437500, 0.0820312500, 0.5429687500, 0.7226562500, 0.5976562500 },
  { 0.5898437500, 0.9101562500, 0.0273437500, 0.5820312500, 0.0429687500, 0.2226562500, 0.0976562500 },
  { 0.8398437500, 0.1601562500, 0.7773437500, 0.3320312500, 0.2929687500, 0.4726562500, 0.8476562500 },
  { 0.3398437500, 0.6601562500, 0.2773437500, 0.8320312500, 0.7929687500, 0.9726562500, 0.3476562500 },
  { 0.4648437500, 0.0351562500, 0.1523437500, 0.9570312500, 0.9179687500, 0.5976562500, 0.9726562500 },
  { 0.9648437500, 0.5351562500, 0.6523437500, 0.4570312500, 0.4179687500, 0.0976562500, 0.4726562500 },
  { 0.7148437500, 0.2851562500, 0.4023437500, 0.7070312500, 0.1679687500, 0.3476562500, 0.7226562500 },
  { 0.2148437500, 0.7851562500, 0.9023437500, 0.2070312500, 0.6679687500, 0.8476562500, 0.2226562500 },
  { 0.1523437500, 0.2226562500, 0.4648437500, 0.3945312500, 0.1054687500, 0.9101562500, 0.9101562500 },
  { 0.6523437500, 0.7226562500, 0.9648437500, 0.8945312500, 0.6054687500, 0.4101562500, 0.4101562500 },
  { 0.9023437500, 0.4726562500, 0.2148437500, 0.1445312500, 0.8554687500, 0.1601562500, 0.6601562500 },
  { 0.4023437500, 0.9726562500, 0.7148437500, 0.6445312500, 0.3554687500, 0.6601562500, 0.1601562500 },
  { 0.2773437500, 0.3476562500, 0.8398437500, 0.5195312500, 0.4804687500, 0.7851562500, 0.5351562500 },
  { 0.7773437500, 0.8476562500, 0.3398437500, 0.0195312500, 0.9804687500, 0.2851562500, 0.0351562500 },
  { 0.5273437500, 0.0976562500, 0.5898437500, 0.7695312500, 0.7304687500, 0.0351562500, 0.7851562500 },
  { 0.0273437500, 0.5976562500, 0.0898437500, 0.2695312500, 0.2304687500, 0.5351562500, 0.2851562500 },
  { 0.0195312500, 0.1992187500, 0.5976562500, 0.9023437500, 0.2539062500, 0.8710937500, 0.4648437500 },
  { 0.5195312500, 0.6992187500, 0.0976562500, 0.4023437500, 0.7539062500, 0.3710937500, 0.9648437500 },
  { 0.7695312500, 0.4492187500, 0.8476562500, 0.6523437500, 0.5039062500, 0.1210937500, 0.2148437500 },
  { 0.2695312500, 0.9492187500, 0.3476562500, 0.1523437500, 0.0039062500, 0.6210937500, 0.7148437500 },
  { 0.3945312500, 0.3242187500, 0.2226562500, 0.0273437500, 0.1289062500, 0.9960937500, 0.0898437500 },
  { 0.8945312500, 0.8242187500, 0.7226562500, 0.5273437500, 0.6289062500, 0.4960937500, 0.5898437500 },
  { 0.6445312500, 0.0742187500, 0.4726562500, 0.2773437500, 0.8789062500, 0.2460937500, 0.3398437500 },
  { 0.1445312500, 0.5742187500, 0.9726562500, 0.7773437500, 0.3789062500, 0.7460937500, 0.8398437500 },
  { 0.2070312500, 0.3867187500, 0.4101562500, 0.5898437500, 0.8164062500, 0.5585937500, 0.0273437500 },
  { 0.7070312500, 0.8867187500, 0.9101562500, 0.0898437500, 0.3164062500, 0.0585937500, 0.5273437500 },
  { 0.9570312500, 0.1367187500, 0.1601562500, 0.8398437500, 0.0664062500, 0.3085937500, 0.2773437500 },
  { 0.4570312500, 0.6367187500, 0.6601562500, 0.3398437500, 0.5664062500, 0.8085937500, 0.7773437500 },
  { 0.3320312500, 0.0117187500, 0.7851562500, 0.4648437500, 0.6914062500, 0.6835937500, 0.4023437500 },
  { 0.8320312500, 0.5117187500, 0.2851562500, 0.9648437500, 0.1914062500, 0.1835937500, 0.9023437500 },
  { 0.5820312500, 0.2617187500, 0.5351562500, 0.2148437500, 0.4414062500, 0.4335937500, 0.1523437500 },
  { 0.0820312500, 0.7617187500, 0.0351562500, 0.7148437500, 0.9414062500, 0.9335937500, 0.6523437500 },
  { 0.1132812500, 0.2929687500, 0.8789062500, 0.3085937500, 0.0351562500, 0.1523437500, 0.9960937500 },
  { 0.6132812500, 0.7929687500, 0.3789062500, 0.8085937500, 0.5351562500, 0.6523437500, 0.4960937500 },
  { 0.8632812500, 0.0429687500, 0.6289062500, 0.0585937500, 0.7851562500, 0.9023437500, 0.7460937500 },
  { 0.3632812500, 0.5429687500, 0.1289062500, 0.5585937500, 0.2851562500, 0.4023437500, 0.2460937500 },
  { 0.4882812500, 0.1679687500, 0.2539062500, 0.6835937500, 0.4101562500, 0.0273437500, 0.6210937500 },
  { 0.9882812500, 0.6679687500, 0.7539062500, 0.1835937500, 0.9101562500, 0.5273437500, 0.1210937500 },
  { 0.7382812500, 0.4179687500, 0.0039062500, 0.9335937500, 0.6601562500, 0.7773437500, 0.8710937500 },
  { 0.2382812500, 0.9179687500, 0.5039062500, 0.4335937500, 0.1601562500, 0.2773437500, 0.3710937500 },
  { 0.1757812500, 0.1054687500, 0.0664062500, 0.2460937500, 0.5976562500, 0.4648437500, 0.5585937500 },
  { 0.6757812500, 0.6054687500, 0.5664062500, 0.7460937500, 0.0976562500, 0.9648437500, 0.0585937500 },
  { 0.9257812500, 0.3554687500, 0.3164062500, 0.4960937500, 0.3476562500, 0.7148437500, 0.8085937500 },
  { 0.4257812500, 0.8554687500, 0.8164062500, 0.9960937500, 0.8476562500, 0.2148437500, 0.3085937500 },
  { 0.3007812500, 0.4804687500, 0.6914062500, 0.8710937500, 0.9726562500, 0.3398437500, 0.9335937500 },
  { 0.8007812500, 0.9804687500, 0.1914062500, 0.3710937500, 0.4726562500, 0.8398437500, 0.4335937500 },
  { 0.5507812500, 0.2304687500, 0.9414062500, 0.6210937500, 0.2226562500, 0.5898437500, 0.6835937500 },
  { 0.0507812500, 0.7304687500, 0.4414062500, 0.1210937500, 0.7226562500, 0.0898437500, 0.1835937500 },
  { 0.0351562500, 0.4648437500, 0.1757812500, 0.4179687500, 0.3945312500, 0.1992187500, 0.7304687500 },
  { 0.5351562500, 0.9648437500, 0.6757812500, 0.9179687500, 0.8945312500, 0.6992187500, 0.2304687500 },
  { 0.7851562500, 0.2148437500, 0.4257812500, 0.1679687500, 0.6445312500, 0.9492187500, 0.9804687500 },
  { 0.2851562500, 0.7148437500, 0.9257812500, 0.6679687500, 0.1445312500, 0.4492187500, 0.4804687500 }
};

// Spatial dimension: 16
// N: 100
// Vectors skipped: 127
static const double sobol_16_100[100][16] =
{
  { 0.0117187500, 0.3320312500, 0.2929687500, 0.1914062500, 0.9023437500, 0.6757812500, 0.8632812500, 0.2460937500, 0.1054687500, 0.8164062500, 0.7382812500, 0.7382812500, 0.8164062500, 0.8789062500, 0.0273437500, 0.7617187500 },
  { 0.5117187500, 0.8320312500, 0.7929687500, 0.6914062500, 0.4023437500, 0.1757812500, 0.3632812500, 0.7460937500, 0.6054687500, 0.3164062500, 0.2382812500, 0.2382812500, 0.3164062500, 0.3789062500, 0.5273437500, 0.2617187500 },
  { 0.7617187500, 0.0820312500, 0.0429687500, 0.4414062500, 0.1523437500, 0.4257812500, 0.6132812500, 0.9960937500, 0.8554687500, 0.0664062500, 0.4882812500, 0.4882812500, 0.5664062500, 0.6289062500, 0.7773437500, 0.5117187500 },
  { 0.2617187500, 0.5820312500, 0.5429687500, 0.9414062500, 0.6523437500, 0.9257812500, 0.1132812500, 0.4960937500, 0.3554687500, 0.5664062500, 0.9882812500, 0.9882812500, 0.0664062500, 0.1289062500, 0.2773437500, 0.0117187500 },
  { 0.3867187500, 0.2070312500, 0.9179687500, 0.8164062500, 0.5273437500, 0.5507812500, 0.7382812500, 0.8710937500, 0.9804687500, 0.4414062500, 0.3632812500, 0.8632812500, 0.6914062500, 0.2539062500, 0.4023437500, 0.1367187500 },
  { 0.8867187500, 0.7070312500, 0.4179687500, 0.3164062500, 0.0273437500, 0.0507812500, 0.2382812500, 0.3710937500, 0.4804687500, 0.9414062500, 0.8632812500, 0.3632812500, 0.1914062500, 0.7539062500, 0.9023437500, 0.6367187500 },
  { 0.6367187500, 0.4570312500, 0.6679687500, 0.5664062500, 0.2773437500, 0.3007812500, 0.9882812500, 0.1210937500, 0.2304687500, 0.6914062500, 0.6132812500, 0.1132812500, 0.9414062500, 0.0039062500, 0.6523437500, 0.3867187500 },
  { 0.1367187500, 0.9570312500, 0.1679687500, 0.0664062500, 0.7773437500, 0.8007812500, 0.4882812500, 0.6210937500, 0.7304687500, 0.1914062500, 0.1132812500, 0.6132812500, 0.4414062500, 0.5039062500, 0.1523437500, 0.8867187500 },
  { 0.1992187500, 0.0195312500, 0.7304687500, 0.2539062500, 0.4648437500, 0.9882812500, 0.6757812500, 0.8085937500, 0.9179687500, 0.5039062500, 0.0507812500, 0.6757812500, 0.1289062500, 0.0664062500, 0.8398437500, 0.1992187500 },
  { 0.6992187500, 0.5195312500, 0.2304687500, 0.7539062500, 0.9648437500, 0.4882812500, 0.1757812500, 0.3085937500, 0.4179687500, 0.0039062500, 0.5507812500, 0.1757812500, 0.6289062500, 0.5664062500, 0.3398437500, 0.6992187500 },
  { 0.9492187500, 0.2695312500, 0.9804687500, 0.0039062500, 0.7148437500, 0.2382812500, 0.9257812500, 0.0585937500, 0.1679687500, 0.2539062500, 0.8007812500, 0.4257812500, 0.3789062500, 0.3164062500, 0.0898437500, 0.4492187500 },
  { 0.4492187500, 0.7695312500, 0.4804687500, 0.5039062500, 0.2148437500, 0.7382812500, 0.4257812500, 0.5585937500, 0.6679687500, 0.7539062500, 0.3007812500, 0.9257812500, 0.8789062500, 0.8164062500, 0.5898437500, 0.9492187500 },
  { 0.3242187500, 0.3945312500, 0.1054687500, 0.6289062500, 0.0898437500, 0.8632812500, 0.8007812500, 0.1835937500, 0.0429687500, 0.1289062500, 0.9257812500, 0.8007812500, 0.2539062500, 0.6914062500, 0.7148437500, 0.8242187500 },
  { 0.8242187500, 0.8945312500, 0.6054687500, 0.1289062500, 0.5898437500, 0.3632812500, 0.3007812500, 0.6835937500, 0.5429687500, 0.6289062500, 0.4257812500, 0.3007812500, 0.7539062500, 0.1914062500, 0.2148437500, 0.3242187500 },
  { 0.5742187500, 0.1445312500, 0.3554687500, 0.8789062500, 0.8398437500, 0.1132812500, 0.5507812500, 0.9335937500, 0.7929687500, 0.8789062500, 0.1757812500, 0.0507812500, 0.0039062500, 0.9414062500, 0.4648437500, 0.5742187500 },
  { 0.0742187500, 0.6445312500, 0.8554687500, 0.3789062500, 0.3398437500, 0.6132812500, 0.0507812500, 0.4335937500, 0.2929687500, 0.3789062500, 0.6757812500, 0.5507812500, 0.5039062500, 0.4414062500, 0.9648437500, 0.0742187500 },
  { 0.1054687500, 0.1757812500, 0.1992187500, 0.5976562500, 0.6835937500, 0.3320312500, 0.3320312500, 0.9023437500, 0.3867187500, 0.9726562500, 0.6445312500, 0.8320312500, 0.4726562500, 0.2851562500, 0.3710937500, 0.7929687500 },
  { 0.6054687500, 0.6757812500, 0.6992187500, 0.0976562500, 0.1835937500, 0.8320312500, 0.8320312500, 0.4023437500, 0.8867187500, 0.4726562500, 0.1445312500, 0.3320312500, 0.9726562500, 0.7851562500, 0.8710937500, 0.2929687500 },
  { 0.8554687500, 0.4257812500, 0.4492187500, 0.8476562500, 0.4335937500, 0.5820312500, 0.0820312500, 0.1523437500, 0.6367187500, 0.2226562500, 0.3945312500, 0.0820312500, 0.2226562500, 0.0351562500, 0.6210937500, 0.5429687500 },
  { 0.3554687500, 0.9257812500, 0.9492187500, 0.3476562500, 0.9335937500, 0.0820312500, 0.5820312500, 0.6523437500, 0.1367187500, 0.7226562500, 0.8945312500, 0.5820312500, 0.7226562500, 0.5351562500, 0.1210937500, 0.0429687500 },
  { 0.4804687500, 0.3007812500, 0.5742187500, 0.4726562500, 0.8085937500, 0.4570312500, 0.2070312500, 0.0273437500, 0.5117187500, 0.3476562500, 0.2695312500, 0.7070312500, 0.0976562500, 0.9101562500, 0.2460937500, 0.1679687500 },
  { 0.9804687500, 0.8007812500, 0.0742187500, 0.9726562500, 0.3085937500, 0.9570312500, 0.7070312500, 0.5273437500, 0.0117187500, 0.8476562500, 0.7695312500, 0.2070312500, 0.5976562500, 0.4101562500, 0.7460937500, 0.6679687500 },
  { 0.7304687500, 0.0507812500, 0.8242187500, 0.2226562500, 0.0585937500, 0.7070312500, 0.4570312500, 0.7773437500, 0.2617187500, 0.5976562500, 0.5195312500, 0.4570312500, 0.3476562500, 0.6601562500, 0.9960937500, 0.4179687500 },
  { 0.2304687500, 0.5507812500, 0.3242187500, 0.7226562500, 0.5585937500, 0.2070312500, 0.9570312500, 0.2773437500, 0.7617187500, 0.0976562500, 0.0195312500, 0.9570312500, 0.8476562500, 0.1601562500, 0.4960937500, 0.9179687500 },
  { 0.1679687500, 0.4882812500, 0.7617187500, 0.9101562500, 0.2460937500, 0.0195312500, 0.1445312500, 0.0898437500, 0.5742187500, 0.6601562500, 0.0820312500, 0.7695312500, 0.5351562500, 0.7226562500, 0.5585937500, 0.2304687500 },
  { 0.6679687500, 0.9882812500, 0.2617187500, 0.4101562500, 0.7460937500, 0.5195312500, 0.6445312500, 0.5898437500, 0.0742187500, 0.1601562500, 0.5820312500, 0.2695312500, 0.0351562500, 0.2226562500, 0.0585937500, 0.7304687500 },
  { 0.9179687500, 0.2382812500, 0.5117187500, 0.6601562500, 0.9960937500, 0.7695312500, 0.3945312500, 0.8398437500, 0.3242187500, 0.4101562500, 0.8320312500, 0.0195312500, 0.7851562500, 0.9726562500, 0.3085937500, 0.4804687500 },
  { 0.4179687500, 0.7382812500, 0.0117187500, 0.1601562500, 0.4960937500, 0.2695312500, 0.8945312500, 0.3398437500, 0.8242187500, 0.9101562500, 0.3320312500, 0.5195312500, 0.2851562500, 0.4726562500, 0.8085937500, 0.9804687500 },
  { 0.2929687500, 0.1132812500, 0.3867187500, 0.0351562500, 0.3710937500, 0.1445312500, 0.2695312500, 0.9648437500, 0.4492187500, 0.0351562500, 0.9570312500, 0.6445312500, 0.9101562500, 0.0976562500, 0.9335937500, 0.8554687500 },
  { 0.7929687500, 0.6132812500, 0.8867187500, 0.5351562500, 0.8710937500, 0.6445312500, 0.7695312500, 0.4648437500, 0.9492187500, 0.5351562500, 0.4570312500, 0.1445312500, 0.4101562500, 0.5976562500, 0.4335937500, 0.3554687500 },
  { 0.5429687500, 0.3632812500, 0.1367187500, 0.2851562500, 0.6210937500, 0.8945312500, 0.0195312500, 0.2148437500, 0.6992187500, 0.7851562500, 0.2070312500, 0.3945312500, 0.6601562500, 0.3476562500, 0.1835937500, 0.6054687500 },
  { 0.0429687500, 0.8632812500, 0.6367187500, 0.7851562500, 0.1210937500, 0.3945312500, 0.5195312500, 0.7148437500, 0.1992187500, 0.2851562500, 0.7070312500, 0.8945312500, 0.1601562500, 0.8476562500, 0.6835937500, 0.1054687500 },
  { 0.0585937500, 0.0664062500, 0.9960937500, 0.7382812500, 0.7617187500, 0.2539062500, 0.0664062500, 0.5742187500, 0.9023437500, 0.8632812500, 0.8476562500, 0.2851562500, 0.6445312500, 0.1132812500, 0.9804687500, 0.8710937500 },
  { 0.5585937500, 0.5664062500, 0.4960937500, 0.2382812500, 0.2617187500, 0.7539062500, 0.5664062500, 0.0742187500, 0.4023437500, 0.3632812500, 0.3476562500, 0.7851562500, 0.1445312500, 0.6132812500, 0.4804687500, 0.3710937500 },
  { 0.8085937500, 0.3164062500, 0.7460937500, 0.9882812500, 0.0117187500, 0.5039062500, 0.3164062500, 0.3242187500, 0.1523437500, 0.1132812500, 0.0976562500, 0.5351562500, 0.8945312500, 0.3632812500, 0.2304687500, 0.6210937500 },
  { 0.3085937500, 0.8164062500, 0.2460937500, 0.4882812500, 0.5117187500, 0.0039062500, 0.8164062500, 0.8242187500, 0.6523437500, 0.6132812500, 0.5976562500, 0.0351562500, 0.3945312500, 0.8632812500, 0.7304687500, 0.1210937500 },
  { 0.4335937500, 0.4414062500, 0.3710937500, 0.3632812500, 0.6367187500, 0.3789062500, 0.4414062500, 0.4492187500, 0.0273437500, 0.4882812500, 0.2226562500, 0.1601562500, 0.7695312500, 0.7382812500, 0.6054687500, 0.2460937500 },
  { 0.9335937500, 0.9414062500, 0.8710937500, 0.8632812500, 0.1367187500, 0.8789062500, 0.9414062500, 0.9492187500, 0.5273437500, 0.9882812500, 0.7226562500, 0.6601562500, 0.2695312500, 0.2382812500, 0.1054687500, 0.7460937500 },
  { 0.6835937500, 0.1914062500, 0.1210937500, 0.1132812500, 0.3867187500, 0.6289062500, 0.1914062500, 0.6992187500, 0.7773437500, 0.7382812500, 0.9726562500, 0.9101562500, 0.5195312500, 0.9882812500, 0.3554687500, 0.4960937500 },
  { 0.1835937500, 0.6914062500, 0.6210937500, 0.6132812500, 0.8867187500, 0.1289062500, 0.6914062500, 0.1992187500, 0.2773437500, 0.2382812500, 0.4726562500, 0.4101562500, 0.0195312500, 0.4882812500, 0.8554687500, 0.9960937500 },
  { 0.2460937500, 0.2539062500, 0.0585937500, 0.8007812500, 0.3242187500, 0.0664062500, 0.3789062500, 0.3867187500, 0.0898437500, 0.5507812500, 0.4101562500, 0.3476562500, 0.3320312500, 0.9257812500, 0.1679687500, 0.1835937500 },
  { 0.7460937500, 0.7539062500, 0.5585937500, 0.3007812500, 0.8242187500, 0.5664062500, 0.8789062500, 0.8867187500, 0.5898437500, 0.0507812500, 0.9101562500, 0.8476562500, 0.8320312500, 0.4257812500, 0.6679687500, 0.6835937500 },
  { 0.9960937500, 0.0039062500, 0.3085937500, 0.5507812500, 0.5742187500, 0.8164062500, 0.1289062500, 0.6367187500, 0.8398437500, 0.3007812500, 0.6601562500, 0.5976562500, 0.0820312500, 0.6757812500, 0.9179687500, 0.4335937500 },
  { 0.4960937500, 0.5039062500, 0.8085937500, 0.0507812500, 0.0742187500, 0.3164062500, 0.6289062500, 0.1367187500, 0.3398437500, 0.8007812500, 0.1601562500, 0.0976562500, 0.5820312500, 0.1757812500, 0.4179687500, 0.9335937500 },
  { 0.3710937500, 0.1289062500, 0.6835937500, 0.1757812500, 0.1992187500, 0.1914062500, 0.0039062500, 0.5117187500, 0.9648437500, 0.1757812500, 0.5351562500, 0.2226562500, 0.2070312500, 0.3007812500, 0.2929687500, 0.8085937500 },
  { 0.8710937500, 0.6289062500, 0.1835937500, 0.6757812500, 0.6992187500, 0.6914062500, 0.5039062500, 0.0117187500, 0.4648437500, 0.6757812500, 0.0351562500, 0.7226562500, 0.7070312500, 0.8007812500, 0.7929687500, 0.3085937500 },
  { 0.6210937500, 0.3789062500, 0.9335937500, 0.4257812500, 0.9492187500, 0.9414062500, 0.2539062500, 0.2617187500, 0.2148437500, 0.9257812500, 0.2851562500, 0.9726562500, 0.4570312500, 0.0507812500, 0.5429687500, 0.5585937500 },
  { 0.1210937500, 0.8789062500, 0.4335937500, 0.9257812500, 0.4492187500, 0.4414062500, 0.7539062500, 0.7617187500, 0.7148437500, 0.4257812500, 0.7851562500, 0.4726562500, 0.9570312500, 0.5507812500, 0.0429687500, 0.0585937500 },
  { 0.0898437500, 0.4101562500, 0.5273437500, 0.0820312500, 0.5429687500, 0.7226562500, 0.5976562500, 0.2929687500, 0.6210937500, 0.9570312500, 0.7539062500, 0.1289062500, 0.0507812500, 0.7070312500, 0.6367187500, 0.8398437500 },
  { 0.5898437500, 0.9101562500, 0.0273437500, 0.5820312500, 0.0429687500, 0.2226562500, 0.0976562500, 0.7929687500, 0.1210937500, 0.4570312500, 0.2539062500, 0.6289062500, 0.5507812500, 0.2070312500, 0.1367187500, 0.3398437500 },
  { 0.8398437500, 0.1601562500, 0.7773437500, 0.3320312500, 0.2929687500, 0.4726562500, 0.8476562500, 0.5429687500, 0.3710937500, 0.2070312500, 0.0039062500, 0.8789062500, 0.3007812500, 0.9570312500, 0.3867187500, 0.5898437500 },
  { 0.3398437500, 0.6601562500, 0.2773437500, 0.8320312500, 0.7929687500, 0.9726562500, 0.3476562500, 0.0429687500, 0.8710937500, 0.7070312500, 0.5039062500, 0.3789062500, 0.8007812500, 0.4570312500, 0.8867187500, 0.0898437500 },
  { 0.4648437500, 0.0351562500, 0.1523437500, 0.9570312500, 0.9179687500, 0.5976562500, 0.9726562500, 0.6679687500, 0.4960937500, 0.3320312500, 0.1289062500, 0.2539062500, 0.4257812500, 0.0820312500, 0.7617187500, 0.2148437500 },
  { 0.9648437500, 0.5351562500, 0.6523437500, 0.4570312500, 0.4179687500, 0.0976562500, 0.4726562500, 0.1679687500, 0.9960937500, 0.8320312500, 0.6289062500, 0.7539062500, 0.9257812500, 0.5820312500, 0.2617187500, 0.7148437500 },
  { 0.7148437500, 0.2851562500, 0.4023437500, 0.7070312500, 0.1679687500, 0.3476562500, 0.7226562500, 0.4179687500, 0.7460937500, 0.5820312500, 0.8789062500, 0.5039062500, 0.1757812500, 0.3320312500, 0.0117187500, 0.4648437500 },
  { 0.2148437500, 0.7851562500, 0.9023437500, 0.2070312500, 0.6679687500, 0.8476562500, 0.2226562500, 0.9179687500, 0.2460937500, 0.0820312500, 0.3789062500, 0.0039062500, 0.6757812500, 0.8320312500, 0.5117187500, 0.9648437500 },
  { 0.1523437500, 0.2226562500, 0.4648437500, 0.3945312500, 0.1054687500, 0.9101562500, 0.9101562500, 0.7304687500, 0.4335937500, 0.6445312500, 0.4414062500, 0.1914062500, 0.9882812500, 0.2695312500, 0.4492187500, 0.1523437500 },
  { 0.6523437500, 0.7226562500, 0.9648437500, 0.8945312500, 0.6054687500, 0.4101562500, 0.4101562500, 0.2304687500, 0.9335937500, 0.1445312500, 0.9414062500, 0.6914062500, 0.4882812500, 0.7695312500, 0.9492187500, 0.6523437500 },
  { 0.9023437500, 0.4726562500, 0.2148437500, 0.1445312500, 0.8554687500, 0.1601562500, 0.6601562500, 0.4804687500, 0.6835937500, 0.3945312500, 0.6914062500, 0.9414062500, 0.7382812500, 0.0195312500, 0.6992187500, 0.4023437500 },
  { 0.4023437500, 0.9726562500, 0.7148437500, 0.6445312500, 0.3554687500, 0.6601562500, 0.1601562500, 0.9804687500, 0.1835937500, 0.8945312500, 0.1914062500, 0.4414062500, 0.2382812500, 0.5195312500, 0.1992187500, 0.9023437500 },
  { 0.2773437500, 0.3476562500, 0.8398437500, 0.5195312500, 0.4804687500, 0.7851562500, 0.5351562500, 0.3554687500, 0.5585937500, 0.0195312500, 0.5664062500, 0.3164062500, 0.6132812500, 0.8945312500, 0.0742187500, 0.7773437500 },
  { 0.7773437500, 0.8476562500, 0.3398437500, 0.0195312500, 0.9804687500, 0.2851562500, 0.0351562500, 0.8554687500, 0.0585937500, 0.5195312500, 0.0664062500, 0.8164062500, 0.1132812500, 0.3945312500, 0.5742187500, 0.2773437500 },
  { 0.5273437500, 0.0976562500, 0.5898437500, 0.7695312500, 0.7304687500, 0.0351562500, 0.7851562500, 0.6054687500, 0.3085937500, 0.7695312500, 0.3164062500, 0.5664062500, 0.8632812500, 0.6445312500, 0.8242187500, 0.5273437500 },
  { 0.0273437500, 0.5976562500, 0.0898437500, 0.2695312500, 0.2304687500, 0.5351562500, 0.2851562500, 0.1054687500, 0.8085937500, 0.2695312500, 0.8164062500, 0.0664062500, 0.3632812500, 0.1445312500, 0.3242187500, 0.0273437500 },
  { 0.0195312500, 0.1992187500, 0.5976562500, 0.9023437500, 0.2539062500, 0.8710937500, 0.4648437500, 0.0351562500, 0.6445312500, 0.8085937500, 0.3085937500, 0.5273437500, 0.7460937500, 0.4023437500, 0.7851562500, 0.2539062500 },
  { 0.5195312500, 0.6992187500, 0.0976562500, 0.4023437500, 0.7539062500, 0.3710937500, 0.9648437500, 0.5351562500, 0.1445312500, 0.3085937500, 0.8085937500, 0.0273437500, 0.2460937500, 0.9023437500, 0.2851562500, 0.7539062500 },
  { 0.7695312500, 0.4492187500, 0.8476562500, 0.6523437500, 0.5039062500, 0.1210937500, 0.2148437500, 0.7851562500, 0.3945312500, 0.0585937500, 0.5585937500, 0.2773437500, 0.9960937500, 0.1523437500, 0.0351562500, 0.0039062500 },
  { 0.2695312500, 0.9492187500, 0.3476562500, 0.1523437500, 0.0039062500, 0.6210937500, 0.7148437500, 0.2851562500, 0.8945312500, 0.5585937500, 0.0585937500, 0.7773437500, 0.4960937500, 0.6523437500, 0.5351562500, 0.5039062500 },
  { 0.3945312500, 0.3242187500, 0.2226562500, 0.0273437500, 0.1289062500, 0.9960937500, 0.0898437500, 0.9101562500, 0.2695312500, 0.4335937500, 0.6835937500, 0.9023437500, 0.8710937500, 0.7773437500, 0.6601562500, 0.6289062500 },
  { 0.8945312500, 0.8242187500, 0.7226562500, 0.5273437500, 0.6289062500, 0.4960937500, 0.5898437500, 0.4101562500, 0.7695312500, 0.9335937500, 0.1835937500, 0.4023437500, 0.3710937500, 0.2773437500, 0.1601562500, 0.1289062500 },
  { 0.6445312500, 0.0742187500, 0.4726562500, 0.2773437500, 0.8789062500, 0.2460937500, 0.3398437500, 0.1601562500, 0.5195312500, 0.6835937500, 0.4335937500, 0.1523437500, 0.6210937500, 0.5273437500, 0.4101562500, 0.8789062500 },
  { 0.1445312500, 0.5742187500, 0.9726562500, 0.7773437500, 0.3789062500, 0.7460937500, 0.8398437500, 0.6601562500, 0.0195312500, 0.1835937500, 0.9335937500, 0.6523437500, 0.1210937500, 0.0273437500, 0.9101562500, 0.3789062500 },
  { 0.2070312500, 0.3867187500, 0.4101562500, 0.5898437500, 0.8164062500, 0.5585937500, 0.0273437500, 0.9726562500, 0.3320312500, 0.6210937500, 0.9960937500, 0.5898437500, 0.3085937500, 0.5898437500, 0.0976562500, 0.6914062500 },
  { 0.7070312500, 0.8867187500, 0.9101562500, 0.0898437500, 0.3164062500, 0.0585937500, 0.5273437500, 0.4726562500, 0.8320312500, 0.1210937500, 0.4960937500, 0.0898437500, 0.8085937500, 0.0898437500, 0.5976562500, 0.1914062500 },
  { 0.9570312500, 0.1367187500, 0.1601562500, 0.8398437500, 0.0664062500, 0.3085937500, 0.2773437500, 0.2226562500, 0.5820312500, 0.3710937500, 0.2460937500, 0.3398437500, 0.0585937500, 0.8398437500, 0.8476562500, 0.9414062500 },
  { 0.4570312500, 0.6367187500, 0.6601562500, 0.3398437500, 0.5664062500, 0.8085937500, 0.7773437500, 0.7226562500, 0.0820312500, 0.8710937500, 0.7460937500, 0.8398437500, 0.5585937500, 0.3398437500, 0.3476562500, 0.4414062500 },
  { 0.3320312500, 0.0117187500, 0.7851562500, 0.4648437500, 0.6914062500, 0.6835937500, 0.4023437500, 0.0976562500, 0.7070312500, 0.2460937500, 0.1210937500, 0.9648437500, 0.1835937500, 0.2148437500, 0.4726562500, 0.3164062500 },
  { 0.8320312500, 0.5117187500, 0.2851562500, 0.9648437500, 0.1914062500, 0.1835937500, 0.9023437500, 0.5976562500, 0.2070312500, 0.7460937500, 0.6210937500, 0.4648437500, 0.6835937500, 0.7148437500, 0.9726562500, 0.8164062500 },
  { 0.5820312500, 0.2617187500, 0.5351562500, 0.2148437500, 0.4414062500, 0.4335937500, 0.1523437500, 0.8476562500, 0.4570312500, 0.9960937500, 0.8710937500, 0.2148437500, 0.4335937500, 0.4648437500, 0.7226562500, 0.0664062500 },
  { 0.0820312500, 0.7617187500, 0.0351562500, 0.7148437500, 0.9414062500, 0.9335937500, 0.6523437500, 0.3476562500, 0.9570312500, 0.4960937500, 0.3710937500, 0.7148437500, 0.9335937500, 0.9648437500, 0.2226562500, 0.5664062500 },
  { 0.1132812500, 0.2929687500, 0.8789062500, 0.3085937500, 0.0351562500, 0.1523437500, 0.9960937500, 0.8164062500, 0.8632812500, 0.9023437500, 0.3398437500, 0.9335937500, 0.0898437500, 0.8085937500, 0.5664062500, 0.2851562500 },
  { 0.6132812500, 0.7929687500, 0.3789062500, 0.8085937500, 0.5351562500, 0.6523437500, 0.4960937500, 0.3164062500, 0.3632812500, 0.4023437500, 0.8398437500, 0.4335937500, 0.5898437500, 0.3085937500, 0.0664062500, 0.7851562500 },
  { 0.8632812500, 0.0429687500, 0.6289062500, 0.0585937500, 0.7851562500, 0.9023437500, 0.7460937500, 0.0664062500, 0.1132812500, 0.1523437500, 0.5898437500, 0.1835937500, 0.3398437500, 0.5585937500, 0.3164062500, 0.0351562500 },
  { 0.3632812500, 0.5429687500, 0.1289062500, 0.5585937500, 0.2851562500, 0.4023437500, 0.2460937500, 0.5664062500, 0.6132812500, 0.6523437500, 0.0898437500, 0.6835937500, 0.8398437500, 0.0585937500, 0.8164062500, 0.5351562500 },
  { 0.4882812500, 0.1679687500, 0.2539062500, 0.6835937500, 0.4101562500, 0.0273437500, 0.6210937500, 0.1914062500, 0.2382812500, 0.2773437500, 0.7148437500, 0.5585937500, 0.4648437500, 0.4335937500, 0.9414062500, 0.6601562500 },
  { 0.9882812500, 0.6679687500, 0.7539062500, 0.1835937500, 0.9101562500, 0.5273437500, 0.1210937500, 0.6914062500, 0.7382812500, 0.7773437500, 0.2148437500, 0.0585937500, 0.9648437500, 0.9335937500, 0.4414062500, 0.1601562500 },
  { 0.7382812500, 0.4179687500, 0.0039062500, 0.9335937500, 0.6601562500, 0.7773437500, 0.8710937500, 0.9414062500, 0.9882812500, 0.5273437500, 0.4648437500, 0.3085937500, 0.2148437500, 0.1835937500, 0.1914062500, 0.9101562500 },
  { 0.2382812500, 0.9179687500, 0.5039062500, 0.4335937500, 0.1601562500, 0.2773437500, 0.3710937500, 0.4414062500, 0.4882812500, 0.0273437500, 0.9648437500, 0.8085937500, 0.7148437500, 0.6835937500, 0.6914062500, 0.4101562500 },
  { 0.1757812500, 0.1054687500, 0.0664062500, 0.2460937500, 0.5976562500, 0.4648437500, 0.5585937500, 0.1289062500, 0.1757812500, 0.7148437500, 0.9023437500, 0.9960937500, 0.9023437500, 0.2460937500, 0.2539062500, 0.7226562500 },
  { 0.6757812500, 0.6054687500, 0.5664062500, 0.7460937500, 0.0976562500, 0.9648437500, 0.0585937500, 0.6289062500, 0.6757812500, 0.2148437500, 0.4023437500, 0.4960937500, 0.4023437500, 0.7460937500, 0.7539062500, 0.2226562500 },
  { 0.9257812500, 0.3554687500, 0.3164062500, 0.4960937500, 0.3476562500, 0.7148437500, 0.8085937500, 0.8789062500, 0.9257812500, 0.4648437500, 0.1523437500, 0.2460937500, 0.6523437500, 0.4960937500, 0.5039062500, 0.9726562500 },
  { 0.4257812500, 0.8554687500, 0.8164062500, 0.9960937500, 0.8476562500, 0.2148437500, 0.3085937500, 0.3789062500, 0.4257812500, 0.9648437500, 0.6523437500, 0.7460937500, 0.1523437500, 0.9960937500, 0.0039062500, 0.4726562500 },
  { 0.3007812500, 0.4804687500, 0.6914062500, 0.8710937500, 0.9726562500, 0.3398437500, 0.9335937500, 0.7539062500, 0.8007812500, 0.0898437500, 0.0273437500, 0.6210937500, 0.5273437500, 0.6210937500, 0.1289062500, 0.3476562500 },
  { 0.8007812500, 0.9804687500, 0.1914062500, 0.3710937500, 0.4726562500, 0.8398437500, 0.4335937500, 0.2539062500, 0.3007812500, 0.5898437500, 0.5273437500, 0.1210937500, 0.0273437500, 0.1210937500, 0.6289062500, 0.8476562500 },
  { 0.5507812500, 0.2304687500, 0.9414062500, 0.6210937500, 0.2226562500, 0.5898437500, 0.6835937500, 0.0039062500, 0.0507812500, 0.8398437500, 0.7773437500, 0.3710937500, 0.7773437500, 0.8710937500, 0.8789062500, 0.0976562500 },
  { 0.0507812500, 0.7304687500, 0.4414062500, 0.1210937500, 0.7226562500, 0.0898437500, 0.1835937500, 0.5039062500, 0.5507812500, 0.3398437500, 0.2773437500, 0.8710937500, 0.2773437500, 0.3710937500, 0.3789062500, 0.5976562500 },
  { 0.0351562500, 0.4648437500, 0.1757812500, 0.4179687500, 0.3945312500, 0.1992187500, 0.7304687500, 0.6445312500, 0.3476562500, 0.7617187500, 0.1679687500, 0.4492187500, 0.7929687500, 0.6054687500, 0.2070312500, 0.3632812500 },
  { 0.5351562500, 0.9648437500, 0.6757812500, 0.9179687500, 0.8945312500, 0.6992187500, 0.2304687500, 0.1445312500, 0.8476562500, 0.2617187500, 0.6679687500, 0.9492187500, 0.2929687500, 0.1054687500, 0.7070312500, 0.8632812500 },
  { 0.7851562500, 0.2148437500, 0.4257812500, 0.1679687500, 0.6445312500, 0.9492187500, 0.9804687500, 0.3945312500, 0.5976562500, 0.0117187500, 0.9179687500, 0.6992187500, 0.5429687500, 0.8554687500, 0.9570312500, 0.1132812500 },
  { 0.2851562500, 0.7148437500, 0.9257812500, 0.6679687500, 0.1445312500, 0.4492187500, 0.4804687500, 0.8945312500, 0.0976562500, 0.5117187500, 0.4179687500, 0.1992187500, 0.0429687500, 0.3554687500, 0.4570312500, 0.6132812500 }
};


QRNG_VALIDATION_TEST_FUNCTIONS(sobol)
QRNG_VALIDATION_TEST_DISCARD(sobol)

BOOST_AUTO_TEST_CASE( check_generator_limits )
{
  test_sobol_max_seed();
  test_sobol_max_discard();
  test_sobol_max_dimension(BOOST_RANDOM_SOBOL_MAX_DIMENSION);
}

BOOST_AUTO_TEST_CASE( validate_sobol )
{
  test_sobol_values(sobol_02_99, 0);
  test_sobol_values(sobol_07_100, 127);
  test_sobol_values(sobol_16_100, 127);
}

BOOST_AUTO_TEST_CASE( validate_sobol_seed )
{
  test_sobol_seed(sobol_02_99, 0);
  test_sobol_seed(sobol_07_100, 127);
  test_sobol_seed(sobol_16_100, 127);
}

BOOST_AUTO_TEST_CASE( validate_sobol_discard )
{
  test_sobol_discard(sobol_02_99, 0);
  test_sobol_discard(sobol_07_100, 127);
  test_sobol_discard(sobol_16_100, 127);
}

