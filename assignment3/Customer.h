#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<algorithm>
#include<vector>

class Customer
{
    public:
        Customer()
        {
            name_ = "";
            service_time_ = 0;
            priority_level_ = 0;
        } // default
        




    private:
        std::string name_;
        int service_time_;
        int priority_level_;




};


#endif // end of customer class