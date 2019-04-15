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


namespace Botan {

/*
* DH_PublicKey Constructor
*/
DH_PublicKey::DH_PublicKey(const DL_Group& grp, const BigInt& y1)
   {
   m_group = grp;
   m_y = y1;
   }

/*
* Return the public value for key agreement
*/
std::vector<uint8_t> DH_PublicKey::public_value() const
   {
   return unlock(BigInt::encode_1363(m_y, group_p().bytes()));
   }

/*
* Create a DH private key
*/
DH_PrivateKey::DH_PrivateKey(RandomNumberGenerator& rng,
                             const DL_Group& grp,
                             const BigInt& x_arg)
   {
   m_group = grp;

   if(x_arg == 0)
      {
      const size_t exp_bits = grp.exponent_bits();
      m_x.randomize(rng, exp_bits);
      m_y = m_group.power_g_p(m_x, exp_bits);
      }
   else
      {
      m_x = x_arg;

      if(m_y == 0)
         m_y = m_group.power_g_p(m_x, grp.p_bits());
      }
   }

/*
* Load a DH private key
*/
DH_PrivateKey::DH_PrivateKey(const AlgorithmIdentifier& alg_id,
                             const secure_vector<uint8_t>& key_bits) :
   DL_Scheme_PrivateKey(alg_id, key_bits, DL_Group::ANSI_X9_42)
   {
   if(m_y.is_zero())
      {
      m_y = m_group.power_g_p(m_x, m_group.p_bits());
      }
   }

/*
* Return the public value for key agreement
*/
std::vector<uint8_t> DH_PrivateKey::public_value() const
   {
   return DH_PublicKey::public_value();
   }

namespace {

/**
* DH operation
*/
class DH_KA_Operation final : public PK_Ops::Key_Agreement_with_KDF
   {
   public:

      DH_KA_Operation(const DH_PrivateKey& key, const std::string& kdf, RandomNumberGenerator& rng) :
         PK_Ops::Key_Agreement_with_KDF(kdf),
         m_p(key.group_p()),
         m_powermod_x_p(key.get_x(), m_p),
         m_blinder(m_p,
                   rng,
                   [](const BigInt& k) { return k; },
                   [this](const BigInt& k) { return m_powermod_x_p(inverse_mod(k, m_p)); })
         {}

      size_t agreed_value_size() const override { return m_p.bytes(); }

      secure_vector<uint8_t> raw_agree(const uint8_t w[], size_t w_len) override;
   private:
      const BigInt& m_p;

      Fixed_Exponent_Power_Mod m_powermod_x_p;
      Blinder m_blinder;
   };

secure_vector<uint8_t> DH_KA_Operation::raw_agree(const uint8_t w[], size_t w_len)
   {
   BigInt v = BigInt::decode(w, w_len);

   if(v <= 1 || v >= m_p - 1)
      throw Invalid_Argument("DH agreement - invalid key provided");

   v = m_blinder.blind(v);
   v = m_powermod_x_p(v);
   v = m_blinder.unblind(v);

   return BigInt::encode_1363(v, m_p.bytes());
   }

}

std::unique_ptr<PK_Ops::Key_Agreement>
DH_PrivateKey::create_key_agreement_op(RandomNumberGenerator& rng,
                                       const std::string& params,
                                       const std::string& provider) const
   {
   if(provider == "base" || provider.empty())
      return std::unique_ptr<PK_Ops::Key_Agreement>(new DH_KA_Operation(*this, params, rng));
   throw Provider_Not_Found(algo_name(), provider);
   }

}
/*
* DL Scheme
* (C) 1999-2007 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
