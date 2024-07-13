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


}