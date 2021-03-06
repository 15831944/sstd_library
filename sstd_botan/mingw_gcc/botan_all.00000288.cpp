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


#if defined(BOTAN_HAS_CHACHA)
#endif

#if defined(BOTAN_HAS_SALSA20)
#endif

#if defined(BOTAN_HAS_SHAKE_CIPHER)
#endif

#if defined(BOTAN_HAS_CTR_BE)
#endif

#if defined(BOTAN_HAS_OFB)
#endif

#if defined(BOTAN_HAS_RC4)
#endif

#if defined(BOTAN_HAS_OPENSSL)
#endif

namespace Botan {

std::unique_ptr<StreamCipher> StreamCipher::create(const std::string& algo_spec,
                                                   const std::string& provider)
   {
   const SCAN_Name req(algo_spec);

#if defined(BOTAN_HAS_CTR_BE)
   if((req.algo_name() == "CTR-BE" || req.algo_name() == "CTR") && req.arg_count_between(1,2))
      {
      if(provider.empty() || provider == "base")
         {
         auto cipher = BlockCipher::create(req.arg(0));
         if(cipher)
            {
            size_t ctr_size = req.arg_as_integer(1, cipher->block_size());
            return std::unique_ptr<StreamCipher>(new CTR_BE(cipher.release(), ctr_size));
            }
         }
      }
#endif

#if defined(BOTAN_HAS_CHACHA)
   if(req.algo_name() == "ChaCha")
      {
      if(provider.empty() || provider == "base")
         return std::unique_ptr<StreamCipher>(new ChaCha(req.arg_as_integer(0, 20)));
      }

   if(req.algo_name() == "ChaCha20")
      {
      if(provider.empty() || provider == "base")
         return std::unique_ptr<StreamCipher>(new ChaCha(20));
      }
#endif

#if defined(BOTAN_HAS_SALSA20)
   if(req.algo_name() == "Salsa20")
      {
      if(provider.empty() || provider == "base")
         return std::unique_ptr<StreamCipher>(new Salsa20);
      }
#endif

#if defined(BOTAN_HAS_SHAKE_CIPHER)
   if(req.algo_name() == "SHAKE-128" || req.algo_name() == "SHAKE-128-XOF")
      {
      if(provider.empty() || provider == "base")
         return std::unique_ptr<StreamCipher>(new SHAKE_128_Cipher);
      }
#endif

#if defined(BOTAN_HAS_OFB)
   if(req.algo_name() == "OFB" && req.arg_count() == 1)
      {
      if(provider.empty() || provider == "base")
         {
         if(auto c = BlockCipher::create(req.arg(0)))
            return std::unique_ptr<StreamCipher>(new OFB(c.release()));
         }
      }
#endif

#if defined(BOTAN_HAS_RC4)

   if(req.algo_name() == "RC4" ||
      req.algo_name() == "ARC4" ||
      req.algo_name() == "MARK-4")
      {
      const size_t skip = (req.algo_name() == "MARK-4") ? 256 : req.arg_as_integer(0, 0);

#if defined(BOTAN_HAS_OPENSSL)
      if(provider.empty() || provider == "openssl")
         {
         return std::unique_ptr<StreamCipher>(make_openssl_rc4(skip));
         }
#endif

      if(provider.empty() || provider == "base")
         {
         return std::unique_ptr<StreamCipher>(new RC4(skip));
         }
      }

#endif

   BOTAN_UNUSED(req);
   BOTAN_UNUSED(provider);

   return nullptr;
   }

//static
std::unique_ptr<StreamCipher>
StreamCipher::create_or_throw(const std::string& algo,
                             const std::string& provider)
   {
   if(auto sc = StreamCipher::create(algo, provider))
      {
      return sc;
      }
   throw Lookup_Error("Stream cipher", algo, provider);
   }

std::vector<std::string> StreamCipher::providers(const std::string& algo_spec)
   {
   return probe_providers_of<StreamCipher>(algo_spec, {"base", "openssl"});
   }

}
/*
* Streebog
* (C) 2017 Ribose Inc.
* (C) 2018 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
