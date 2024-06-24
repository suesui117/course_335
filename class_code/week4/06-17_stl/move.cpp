#include <iostream>
#include <list>

void partition(std::list<int> &nums, const int x)
{
    auto it = nums.begin();
    auto last = prev(nums.end()); // make sure to set last to the last element, not past-the-last element

    std::cout << *last << std::endl;

    while (it != last)
    {
        if (*it > x)
        {
            nums.push_back(*it);  // Move greater elements to the back
            it = nums.erase(it);       // Erase current element
        }
        else
        {
            ++it;  // Move to the next element
        }

    }
    
}


int main() {
    std::list<int> myList = {3, 5, 2, 8, 1, 7, 4};
    int x = 4;

    std::cout << "Original list: ";
    for (auto num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    partition(myList, x);

    std::cout << "Partitioned list with x = " << x << ": ";
    for (auto num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Output the modified list
    for (auto num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;

}