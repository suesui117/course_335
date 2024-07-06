#include <iostream>
#include <algorithm>
#include <vector>
#include "maxHeap.h"
#include "Customer.cpp"



int main()
{

    std::vector<int> vec{1,2,3,4,5,6,7,8};
    MaxHeap<int> ok(vec);
    std::cout << ok.size() << "\n";

    // Customer sue;
    // // sue.SetPriorityLevel();
    // // sue.SetServiceTime();

    // std::cout << sue.GetPriorityLevel() << std::endl;
    // std::cout << sue.GetServiceTime() << std::endl;



    return 0;
}