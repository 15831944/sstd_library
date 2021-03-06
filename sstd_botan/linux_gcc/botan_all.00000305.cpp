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

/**
* Create a new Certificate message
*/
Certificate::Certificate(Handshake_IO& io,
                         Handshake_Hash& hash,
                         const std::vector<X509_Certificate>& cert_list) :
   m_certs(cert_list)
   {
   hash.update(io.send(*this));
   }

/**
* Deserialize a Certificate message
*/
Certificate::Certificate(const std::vector<uint8_t>& buf, const Policy& /*policy_currently_unused*/)
   {
   if(buf.size() < 3)
      throw Decoding_Error("Certificate: Message malformed");

   const size_t total_size = make_uint32(0, buf[0], buf[1], buf[2]);

   if(total_size != buf.size() - 3)
      throw Decoding_Error("Certificate: Message malformed");

   const uint8_t* certs = buf.data() + 3;

   while(size_t remaining_bytes = buf.data() + buf.size() - certs)
      {
      if(remaining_bytes < 3)
         throw Decoding_Error("Certificate: Message malformed");

      const size_t cert_size = make_uint32(0, certs[0], certs[1], certs[2]);

      if(remaining_bytes < (3 + cert_size))
         throw Decoding_Error("Certificate: Message malformed");

      DataSource_Memory cert_buf(&certs[3], cert_size);
      m_certs.push_back(X509_Certificate(cert_buf));

      certs += cert_size + 3;
      }
   }

/**
* Serialize a Certificate message
*/
std::vector<uint8_t> Certificate::serialize() const
   {
   std::vector<uint8_t> buf(3);

   for(size_t i = 0; i != m_certs.size(); ++i)
      {
      std::vector<uint8_t> raw_cert = m_certs[i].BER_encode();
      const size_t cert_size = raw_cert.size();
      for(size_t j = 0; j != 3; ++j)
         {
         buf.push_back(get_byte(j+1, static_cast<uint32_t>(cert_size)));
         }
      buf += raw_cert;
      }

   const size_t buf_size = buf.size() - 3;
   for(size_t i = 0; i != 3; ++i)
      buf[i] = get_byte(i+1, static_cast<uint32_t>(buf_size));

   return buf;
   }

}

}
/*
* TLS Hello Request and Client Hello Messages
* (C) 2004-2011,2015,2016 Jack Lloyd
*     2016 Matthias Gierlings
*     2017 Harry Reimann, Rohde & Schwarz Cybersecurity
*
* Botan is released under the Simplified BSD License (see license.txt)
*/
