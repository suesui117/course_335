#ifndef DOUBLE_HASHING_H
#define DOUBLE_HASHING_H

#include <vector>
#include <algorithm>
#include <functional> // its a STL where includes lambda functions

/*
From textbook: Data Structures and Algorithm Analysis, fourth edition
Chapter 5. p.207

hashTable is a class that stores HashedObj as the key.
HashEntry is a struct object that has 2 member variables, the HashedObject (element_) and info_ which is just a tag
element_ is the one being hashed, the hash value will be the index where hashedObject will be stored.

HashEntry.element_ = key
HashEntry.info_ = just a flag

hf(HashEntry.element_) = hash value or index
*/

// double hashing implementation.
// create a class called HashTableDouble which holds HashedObj as the key
template <typename HashedObj>
class HashTableDouble{

 public:
  // ACTIVE = 0
  // EMPTY = 1
  // DELETED = 2
  enum EntryType {ACTIVE, EMPTY, DELETED};

  // textbook 205
  // constructor, explicitly specifying a size:
  // like HashTableDouble sue(200); or HashTableDouble sue;, cannot do HashTableDouble sue = 200;
  explicit HashTableDouble(size_t size = 101, int R = 89) : array_(NextPrime(size)), R_(R)
    { 
      std::cout << "size of table is" << size << "\n";
      std::cout << "size of array table size is" << array_.size() << "\n";

      MakeEmpty(); 
    }
  


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
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5 when current size is more than 50% of the entire table size
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
    size_t current_pos = InternalHash(x); // Initial hash function
    std::hash<HashedObj> hf;
    int h2x = R_ - (hf(x) % R_); // Secondary hash function
    int probe_counter = 1; // Count the first search as one probe
    int temp = current_pos; // using temp, as we're not changing h(x), it remains unchanged
    int i = 1;

    while (IsActive(temp)) {
        if (array_[temp].element_ == x) 
        {
            return {true, probe_counter}; // check first, not incrementing probe counter yet
        }
        
        // Compute next probe position using double hashing
        temp = (current_pos + i * h2x) % array_.size(); // i=1 for the first iteration
        ++i;
        ++probe_counter;
    }

    // if IsActive(temp) is false or enters the while loop and becomes false, it will reach here, along with probe counter
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
    int R_;
    mutable size_t total_collision_ = 0;


    bool IsActive(size_t current_pos) const
    {
      return array_[current_pos].info_ == ACTIVE; 
    }


    // private member function 2
    // this is the double_hashing section
size_t FindPos(const HashedObj & x) const 
{
    size_t current_pos = InternalHash(x); // Initial hash position: h(x) = hf(x) % array_.size()
    std::hash<HashedObj> hf;
    int h2x = R_ - (hf(x) % R_); // Secondary hash value: h2(x) = hash2(x) = R - (x mod R).  we're using hf(x) = hash value, NOT h(x). hf(x) not the same as h(x) 
    int i = 1; // Start with 1 and increment in the loop
    int probe_counter = 1; // count the first search as one probe
    size_t temp = current_pos; // Start with initial hash value

    std::cout << "\n\n\n\nKey to be inserted is: " << x <<" and its h2(x) is: " << h2x << " its h(x) is " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? " Empty/deleted" : " NOT-EMPTY --> ") << array_[current_pos].element_ << " <-- "<< InternalHash(array_[current_pos].element_)<< "\n";
    std::cout << "This is the current_pos of double hashing: " << current_pos << "\n";

    // will only enter the loop if collision occurred
    while (array_[temp].info_ != EMPTY && array_[temp].element_ != x) 
    {
        ++total_collision_;
        ++probe_counter; // as soon as we enter the while loop, need to increment the probe

        // std::cout << "While loop entered: " <<  "Key to be inserted is: " << x <<" and its hashed value is: " << temp << ((array_[temp].info_ == 1 || array_[temp].info_ == 2 ) ? " Empty/deleted" : " NOT-EMPTY --> ") << array_[temp].element_ << " <--\n";

        std::cout << "This is the current_pos of double hashing: " << current_pos << "\n";
        temp = (current_pos + i * h2x) % array_.size(); // Compute i-th probe, current_pos is the result of h(x)
        ++i;


        // std::cout << "NEW double hashed value After offsetting I entered: " <<  "Key to be inserted is: " << x <<" and its double hashed value is: ---------> " << temp << " <-------- and at this index is " << ((array_[temp].info_ == 1 || array_[temp].info_ == 2 ) ? "Empty/deleted" : "NOT_EMPTY ") << array_[temp].element_ << "\n";

        if (array_[temp].info_ == EMPTY || array_[temp].element_ == x)
        {
            // std::cout << "We're good to exit now, NEW double hashed value After offsetting I entered: " <<  "Key to be inserted is: " << x <<" and its double hashed value is: ---------> " << temp << " <-------- and at this index is " << ((array_[temp].info_ == 1 || array_[temp].info_ == 2 ) ? "Empty/deleted" : "NOT_EMPTY ") << array_[temp].element_ << " TOTAL PROBE is " << probe_counter << "\n";
            return temp;
        }

    }

    // std::cout << "NO COLLISION Key to be inserted is: " << x <<" and its hashed value is: " << current_pos << " and at this index is " << ((array_[current_pos].info_ == 1 || array_[current_pos].info_ == 2 ) ? "Empty/deleted" : "NOT empty ") << array_[current_pos].element_ << " TOTAL PROBE is " << probe_counter <<"\n";

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
      return hf(x) % array_.size(); // same as h(x) = x mod m or h(x) x % m 
    }

};

#endif  // DOUBLE_HASHING_H
