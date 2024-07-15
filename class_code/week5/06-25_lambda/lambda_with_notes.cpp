#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional> // its a STL where includes lambda functions

using namespace std;


// void(*func)(int) // this is how we pass in the func pointer as a type

// this function takes in a vector of integers and a function
// functors a class that acts as a function, a class() can be passed in as a function
// good thing is class can have private variables, functor is an alternative to a lambda.
// have to make a class for functor, more verbose. 
void ForEach(const vector<int>& values, const function<void(int)>& func) //function is the keyword, angle <> is from the library just like vector, void is the function that returns nothing with an int input
// const function<void(int)>& func this is a lambda function,
// void(*func)(int) is dual form of lambda function, they are the same, could use either
{
    for(int val : values)
        func(val);
}


// bool isPalindrome(string s) 
// {
//     //convert s to all lowercase 
//     // takes in a container, for each element, turn c into a lower c
//     // lambda function: [](char& c){ c = tolower(c);}
//     for_each( s.begin(), s.end(), [](char& c){ c = tolower(c); } );
    
//     //remove non-alphanumeric characters
//     //does so by moving all nonalphanumeric character to end of string
//     //then you must delete character from first invalid character located at
//     //it and onwards

//     // remove_if() requires a lambda function to return a boolean
//     // demonstrates how remove_if() works:
//     // when it encounters nonalphanumeric, it moves it to the back
//     // race-#a
//     // race #a-
//     // race a-#
//     //      ^
//     //      |
//     //      pointer stops here
//     auto it = remove_if(s.begin(), s.end(), 
//                         [](char const &c){return !isalnum(c);});
//     s.erase(it, s.end());
//     // then deletes nonalphanumeric characters
    
//     string s_pali;
//     for(auto iter = s.rbegin(); iter !=s.rend(); iter++) s_pali+=*iter;
    
//     return s == s_pali;
// }


// void tempFunc(int value)
// {
//     cout<<"Hi: "<<value<<" ";
// }


// void tempFunc2(string value, int x)
// {
//     cout<<"Hi: "<<value<<endl;
// }

int func(string value)
{
    cout << "hi: " << value << endl;
    return 8;
}

void printNum(const std::vector<int>& nums, const std::function<bool(int, int)>& lambda) 
{
    for(size_t i = 0; i < nums.size() - 1; ++i)
    {
        if (lambda(nums[i], nums[i + 1])) {
            std::cout << nums[i] << " is less than " << nums[i + 1] << std::endl;
        } else {
            std::cout << nums[i] << " is not less than " << nums[i + 1] << std::endl;
        }
    }
}

int main()
{
    // History: lambda comes from lambda calculus, allen turin had teacher, named Alonzo Church,
    // invented almbda calculus, a type of math uses only functions, from axioms you can derive functions
    // starts with 5 axioms, you can derive functions.
    // lamda calculus, turin machines and real number calculus, each all start with axioms where we derive theorems.
    // in computer theory they teach theory
    // lambda caluclus uses function as its atomic unit of computation. 
    // turin uses indeices of array
    // what created the need of 
    // pointer to a function
    // int(*func_ptr)(string) = func; // a function has a return type 
    // // use* to tell compiler its a pointer, storing a pointer to a function
    // cout << func_ptr("sup") << endl; // same as a func call like: func("sup");


    // typedef void(*func_ptr2)(int); //renaming this type into a function pointer
    // typedef int jaime; // give alias int, jaime. jaime and int are interchangable.
    // int x = 7;
    // jaime y = 8;

    // func_ptr2 p = tempFunc;
    // p(3); // pointer gets dereferenced with the parenthesis, when you have a function, when we call void func2
    // // you're actually using a pointer pointing to it. func("sup"), func() is a function pointer
    // // no need "->"
 

    // in C you need to use function pointers and use typedef to give it a name
    // in C++, they implemented lambda
    vector<int> values({7,4,8, 10, 81, 3});
    string x = "SUESUE: ";
    for_each(x.begin(), x.end(),[](char& c){c = tolower(c);});
    std::cout << x << "\n";

    std::string str1 = "Hello";
    std::string str2 = "World";

    std::cout <<  &str2 << std::endl; // str2 is in a valid but unspecified state after move

    // Perform move assignment
    str1 = std::move(str2);


    std::cout << "str1 after move assignment: " << str1 << std::endl;
    std::cout << "str2 after move: " << &str2 << std::endl; // str2 is in a valid but unspecified state after move


    // ) mutable { modify capture variables.pass by copy =, pass by reference &
    // has 3 components:
    // [&x] = capture, global variables that you can pass in, pass by reference
    // (int value) = parameter list
    // {} = what the function does
    // auto lambda = [&x](int value){cout<<x<<value<<" ";}; // if we return 7, auto will know its int
    // can also create things within the lambda function, use [], so it doesnt accept global variable
    // auto lambda = [=](int value){cout<<x<<value<<" ";}; // if we return 7, auto will know its int
    // [=], pass in all global variable declared above by value
    // [&], pass in all global varible declared above by reference 

   
   
    // ForEach(values,lambda);
    
    cout<<endl;
    // ForEach(values, tempFunc);
    // cout<<endl;

    // cout<<isPalindrome("Apple-Sauce")<<endl;
    // cout<<isPalindrome("Race-c-ar-")<<endl;


    // last thing to go over today (6/25/2024)
    // sort(values.begin(), values.end()); //sort() is from algorithm library, by default ascending order small to large
    // above, we're passing in by reference, so we's changing the order auto lambda = [&x](int value){cout<<x<<value<<" ";}; // if we return 7, auto will know its int

    // x = "";

    // ForEach(values,lambda);
    // cout << endl;

    // // we could use lambda to sort in decending order by comparing a > b, a has to be greater than b, preceeding elements than elements that follow
    // // a is the first value compare it to the one that follows
    // sort(values.begin(),values.end(),[](int a, int b){return a > b;});
    
    // ForEach(values,lambda);

    std::string msg = "hi this is a message ";
    std::vector<int> nums{1,2,3,4,5,6,7};
    auto lambda = [&msg](const int a, int b)
    {
        std::cout << msg << "\n";
        return a < b;
    };




    printNum(nums, lambda);

    return 0;
}