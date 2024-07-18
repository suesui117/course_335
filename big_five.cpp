#include <iostream>
#include <string>
#include <vector>



int main()
{

    // int a = 5;
    // int b = 10;
    // b = a;

    // std::cout << "This is copy assignment b is: " << b << " a is " << a << "\n";

    int a = 5;
    int b;
    b = a;

    std::cout << "This is copy assignment b is: " << b << " a is " << a << "\n";

    

    int c = 7;
    int d = c;
    std::cout << "This is copy constructor d is: " << d << " c is " << c << "\n";


    int e = 99;
    int f = std::move(e);
    std::cout << "This is move assignment f is: " << f << " e is " << e << "\n";

    int g = 100;
    int h = std::move(g);
     std::cout << "This is move constructor h is: " << h << " g is " << g << "\n";


    
return 0;

}