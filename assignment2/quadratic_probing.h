#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>

/*
From textbook: Data Structures and Algorithm Analysis, fourth edition
Chapter 5. p.207
*/

namespace {

// Internal method to test if a positive number is prime.
bool IsPrime(size_t n) {
  if( n == 2 || n == 3 )
    return true;
  
  if( n == 1 || n % 2 == 0 )
    return false;
  
  for( int i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
      return false;
  
  return true;
}


// Internal method to return a prime number at least as large as n.
int NextPrime(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!IsPrime(n)) n += 2;  
  return n;
}

}  // namespace


// Quadratic probing implementation.
// create a class called Hashtable
template <typename HashedObj>
class HashTable {

 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  // textbook 205
  // constructor, explicitly specifying a size:
  // like HashTable sue(200); or HashTable sue;, cannot do HashTable sue = 200;
  explicit HashTable(size_t size = 101) : array_(NextPrime(size))
    { MakeEmpty(); }
  
  bool Contains(const HashedObj & x) const {
    return IsActive(FindPos(x));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();  
  
    return true;
  }
    
  bool Insert(HashedObj && x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();

    return true;
  }

  // just marks is x is deleted (true) or not (active - false)
  bool Remove(const HashedObj & x) {
    size_t current_pos = FindPos(x);
    if (!IsActive(current_pos)) // IsActive(current_pos) returns false if its empty or deleted, not false means not empty, which is active
      return false; // if its active return false;

    array_[current_pos].info_ = DELETED; // else if its empty or deleted, set it to deleted
    return true;
  }



  // below are all private data members and private member functions
  private:     

    struct HashEntry 
    {
      HashedObj element_;
      EntryType info_;
      
      HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
      :element_{e}, info_{i} { }
      
      HashEntry(HashedObj && e, EntryType i = EMPTY)
      :element_{std::move(e)}, info_{ i } {}
    };
      

    std::vector<HashEntry> array_;
    size_t current_size_;


    // private member function 1
    bool IsActive(size_t current_pos) const
    {
      return array_[current_pos].info_ == ACTIVE; 
    }


    // private member function 2
    // this is the quadratice_probing section
    size_t FindPos(const HashedObj & x) const 
    {
      size_t offset = 1;
      size_t current_pos = InternalHash(x);
        
      while ( array_[current_pos].info_ != EMPTY && array_[current_pos].element_ != x) 
      {
        current_pos += offset;  // Compute i-th probe.
        offset += 2;

        if (current_pos >= array_.size())
          current_pos -= array_.size();
      }

      return current_pos;
    }


    // private member function 3
    void Rehash() 
    {
      std::vector<HashEntry> old_array = array_;

      // Create new double-sized, empty table.
      array_.resize(NextPrime(2 * old_array.size()));
      for (auto & entry : array_)
        entry.info_ = EMPTY;
      
      // Copy table over.
      current_size_ = 0;
      for (auto & entry :old_array)
        if (entry.info_ == ACTIVE)
          Insert(std::move(entry.element_));
    }


    // private member function 3
    // collision handles different 
    size_t InternalHash(const HashedObj & x) const 
    {
      static std::hash<HashedObj> hf;
      return hf(x) % array_.size( );
    }

};

#endif  // QUADRATIC_PROBING_H
