#include <iostream>
#include <algorithm>
#include <vector>
#include "maxHeap.h"
#include "Customer.h"



int main()
{

    srand(time(0));
    Customer sue("sue");
    Customer joe("joe");
    Customer andy("andy");
    Customer tony("tony");
    Customer cathy("cathy");
    
    std::vector<Customer> vec{sue, andy, tony, cathy};
    MaxHeap<Customer> ok(vec);

    ok.printHeap();
    ok.insert(joe);
    // ok.printHeap();
    // ok.DeleteMax();
    // ok.DeleteMax();
    // ok.DeleteMax();
    // ok.DeleteMax();
    // ok.DeleteMax();


    std::cout << ok.findMax().GetName() << "\n";
    ok.printHeap();
    ok.makeEmpty();
    ok.printHeap();
    ok.IsEmpty();
    std::cout << ok.size();

    return 0;
}