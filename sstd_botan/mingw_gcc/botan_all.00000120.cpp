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


#if defined(BOTAN_HAS_RDRAND_RNG)
#endif

extern "C" {

using namespace Botan_FFI;

int botan_rng_init(botan_rng_t* rng_out, const char* rng_type)
   {
   return ffi_guard_thunk(__func__, [=]() -> int {
      if(rng_out == nullptr)
         return BOTAN_FFI_ERROR_NULL_POINTER;

      const std::string rng_type_s(rng_type ? rng_type : "system");

      std::unique_ptr<Botan::RandomNumberGenerator> rng;

      if(rng_type_s == "system")
         {
         rng.reset(new Botan::System_RNG);
         }
      else if(rng_type_s == "user")
         {
         rng.reset(new Botan::AutoSeeded_RNG);
         }
      else if(rng_type_s == "null")
         {
         rng.reset(new Botan::Null_RNG);
         }
#if defined(BOTAN_HAS_RDRAND_RNG)
      else if(rng_type_s == "rdrand" && Botan::RDRAND_RNG::available())
         {
         rng.reset(new Botan::RDRAND_RNG);
         }
#endif
#if defined(BOTAN_TARGET_OS_HAS_THREADS)
      else if(rng_type_s == "user-threadsafe")
         {
         rng.reset(new Botan::Serialized_RNG(new Botan::AutoSeeded_RNG));
         }
#endif

      if(!rng)
         {
         return BOTAN_FFI_ERROR_NOT_IMPLEMENTED;
         }

      *rng_out = new botan_rng_struct(rng.release());
      return BOTAN_FFI_SUCCESS;
      });
   }

int botan_rng_destroy(botan_rng_t rng)
   {
   return BOTAN_FFI_CHECKED_DELETE(rng);
   }

int botan_rng_get(botan_rng_t rng, uint8_t* out, size_t out_len)
   {
   return BOTAN_FFI_DO(Botan::RandomNumberGenerator, rng, r, { r.randomize(out, out_len); });
   }

int botan_rng_reseed(botan_rng_t rng, size_t bits)
   {
   return BOTAN_FFI_DO(Botan::RandomNumberGenerator, rng, r, { r.reseed_from_rng(Botan::system_rng(), bits); });
   }

int botan_rng_add_entropy(botan_rng_t rng, const uint8_t* input, size_t len)
   {
   return BOTAN_FFI_DO(Botan::RandomNumberGenerator, rng, r, { r.add_entropy(input, len); });
   }

int botan_rng_reseed_from_rng(botan_rng_t rng, botan_rng_t source_rng, size_t bits)
   {
   return BOTAN_FFI_DO(Botan::RandomNumberGenerator, rng, r, { r.reseed_from_rng(safe_get(source_rng), bits); });
   }

}
/*
* (C) 2018 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
