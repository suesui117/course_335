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
    
    // std::vector<Customer> vec{sue, andy, tony, cathy};
    // MaxHeap<Customer> ok(vec);

    // ok.printHeap();
    // ok.insert(joe);
    // ok.printHeap();


    // ok.DeleteMax();
    // ok.DeleteMax();
    // ok.DeleteMax();

    // ok.printHeap();
    
    // ok.GetHistory();

    MaxHeap<Customer> heap;

    // Insert customers into the heap
    heap.insert(Customer("Tony"));
    heap.insert(Customer("Joe"));
    heap.insert(Customer("Sue"));
    heap.insert(Customer("Cathy"));
    heap.insert(Customer("Andy"));
    heap.printHeap();

    // Delete max items and collect history
    heap.DeleteMax(); // Deletes the max and adds to history
    // heap.DeleteMax(); // Deletes the max and adds to history

    // Print and sort the history
    heap.GetHistory();
    heap.printHeap();



    return 0;
}