﻿//          Copyright Alain Miniussi 20014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// A test of the sendrecv() operation.
#include <sstd/boost/mpi/communicator.hpp>
#include <sstd/boost/mpi/environment.hpp>
#include <sstd/boost/test/minimal.hpp>
#include <vector>
#include <algorithm>
#include <sstd/boost/serialization/string.hpp>
#include <sstd/boost/iterator/counting_iterator.hpp>
#include <sstd/boost/lexical_cast.hpp>
#include <numeric>

namespace mpi = boost::mpi;

struct blob {
  blob(int i) : value(i) {}
  int value;
  template<class Archive>
  void serialize(Archive& s, const unsigned int version) {
    s & value;
  }
};

std::ostream& operator<<(std::ostream& out, blob const& b) {
  out << "blob(" << b.value << ")";
  return out;
}

bool operator==(blob const& b1, blob const& b2) {
  return b1.value == b2.value;
}

template<typename T>
void test_sendrecv(mpi::communicator& com) {
  int const wrank = com.rank();
  int const wsize = com.size();
  int const wnext((wrank + 1) % wsize);
  int const wprev((wrank + wsize - 1) % wsize);
  T recv(-1);
  com.sendrecv(wnext, 1, T(wrank), wprev, 1, recv);
  for(int r = 0; r < wsize; ++r) {
    com.barrier();
    if (r == wrank) {
      std::cout << "rank " << wrank << " received " << recv << " from " << wprev << '\n';
    }
  }
  BOOST_CHECK(recv == T(wprev));
}

int test_main(int argc, char* argv[])
{
  mpi::environment env(argc, argv);
  mpi::communicator world;
  test_sendrecv<int>(world);
  test_sendrecv<blob>(world);
  return 0;
}
