#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // defines a core set of functions used for data type conversion, 
// pseudo-random number generation, memory allocation, searching, sorting, mathematics, 
// and dealing with wide or multibyte characters.
#include <ctime>
// srand(117);
class Customer
{
    public:
        Customer()
        {
            name_ = "";
            SetPriorityLevel();
        }// default constructor
        
        Customer(const std::string name) // calling SetPriorityLevel
        {
            name_ = name;
            SetPriorityLevel();
        }// parameterized constructor
 
        // setters
        void SetName(const std::string& in_name) { name_ = in_name; }

        void SetPriorityLevel() { priority_level_ = rand() % 101; }// Generates a pseudo-random integer between 0 and RAND_MAX.
            // mod 101 because we need 0 to 100, if 101/101, that loops back to 0. 
            // std::cout << priority_level_ << "\n";
        void SetServiceTime() { service_time_ = rand() % 61; } // random int between 0 and 60



        // getters
        std::string GetName() const { return name_; } 

        int GetPriorityLevel() const { return priority_level_; }

        int GetServiceTime() const { return service_time_; }


        // comparison operators overload:
        bool operator>(const Customer& other) const 
        { 
            return priority_level_ > other.priority_level_; 
        }

        bool operator<(const Customer& other) const 
        {
            return priority_level_ < other.priority_level_;
        }

        bool operator==(const Customer& other) const 
        {
            return priority_level_ == other.priority_level_;
        }
        


    private:
        std::string name_;
        int service_time_ = 0;
        int priority_level_;

};


#endif // end of customer class
