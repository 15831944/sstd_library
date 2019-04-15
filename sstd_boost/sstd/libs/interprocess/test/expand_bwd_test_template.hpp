﻿//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_INTERPROCESS_TEST_ALLOCATION_TEST_TEMPLATE_HEADER
#define BOOST_INTERPROCESS_TEST_ALLOCATION_TEST_TEMPLATE_HEADER

#include <sstd/boost/interprocess/detail/config_begin.hpp>
#include "expand_bwd_test_allocator.hpp"
#include <sstd/boost/interprocess/detail/type_traits.hpp>
#include <algorithm> //std::equal
#include <vector>
#include <iostream>

namespace boost { namespace interprocess { namespace test {

template<class T>
struct value_holder
{
   value_holder(T val)  :  m_value(val){}
   value_holder(): m_value(0){}
   ~value_holder(){ m_value = 0; }
   bool operator == (const value_holder &other) const
   {  return m_value == other.m_value; }
   bool operator != (const value_holder &other) const
   {  return m_value != other.m_value; }

   T m_value;
};

template<class T>
struct triple_value_holder
{
   triple_value_holder(T val)
      :  m_value1(val)
      ,  m_value2(val)
      ,  m_value3(val)
   {}

   triple_value_holder()
      :  m_value1(0)
      ,  m_value2(0)
      ,  m_value3(0)
   {}

   ~triple_value_holder()
   {  m_value1 = m_value2 = m_value3 = 0; }

   bool operator == (const triple_value_holder &other) const
   {
      return   m_value1 == other.m_value1
         &&    m_value2 == other.m_value2
         &&    m_value3 == other.m_value3;
   }

   bool operator != (const triple_value_holder &other) const
   {
      return   m_value1 != other.m_value1
         ||    m_value2 != other.m_value2
         ||    m_value3 != other.m_value3;
   }

