﻿
#include "botan_all.h"
#include "botan_all_internal.h"

/*
* Adler32
* (C) 1999-2007 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include "botan_parts_detail.hpp"


#if !defined(BOTAN_USE_GCC_INLINE_ASM)
#endif

namespace Botan {

BOTAN_FUNC_ISA("rdseed")
size_t Intel_Rdseed::poll(RandomNumberGenerator& rng)
   {
   if(CPUID::has_rdseed())
      {
      for(size_t p = 0; p != BOTAN_ENTROPY_INTEL_RNG_POLLS; ++p)
         {
         for(size_t i = 0; i != BOTAN_ENTROPY_RDSEED_RETRIES; ++i)
            {
            uint32_t r = 0;

#if defined(BOTAN_USE_GCC_INLINE_ASM)
            int cf = 0;

            // Encoding of rdseed %eax
            asm(".byte 0x0F, 0xC7, 0xF8; adcl $0,%1" :
                "=a" (r), "=r" (cf) : "0" (r), "1" (cf) : "cc");
#else
            int cf = _rdseed32_step(&r);
#endif
            if(1 == cf)
               {
               rng.add_entropy_T(r);
               break;
               }
            }
         }
      }

   return 0;
   }

}
/*
* AES Key Wrap (RFC 3394)
* (C) 2011 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
