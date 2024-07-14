#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int main()
{

    
    
    std::string str = ".";
    std::hash<std::string> hf; // this is a hash function that hashes string
    hf(str);

    std::cout << "string is: " << str << " hashed value is " << hf(str) << '\n';


    int x = 5;
    std::hash<int> hf1;
    std::cout << hf1(x) << "\n";


    std::string sue = "sue";
    std::hash<std::string> hf2;
    std::cout << hf2(sue) << "\n";


}