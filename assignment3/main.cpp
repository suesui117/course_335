#include <iostream>
#include <algorithm>
#include <vector>
#include "maxHeap.h"
#include "Customer.h"


int main()
{
    /************* Create a few customers **************/
    Customer sue("sue");
    Customer joe("joe");
    Customer andy("andy");
    Customer tony("tony");
    Customer cathy("cathy");
    Customer jaime("jaime");
    Customer amy("amy");
    Customer bea("bea");
    Customer chloe("chloe");
    Customer daisy("daisy");
    
    std::vector<Customer> vec{sue, andy, tony, cathy};

     MaxHeap<Customer> my_heap(vec); // construct heap with vector passed in
     my_heap.insert(joe); // insert a few customers
     my_heap.insert(jaime);
     my_heap.insert(amy);
     my_heap.insert(bea);
     my_heap.insert(chloe);
     my_heap.insert(daisy);
    /************* Create a few customers **************/



    /************* Test to for max heap property **************/

    std::cout << "size of heap is now: " << my_heap.getHeapVec().size() << "\n";
    for(auto x : my_heap.getHeapVec())
    {
        std::cout << x.GetName() << "\t -> " << x.GetPriorityLevel() << "\n";
    }
    /************* Test to for max heap property **************/



    /************* Test returned deleted max customer and store in history  **************/

    std::vector<Customer> heapVec = my_heap.getHeapVec();
    std::vector<Customer> history;

    std::cout << "\nBefore sorting by service time: from smallest to largest\n";
    while(!my_heap.IsEmpty()) // keep deleting till its empty
    {        
        auto deleted = my_heap.DeleteMax();
        deleted.SetServiceTime();
        history.push_back(deleted);
        std::cout << deleted.GetName() << "\t has a priority of -> " << deleted.GetPriorityLevel() <<" and has a time stamp of " << deleted.GetServiceTime() << "\n";
    }
    /************* Test returned deleted max customer and store in history  **************/



    /************* Test sorted Customers based on service time from smallest to largest  **************/
    auto lambda_func = [](const Customer& a, const Customer& b)
    {
        return a.GetServiceTime() < b.GetServiceTime();
    };

    std::cout << "\nAfter sorting by service time from smallest to largest\n";
    std::sort(history.begin(), history.end(), lambda_func);
    for(auto x : history)
    {
        std::cout << x.GetName() << "\thas a time stamp of " << x.GetServiceTime() << "\n";
    }
    
    std::cout << "size of heap is now: " << my_heap.getHeapVec().size() << "\n";
    /************* Test sorted Customers based on service time from smallest to largest  **************/


    return 0;
}