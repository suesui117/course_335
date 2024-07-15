#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{5, 10, 15, 20, 25, 30, 35};

    // // Define a lambda function
    auto lambda = [](int a, int b){ return a < b; };

    // // Use std::sort with the lambda function
    std::sort(vec.begin(), vec.end(), lambda);

    // // Output sorted vector
    // for (int num : vec) {
    //     std::cout << num << " ";
    // }
    std::cout << std::endl;

    return 0;
}
