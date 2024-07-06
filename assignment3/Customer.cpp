#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // defines a core set of functions used for data type conversion, 
// pseudo-random number generation, memory allocation, searching, sorting, mathematics, 
// and dealing with wide or multibyte characters.

class Customer
{
    public:
        Customer()
        {
            name_ = "";
            service_time_ = 0;
            SetPriorityLevel();
        }// default constructor
        
        Customer(const std::string name, const int service_time, const int priority_level )
        {
            name_ = name;
            service_time_ = service_time;
            SetPriorityLevel();
        }

        void SetPriorityLevel()
        {
            priority_level_ = rand() % 101; // Generates a pseudo-random integer between 0 and RAND_MAX.
            // mod 101 because we need 0 to 100, if 101/101, that loops back to 0. 
            // std::cout << priority_level_ << "\n";
        };

        void SetServiceTime()
        {
            service_time_ = rand() % 61; // 0 to 60
        };

        int GetPriorityLevel()
        {
            return priority_level_;
        }

        int GetServiceTime()
        {
            return service_time_;
        }

    private:
        std::string name_;
        int service_time_;
        int priority_level_;

};


#endif // end of customer class
