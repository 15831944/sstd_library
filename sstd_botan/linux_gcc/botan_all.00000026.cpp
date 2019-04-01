
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


namespace Botan {

namespace {

std::string bcrypt_base64_encode(const uint8_t input[], size_t length)
   {
   // Bcrypt uses a non-standard base64 alphabet
   const uint8_t OPENBSD_BASE64_SUB[256] = {
      0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x38, 0x80, 0x80, 0x80, 0x39,
      0x79, 0x7A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x2E, 0x2F, 0x41, 0x42, 0x43, 0x44, 0x45,
      0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
      0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x59, 0x5A, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
      0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75,
      0x76, 0x77, 0x78, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80
   };

   std::string b64 = base64_encode(input, length);

   while(b64.size() && b64[b64.size()-1] == '=')
      b64 = b64.substr(0, b64.size() - 1);

   for(size_t i = 0; i != b64.size(); ++i)
      b64[i] = OPENBSD_BASE64_SUB[static_cast<uint8_t>(b64[i])];

   return b64;
   }

std::vector<uint8_t> bcrypt_base64_decode(std::string input)
   {
   const uint8_t OPENBSD_BASE64_SUB[256] = {
      0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x41, 0x42,
      0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x2B, 0x2F, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
      0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
      0x56, 0x57, 0x58, 0x59, 0x5A, 0x61, 0x62, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D,
      0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
      0x7A, 0x30, 0x31, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80
   };

   for(size_t i = 0; i != input.size(); ++i)
      input[i] = OPENBSD_BASE64_SUB[static_cast<uint8_t>(input[i])];

   return unlock(base64_decode(input));
   }

std::string make_bcrypt(const std::string& pass,
                        const std::vector<uint8_t>& salt,
                        uint16_t work_factor,
                        char version)
   {
   /*
   * On a 4 GHz Skylake, workfactor == 18 takes about 15 seconds to
   * hash a password. This seems like a reasonable upper bound for the
   * time being.
   * Bcrypt allows up to work factor 31 (2^31 iterations)
   */
   BOTAN_ARG_CHECK(work_factor >= 4 && work_factor <= 18,
                   "Invalid bcrypt work factor");

   static const uint8_t BCRYPT_MAGIC[8*3] = {
      0x4F, 0x72, 0x70, 0x68, 0x65, 0x61, 0x6E, 0x42,
      0x65, 0x68, 0x6F, 0x6C, 0x64, 0x65, 0x72, 0x53,
      0x63, 0x72, 0x79, 0x44, 0x6F, 0x75, 0x62, 0x74
   };

   Blowfish blowfish;

   // Include the trailing NULL byte, so we need c_str() not data()
   blowfish.salted_set_key(cast_char_ptr_to_uint8(pass.c_str()),
                           pass.length() + 1,
                           salt.data(),
                           salt.size(),
                           work_factor);

   std::vector<uint8_t> ctext(BCRYPT_MAGIC, BCRYPT_MAGIC + 8*3);

   for(size_t i = 0; i != 64; ++i)
      blowfish.encrypt_n(ctext.data(), ctext.data(), 3);

   std::string salt_b64 = bcrypt_base64_encode(salt.data(), salt.size());

   std::string work_factor_str = std::to_string(work_factor);
   if(work_factor_str.length() == 1)
      work_factor_str = "0" + work_factor_str;

   return "$2" + std::string(1, version) + "$" + work_factor_str +
          "$" + salt_b64.substr(0, 22) +
          bcrypt_base64_encode(ctext.data(), ctext.size() - 1);
   }

}

std::string generate_bcrypt(const std::string& pass,
                            RandomNumberGenerator& rng,
                            uint16_t work_factor,
                            char version)
   {
   /*
   2a, 2b and 2y are identical for our purposes because our implementation of 2a
   never had the truncation or signed char bugs in the first place.
   */

   if(version != 'a' && version != 'b' && version != 'y')
      throw Invalid_Argument("Unknown bcrypt version '" + std::string(1, version) + "'");
   return make_bcrypt(pass, unlock(rng.random_vec(16)), work_factor, version);
   }

bool check_bcrypt(const std::string& pass, const std::string& hash)
   {
   if(hash.size() != 60 ||
      hash[0] != '$' || hash[1] != '2' || hash[3] != '$' || hash[6] != '$')
      {
      return false;
      }

   const char bcrypt_version = hash[2];

   if(bcrypt_version != 'a' && bcrypt_version != 'b' && bcrypt_version != 'y')
      {
      return false;
      }

   const uint16_t workfactor = to_uint16(hash.substr(4, 2));

   const std::vector<uint8_t> salt = bcrypt_base64_decode(hash.substr(7, 22));
   if(salt.size() != 16)
      return false;

   const std::string compare = make_bcrypt(pass, salt, workfactor, bcrypt_version);

   return same_mem(hash.data(), compare.data(), compare.size());
   }

}
/*
* BigInt Encoding/Decoding
* (C) 1999-2010,2012,2019 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
