#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


int main()
{


    std::string sue = "sue";
    int x = 5;

    std::hash<int> hf;

    std::cout << hf(x);


    return 0;
}