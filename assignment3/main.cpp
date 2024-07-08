#include <iostream>
#include <algorithm>
#include <vector>
#include "maxHeap.h"
#include "Customer.h"



int main()
{

    // srand(time(0));
    Customer sue("sue");
    Customer joe("joe");
    Customer andy("andy");
    Customer tony("tony");
    Customer cathy("cathy");
    
    std::vector<Customer> vec{sue, andy, tony, cathy, joe};
    MaxHeap<Customer> ok(vec);

    ok.insert(joe);

    std::cout << "size of heap is now: " << ok.getHeapVec().size() << "\n";
    for(auto x : ok.getHeapVec())
    {
        std::cout << x.GetName() << " -> " << x.GetPriorityLevel() << "\n";
    }


    // MaxHeap<Customer> heap;

    // // Insert customers into the heap
    // heap.insert(Customer("Tony"));
    // heap.insert(Customer("Joe"));
    // heap.insert(Customer("Sue"));
    // heap.insert(Customer("Cathy"));
    // heap.insert(Customer("Andy"));

    // Delete max items and collect history

    // get the heap vector and then loop through
    std::vector<Customer> heapVec = ok.getHeapVec();
    std::vector<Customer> history;

    std::cout << "Before sorting \n";


    while(!ok.IsEmpty()) // keep deleting till its empty
    {        
        auto deleted = ok.DeleteMax();
        deleted.SetServiceTime();
        history.push_back(deleted);
        std::cout << deleted.GetName() << " has a time stamp of " << deleted.GetServiceTime() << "\n";
    }


    auto lambda_func = [](const Customer& a, const Customer& b)
    {
        return a.GetServiceTime() < b.GetServiceTime();
    };
    std::cout << "\nAfter sorting \n";

    std::sort(history.begin(), history.end(), lambda_func);
    for(auto x : history)
    {
        std::cout << x.GetName() << " has a time stamp of " << x.GetServiceTime() << "\n";
    }


    std::cout << "size of heap is now: " << ok.getHeapVec().size() << "\n";







    return 0;
}