   T m_value1;
   T m_value2;
   T m_value3;
};

typedef value_holder<int> int_holder;
typedef triple_value_holder<int> triple_int_holder;



//Function to check if both sets are equal
template <class Vector1, class Vector2>
bool CheckEqualVector(const Vector1 &vector1, const Vector2 &vector2)
{
   if(vector1.size() != vector2.size())
      return false;
   return std::equal(vector1.begin(), vector1.end(), vector2.begin());
}

template<class Vector>
bool CheckUninitializedIsZero(const Vector & v)
{
   typedef  typename Vector::value_type value_type;
   typename Vector::size_type sz    = v.size();
   typename Vector::size_type extra = v.capacity() - v.size();
   value_type comp(0);

   const value_type *holder = &v[0] + sz;

   while(extra--){
      if(*holder++ != comp)
         return false;
   }
   return true;
}


//This function tests all the possible combinations when
//inserting data in a vector and expanding backwards
template<class VectorWithExpandBwdAllocator>
bool test_insert_with_expand_bwd()
{
   typedef typename VectorWithExpandBwdAllocator::value_type value_type;
   typedef typename boost::interprocess::ipcdetail::remove_volatile<value_type>::type non_volatile_value_type;
   typedef std::vector<non_volatile_value_type> Vect;
   const int MemorySize = 1000;

   //Distance old and new buffer
   const int Offset[]      =
      {  350,  250,  150,  150,
         150,  50,   50,   50    };
   //Insert position
   const int Position[]    =
      {  100,  100,  100,  100,
         100,  100,  100,  100   };
   //Initial vector size
   const int InitialSize[] =
      {  200,  200,  200,  200,
         200,  200,  200,  200   };
   //Size of the data to insert
   const int InsertSize[]  =
      {  100,  100,  100,  200,
         300,  25,   100,  200   };
   //Number of tests
   const int Iterations    = sizeof(InsertSize)/sizeof(int);

   for(int iteration = 0; iteration < Iterations; ++iteration)
   {
      value_type *memory = new value_type[MemorySize];
      try {
         std::vector<non_volatile_value_type> initial_data;
         initial_data.resize(InitialSize[iteration]);
         for(int i = 0; i < InitialSize[iteration]; ++i){
            initial_data[i] = i;
         }

         Vect data_to_insert;
         data_to_insert.resize(InsertSize[iteration]);
         for(int i = 0; i < InsertSize[iteration]; ++i){
            data_to_insert[i] = -i;
         }

         expand_bwd_test_allocator<value_type> alloc
            (&memory[0], MemorySize, Offset[iteration]);
         VectorWithExpandBwdAllocator vector(alloc);
         vector.insert( vector.begin()
                     , initial_data.begin(), initial_data.end());
         vector.insert( vector.begin() + Position[iteration]
                     , data_to_insert.begin(), data_to_insert.end());
         initial_data.insert(initial_data.begin() + Position[iteration]
                           , data_to_insert.begin(), data_to_insert.end());
         //Now check that values are equal
         if(!CheckEqualVector(vector, initial_data)){
            std::cout << "test_assign_with_expand_bwd::CheckEqualVector failed." << std::endl
                     << "   Class: " << typeid(VectorWithExpandBwdAllocator).name() << std::endl
                     << "   Iteration: " << iteration << std::endl;
            return false;
         }
      }
      catch(...){
         delete [](const_cast<non_volatile_value_type*>(memory));
         throw;
      }
      delete [](const_cast<non_volatile_value_type*>(memory));
   }

   return true;
}

//This function tests all the possible combinations when
//inserting data in a vector and expanding backwards
template<class VectorWithExpandBwdAllocator>
bool test_assign_with_expand_bwd()
{
   typedef typename VectorWithExpandBwdAllocator::value_type value_type;
   typedef typename boost::interprocess::ipcdetail::remove_volatile<value_type>::type non_volatile_value_type;
   const int MemorySize = 200;

   const int Offset[]      = { 50, 50, 50};
   const int InitialSize[] = { 25, 25, 25};
   const int InsertSize[]  = { 15, 35, 55};
   const int Iterations    = sizeof(InsertSize)/sizeof(int);

   for(int iteration = 0; iteration <Iterations; ++iteration)
   {
      value_type *memory = new value_type[MemorySize];
      try {
         //Create initial data
         std::vector<non_volatile_value_type> initial_data;
         initial_data.resize(InitialSize[iteration]);
         for(int i = 0; i < InitialSize[iteration]; ++i){
            initial_data[i] = i;
         }

         //Create data to insert
         std::vector<non_volatile_value_type> data_to_insert;
         data_to_insert.resize(InsertSize[iteration]);
         for(int i = 0; i < InsertSize[iteration]; ++i){
            data_to_insert[i] = -i;
         }

         //Insert initial data to the vector to test
         expand_bwd_test_allocator<value_type> alloc
            (&memory[0], MemorySize, Offset[iteration]);
         VectorWithExpandBwdAllocator vector(alloc);
         vector.insert( vector.begin()
                     , initial_data.begin(), initial_data.end());

         //Insert data
         vector.insert(vector.cbegin(), data_to_insert.begin(), data_to_insert.end());
         initial_data.insert(initial_data.begin(), data_to_insert.begin(), data_to_insert.end());

         //Now check that values are equal
         if(!CheckEqualVector(vector, initial_data)){
            std::cout << "test_insert_with_expand_bwd::CheckEqualVector failed." << std::endl
                     << "   Class: " << typeid(VectorWithExpandBwdAllocator).name() << std::endl
                     << "   Iteration: " << iteration << std::endl;
            return false;
         }
      }
      catch(...){
         delete [](const_cast<typename boost::interprocess::ipcdetail::remove_volatile<value_type>::type*>(memory));
         throw;
      }
      delete [](const_cast<typename boost::interprocess::ipcdetail::remove_volatile<value_type>::type*>(memory));
   }

   return true;
}

//This function calls all tests
template<class VectorWithExpandBwdAllocator>
bool test_all_expand_bwd()
{
   std::cout << "Starting test_insert_with_expand_bwd." << std::endl << "  Class: "
             << typeid(VectorWithExpandBwdAllocator).name() << std::endl;

   if(!test_insert_with_expand_bwd<VectorWithExpandBwdAllocator>()){
      std::cout << "test_allocation_direct_deallocation failed. Class: "
                << typeid(VectorWithExpandBwdAllocator).name() << std::endl;
      return false;
   }

   std::cout << "Starting test_assign_with_expand_bwd." << std::endl << "  Class: "
             << typeid(VectorWithExpandBwdAllocator).name() << std::endl;

   if(!test_assign_with_expand_bwd<VectorWithExpandBwdAllocator>()){
      std::cout << "test_allocation_direct_deallocation failed. Class: "
                << typeid(VectorWithExpandBwdAllocator).name() << std::endl;
      return false;
   }

   return true;
}

}}}   //namespace boost { namespace interprocess { namespace test {

#include <sstd/boost/interprocess/detail/config_end.hpp>

#endif   //BOOST_INTERPROCESS_TEST_ALLOCATION_TEST_TEMPLATE_HEADER
