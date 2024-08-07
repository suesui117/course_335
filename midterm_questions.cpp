#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


void printString(const std::string &str)
{
    std::cout << "Lvalue(lhs), a variable, was called " << str << "\n\n";

}


void printString(const std::string &&str)
{
    std::cout << "Rvalue(rhs), temp literal, was called " << str << "\n\n";

}



void printString(const int &num)
{
    std::cout << "printString overloaded with num, Lvalue(lhs), a variable, was called " << num << "\n\n";

}


void printString(const int &&num)
{
    std::cout << "printString overloaded with num, Rvalue(rhs), temp literal, was called " << num << "\n\n";

}


int compute(std::list<int> &my_list)
{
    std::list<int>::iterator it = my_list.begin();
    int sum;
    int average;


    for(it; it != my_list.end(); ++it)
    {
        sum += *it;
    }

    average = sum/my_list.size();
    return average;

}

// void printIntegers(int a, int b, int c)
// {
//     std::cout << a << b << c << "\n";
// }

void printIntegers(int a=0, int b, int c) // this is NOT ok
{
    std::cout << a << b << c << "\n";
}

// void printIntegers(int a, int b, int c=9) // this is ok
// {
//     std::cout << a << b << c << "\n";
// }



int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    printIntegers(b,c);

// std::string str = "sue";
// printString(str); // lvalue passed in 
// printString("blah"); // rvalue passed in
// printString(str+"blah"); // rvalue passed in


// std::list<int> my_list({1,2,3,4,5});
// int result = compute(my_list);

// std::cout << "The average of the ints in list is: " << result << "\n";

// printString(compute(my_list));

// declare a iterator of array with size 2

}
