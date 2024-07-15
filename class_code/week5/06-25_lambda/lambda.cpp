#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


//void(*func)(int)
void ForEach(const vector<int>& values, const function<void(int)>& func)
{
    for(int val : values)
        func(val);
}


bool isPalindrome(string s) 
{
    //convert s to all lowercase 
    for_each(s.begin(), s.end(),[](char& c){c = tolower(c);});
    
    //remove non-alphanumeric characters
    //does so by moving all nonalphanumeric character to end of string
    //then you must delete character from first invalid character located at
    //it and onwards
    auto it = remove_if(s.begin(), s.end(), 
                        [](char &c){return !isalnum(c);});
    s.erase(it, s.end());

    std::cout << s << "<------\n";
    
    string s_pali;
    for(auto iter = s.rbegin(); iter !=s.rend(); iter++) s_pali+=*iter;
    
    return s == s_pali;
}


int func(std::string msg)
{
    cout<<"Hi: "<< msg <<endl;
    return 8;
}


void func(int value)
{
    cout<<"Hello: "<<value<<" ";
}


void func2(int value)
{
    cout<<"Howdy: "<<value<<" ";
}


int main()
{
    //return type - (pointer name) - (list of types of input parameter)
    
    // int(*func_ptr)(string) = func;
    // cout << func_ptr("sue") <<endl; 
    // cout<< func("sue") <<endl;

    // typedef int(*func_ptr)(string);
    // func_ptr p = func;
    // p("sue");


    // // typedef int jaime;
    // // int x = 7;
    // // jaime y = 7;
    // // std::cout << "alias:  " << y << "\n";
    
    // // typedef void(*func_ptr2)(int); // create a function pointer called func_ptr2 that returns nothing, but accepts an int as int
 

    // // func_ptr2 p = func;
    // // // cout<<endl;
    // // p(3);
 

    vector<int> values({7,4,8, 10, 81, 3});
    string x = "Hello: ";
    // // ) mutable { modify capture variables.pass by copy =, pass by reference &
    auto lambda = [&x](int value){cout<<x<<value<<" "; };

    ForEach(values,lambda);
    cout<<endl;

    ForEach(values, func2);
    cout<<endl;

    std::cout<<isPalindrome("Apple-Sauce")<<endl;
    std::cout<<isPalindrome("Race-c-ar-")<<endl;
    std::cout<<isPalindrome("bob")<<endl;
    std::cout<<isPalindrome("app");

    sort(values.begin(), values.end()); //by default sorts in ascending
    x="";

    ForEach(values,lambda);
    std::cout<<endl;

    sort(values.begin(),values.end(),[](int a, int b){return a > b;});
    ForEach(values,lambda);

    return 0;
}