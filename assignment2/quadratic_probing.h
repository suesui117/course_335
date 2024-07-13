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
// create a class called Hashtable which holds HashedObj as the key
template <typename HashedObj>
class HashTable {

 public:
    // ACTIVE = 0
    // EMPTY = 1
    // DELETED = 2
    enum EntryType {ACTIVE, EMPTY, DELETED};

    // textbook 205
    // constructor, explicitly specifying a size:
    // like HashTable sue(200); or HashTable sue;, cannot do HashTable sue = 200;
    explicit HashTable(size_t size = 101) : array_(NextPrime(size))
      { MakeEmpty(); }


    // Q1 B), modify Contains to do the job of Found/Not_Found
    bool Contains(const HashedObj & x) const 
    {
    // quick note, Contains already does the check multiple times to see if a key is found or not,
    // check with prof, if not found, do you still want the probe count?
    return IsActive(FindPos(x));
    }



    void MakeEmpty() 
    {
      current_size_ = 0;
      for (auto &entry : array_)
      {
        // std::cout << entry.element_ << " hey\n";
        entry.info_ = EMPTY;
      }
    }


    /**
    @param HashedObj  : a type T object, in our case is a string - word
    @post             : successfully inserted the key into the hash table and return true
    @return           : returns true if inserted successfully else false if already existed in the table
    */
    bool Insert(const HashedObj & x) {
    
      size_t current_pos = FindPos(x); // find a position for this word first
      if (IsActive(current_pos))
        return false;
      
      array_[current_pos].element_ = x; // then assemble the HashEntry
      array_[current_pos].info_ = ACTIVE;
      
      // Rehash; see Section 5.5
      if (++current_size_ > array_.size() / 2)
        Rehash();  

      return true;
    }
    
    /*
      Overload the Insert function to accept an rvalue reference input.
    */
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

    /***************** User defined functions Begin *****************/

    // current size
    size_t size() { return current_size_; }


    // table size, should be bigger than current_size due to rehashing
    size_t tableSize() { return array_.size(); }

    // user-defined operator[] overloading
      const HashedObj& operator[](size_t index) const 
      {
          if (index < array_.size()) {
              return array_[index].element_;
          } else {
              // Handle index out of bounds error or return a default value
              throw std::out_of_range("Index out of bounds");
          }
      }


    size_t totalCollision() { return total_collision_; }

    float averageCollision() { return static_cast<float>(total_collision_) / size(); }

    float loadFactor() { return static_cast<float>(current_size_) / array_.size(); }


    std::pair<bool, int> FindProbe(const HashedObj & x) const 
    {
      size_t offset = 1;
      size_t current_pos = InternalHash(x);
      int probe_counter = 1;
      // std::cout << "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty, this element is there: ") << array_[current_pos].element_ << " "<<InternalHash(array_[current_pos].element_)<< "\n";


      // If found, increment probe_counter until we find x or hit an empty slot
      while (IsActive(current_pos)) {
          if (array_[current_pos].element_ == x) {
              // Element found, return with current probe_counter
              return {true, probe_counter};
          }
          
          // Increment probe_counter and compute next position
          ++probe_counter;
          current_pos += offset;
          offset += 2;

          // Handle wrap around if necessary
          if (current_pos >= array_.size())
              current_pos -= array_.size();
      }

      // Element not found, return with probe_counter for last position checked
      return {false, probe_counter};
    }

/***************** User defined functions End *****************/

  // below are all private data members and private member functions
  private:     

    struct HashEntry // struct HashEntry parameterized constructor with default arguments
    {

      HashedObj element_;
      EntryType info_;

      // struct HashEntry variable will be created with 2 data members:
      // they are 1. HashedObj - default to empty and 2. EntryType - default to EMPTY
      HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY) //
      :element_{e}, info_{i} { }
      
      HashEntry(HashedObj && e, EntryType i = EMPTY)
      :element_{std::move(e)}, info_{ i } {}
    };
      

    std::vector<HashEntry> array_;
    size_t current_size_;
    mutable size_t total_collision_ = 0;


    /**
    @param current_pos  : size_t an integer
    @post               : if the key is already in the hash table return true
    @return             : returns true if the info_ tag is active else false
    */
    bool IsActive(size_t current_pos) const
    {
      return array_[current_pos].info_ == ACTIVE; 
    }


    // private member function 2
    // this is the quadratic_probing section
    size_t FindPos(const HashedObj & x) const 
    {
      size_t offset = 1;
      size_t current_pos = InternalHash(x);
      int probe_counter = 1;
      // std::cout << "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty, this element is there: ") << array_[current_pos].element_ << " "<<InternalHash(array_[current_pos].element_)<< "\n";

      // will only enter the loop if collision occured  
      while ( array_[current_pos].info_ != EMPTY && array_[current_pos].element_ != x) 
      {
        ++total_collision_;
        ++probe_counter;
        // std::cout << "Hi I entered: " <<  "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty ") <<array_[current_pos].element_ << "\n";

        current_pos += offset;  // Compute i-th probe.
        offset += 2;

        // std::cout << "After offsetting I entered: " <<  "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty ") <<array_[current_pos].element_ << "\n";


        if (current_pos >= array_.size()) // this is the wrap around
          current_pos -= array_.size();
        // std::cout << "After offsetting I entered: " <<  "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty ") <<array_[current_pos].element_ << "\n";

      }
      // std::cout << "Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty ") <<array_[current_pos].element_ << " Probing is: " << probe_counter <<"\n";


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
      static std::hash<HashedObj> hf; // this is a hash function that hashes 
      return hf(x) % array_.size();
    }

};

#endif  // QUADRATIC_PROBING_H
