#include <iostream>
#include <algorithm>
#include <vector>
#include "maxHeap.h"
#include "Customer.cpp"



int main()
{

    Customer sue("sue");
    Customer joe("joe");
    Customer andy("andy");
    Customer tony("tony");
    Customer cathy("cathy");
    
    std::vector<Customer> vec{sue, joe, andy, tony, cathy};
    MaxHeap<Customer> ok(vec);

    ok.printHeap();

    // ok.buildHeap();
    // std::cout << sue.GetPriorityLevel() << std::endl;
    // std::cout << joe.GetPriorityLevel() << std::endl;


    // std::cout << (sue < sue) << std::endl;





    return 0;
}