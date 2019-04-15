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


#if defined(BOTAN_HAS_GCM_CLMUL)
#endif

#if defined(BOTAN_HAS_GCM_CLMUL_SSSE3)
#endif

#if defined(BOTAN_HAS_GCM_PMULL)
#endif

namespace Botan {

std::string GHASH::provider() const
   {
#if defined(BOTAN_HAS_GCM_CLMUL)
   if(CPUID::has_clmul())
      return "clmul";
#endif

#if defined(BOTAN_HAS_GCM_CLMUL_SSSE3)
   if(CPUID::has_ssse3())
      return "ssse3";
#endif

#if defined(BOTAN_HAS_GCM_PMULL)
   if(CPUID::has_arm_pmull())
      return "pmull";
#endif

   return "base";
   }

void GHASH::gcm_multiply(secure_vector<uint8_t>& x,
                         const uint8_t input[],
                         size_t blocks)
   {
#if defined(BOTAN_HAS_GCM_CLMUL)
   if(CPUID::has_clmul())
      {
      return gcm_multiply_clmul(x.data(), m_H_pow.data(), input, blocks);
      }
#endif

#if defined(BOTAN_HAS_GCM_CLMUL_SSSE3)
   if(CPUID::has_ssse3())
      {
      return gcm_multiply_ssse3(x.data(), m_HM.data(), input, blocks);
      }
#endif

#if defined(BOTAN_HAS_GCM_PMULL)
   if(CPUID::has_arm_pmull())
      {
      return gcm_multiply_pmull(x.data(), m_H_pow.data(), input, blocks);
      }
#endif

   CT::poison(x.data(), x.size());

   const uint64_t ALL_BITS = 0xFFFFFFFFFFFFFFFF;

   uint64_t X[2] = {
      load_be<uint64_t>(x.data(), 0),
      load_be<uint64_t>(x.data(), 1)
   };

   for(size_t b = 0; b != blocks; ++b)
      {
      X[0] ^= load_be<uint64_t>(input, 2*b);
      X[1] ^= load_be<uint64_t>(input, 2*b+1);

      uint64_t Z[2] = { 0, 0 };

      for(size_t i = 0; i != 64; ++i)
         {
         const uint64_t X0MASK = (ALL_BITS + (X[0] >> 63)) ^ ALL_BITS;
         const uint64_t X1MASK = (ALL_BITS + (X[1] >> 63)) ^ ALL_BITS;

         X[0] <<= 1;
         X[1] <<= 1;

         Z[0] ^= m_HM[4*i  ] & X0MASK;
         Z[1] ^= m_HM[4*i+1] & X0MASK;
         Z[0] ^= m_HM[4*i+2] & X1MASK;
         Z[1] ^= m_HM[4*i+3] & X1MASK;
         }

      X[0] = Z[0];
      X[1] = Z[1];
      }

   store_be<uint64_t>(x.data(), X[0], X[1]);
   CT::unpoison(x.data(), x.size());
   }

void GHASH::ghash_update(secure_vector<uint8_t>& ghash,
                         const uint8_t input[], size_t length)
   {
   verify_key_set(m_HM.size());

   /*
   This assumes if less than block size input then we're just on the
   final block and should pad with zeros
   */

   const size_t full_blocks = length / GCM_BS;
   const size_t final_bytes = length - (full_blocks * GCM_BS);

   if(full_blocks > 0)
      {
      gcm_multiply(ghash, input, full_blocks);
      }

   if(final_bytes)
      {
      secure_vector<uint8_t> last_block(GCM_BS);
      copy_mem(last_block.data(), input + full_blocks * GCM_BS, final_bytes);
      gcm_multiply(ghash, last_block.data(), 1);
      }
   }

void GHASH::key_schedule(const uint8_t key[], size_t length)
   {
   m_H.assign(key, key+length);
   m_H_ad.resize(GCM_BS);
   m_ad_len = 0;
   m_text_len = 0;

   uint64_t H0 = load_be<uint64_t>(m_H.data(), 0);
   uint64_t H1 = load_be<uint64_t>(m_H.data(), 1);

   const uint64_t R = 0xE100000000000000;

   m_HM.resize(256);

   // precompute the multiples of H
   for(size_t i = 0; i != 2; ++i)
      {
      for(size_t j = 0; j != 64; ++j)
         {
         /*
         we interleave H^1, H^65, H^2, H^66, H3, H67, H4, H68
         to make indexing nicer in the multiplication code
         */
         m_HM[4*j+2*i] = H0;
         m_HM[4*j+2*i+1] = H1;

         // GCM's bit ops are reversed so we carry out of the bottom
         const uint64_t carry = R * (H1 & 1);
         H1 = (H1 >> 1) | (H0 << 63);
         H0 = (H0 >> 1) ^ carry;
         }
      }

#if defined(BOTAN_HAS_GCM_CLMUL)
   if(CPUID::has_clmul())
      {
      m_H_pow.resize(8);
      gcm_clmul_precompute(m_H.data(), m_H_pow.data());
      }
#endif

#if defined(BOTAN_HAS_GCM_PMULL)
   if(CPUID::has_arm_pmull())
      {
      m_H_pow.resize(8);
      gcm_pmull_precompute(m_H.data(), m_H_pow.data());
      }
#endif

   }

void GHASH::start(const uint8_t nonce[], size_t len)
   {
   BOTAN_ARG_CHECK(len == 16, "GHASH requires a 128-bit nonce");
   m_nonce.assign(nonce, nonce + len);
   m_ghash = m_H_ad;
   }

void GHASH::set_associated_data(const uint8_t input[], size_t length)
   {
   if(m_ghash.empty() == false)
      throw Invalid_State("Too late to set AD in GHASH");

   zeroise(m_H_ad);

   ghash_update(m_H_ad, input, length);
   m_ad_len = length;
   }

void GHASH::update_associated_data(const uint8_t ad[], size_t length)
   {
   verify_key_set(m_ghash.size() == GCM_BS);
   m_ad_len += length;
   ghash_update(m_ghash, ad, length);
   }

void GHASH::update(const uint8_t input[], size_t length)
   {
   verify_key_set(m_ghash.size() == GCM_BS);
   m_text_len += length;
   ghash_update(m_ghash, input, length);
   }

void GHASH::add_final_block(secure_vector<uint8_t>& hash,
                            size_t ad_len, size_t text_len)
   {
   /*
   * stack buffer is fine here since the text len is public
   * and the length of the AD is probably not sensitive either.
   */
   uint8_t final_block[GCM_BS];
   store_be<uint64_t>(final_block, 8*ad_len, 8*text_len);
   ghash_update(hash, final_block, GCM_BS);
   }

secure_vector<uint8_t> GHASH::final()
   {
   add_final_block(m_ghash, m_ad_len, m_text_len);

   secure_vector<uint8_t> mac;
   mac.swap(m_ghash);

   mac ^= m_nonce;
   m_text_len = 0;
   return mac;
   }

secure_vector<uint8_t> GHASH::nonce_hash(const uint8_t nonce[], size_t nonce_len)
   {
   BOTAN_ASSERT(m_ghash.size() == 0, "nonce_hash called during wrong time");
   secure_vector<uint8_t> y0(GCM_BS);

   ghash_update(y0, nonce, nonce_len);
   add_final_block(y0, 0, nonce_len);

   return y0;
   }

void GHASH::clear()
   {
   zap(m_H);
   zap(m_HM);
   reset();
   }

void GHASH::reset()
   {
   zeroise(m_H_ad);
   m_ghash.clear();
   m_nonce.clear();
   m_text_len = m_ad_len = 0;
   }

}
/*
 * GMAC
 * (C) 2016 Matthias Gierlings, René Korthaus
 * (C) 2017 Jack Lloyd
 *
 * Botan is released under the Simplified BSD License (see license.txt)
 */
