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

namespace TLS {

Certificate_Status::Certificate_Status(const std::vector<uint8_t>& buf)
   {
   if(buf.size() < 5)
      throw Decoding_Error("Invalid Certificate_Status message: too small");

   if(buf[0] != 1)
      throw Decoding_Error("Unexpected Certificate_Status message: unexpected message type");

   size_t len = make_uint32(0, buf[1], buf[2], buf[3]);

   // Verify the redundant length field...
   if(buf.size() != len + 4)
      throw Decoding_Error("Invalid Certificate_Status: invalid length field");

   m_response = std::make_shared<OCSP::Response>(buf.data() + 4, buf.size() - 4);
   }

Certificate_Status::Certificate_Status(Handshake_IO& io,
                                       Handshake_Hash& hash,
                                       std::shared_ptr<const OCSP::Response> ocsp) :
   m_response(ocsp)
   {
   hash.update(io.send(*this));
   }

std::vector<uint8_t> Certificate_Status::serialize() const
   {
   BOTAN_ASSERT_NONNULL(m_response);
   const std::vector<uint8_t>& m_resp_bits = m_response->raw_bits();

   if(m_resp_bits.size() > 0xFFFFFF) // unlikely
      throw Encoding_Error("OCSP response too long to encode in TLS");

   const uint32_t m_resp_bits_len = static_cast<uint32_t>(m_resp_bits.size());

   std::vector<uint8_t> buf;
   buf.push_back(1); // type OCSP
   for(size_t i = 1; i < 4; ++i)
      buf[i] = get_byte(i, m_resp_bits_len);

   buf += m_resp_bits;
   return buf;
   }

}

}
/*
* Certificate Verify Message
* (C) 2004,2006,2011,2012 Jack Lloyd
*     2017 Harry Reimann, Rohde & Schwarz Cybersecurity
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
