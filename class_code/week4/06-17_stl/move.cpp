#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{

    std::vector<int> vec{1, 2, 3, 4, 5};
    auto it = vec.begin();
    auto diff = vec.end();

    // Pre-increment
    while (it != vec.end())
    {
        auto ok = it -2;

        std::cout << ((ok < it) ? 1 : 0) << std::endl;
       ++it;

    }

    // // Reset iterator
    // it = lst.begin();

    // // Post-increment
    // while (it != lst.end()) {
    //     std::cout << *it++ << " ";  // Dereferences first, then increments
    //     if (it == lst.end()) break;  // Check if it reached the end
    // }
    // std::cout << std::endl;

    return 0;
}