#include <iostream>
#include<memory>
#include<array>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// 06-20-2024, 
// starting with smart pointers
class Temp
{
    public:
        int temp1;
        int temp2;
        string temp3;
        Temp():temp1(1), temp2(2), temp3("three"){}

        Temp(const Temp& in)
        {
            temp1 = in.temp1;
            temp2 = in.temp2;
            temp3 = in.temp3;

        }
        void print()
        {
            cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
        }


 
        // Assignment operator
        Temp& operator=(const Temp& in) {
            if (this != &in) { // Self-assignment check
                temp1 = in.temp1;
                temp2 = in.temp2;
                temp3 = in.temp3;
            }
            return *this;
        }
};


//Unique pointer are pointers that allocate memory onto the heap and can only
//point to one object. Multiple unqiue pointer are not allowed to point to the
//same object.
///////////////////////////////////////////////////////////////////////////////
void test_unique_ptrs()
{
    array<string,2> test_arr; // create an array of string of size 2 called test_arr // lives on the stack
    test_arr[0]= "test1";
    test_arr[1]= "test2";

    //test_arr_ptr creates a copy on the heap
    // unique_ptrs are template classes, so takes in a type
    // make_unique is the keyword to make a unique pointer onto the heap
    unique_ptr<array<string,2>> test_arr_ptr = make_unique<array<string,2>>(test_arr); // lives on the heap
    
    // move works
    // can also do it this way, create a unique pointer first
    // then move test_arr_ptr to test_arr_ptr2
    // CAN USE MOVE, NOT COPY, think about the different scope
    unique_ptr<array<string,2>> test_arr_ptr2;
    test_arr_ptr2=move(test_arr_ptr);

    // cout<<test_arr_ptr->at(0)<<" "<<test_arr_ptr->at(1)<<endl; // seg fault
    // use ->at() to access the element
    cout << test_arr_ptr2->at(0)<<" "<<test_arr_ptr2->at(1) << endl;
    test_arr_ptr = move(test_arr_ptr2); // move ptr2 back to ptr1

    // reassignment ptr2 to point to a new content
    // array is on the heap
    // ptr is on the stack
    test_arr_ptr2 = make_unique<array<string,2>>(array<string,2>({"t1","t2"}));
    cout << test_arr_ptr2->at(0)<<" "<< test_arr_ptr2->at(1) << endl;


    //cant do cause copy constructor not allowed
    // cannot use it because unique_ptrs cannot point to the same object, otherwise its not unique anymore.
    // unique ptr is responsible to delete array on the heap,
    // unique_ptr<array<string,2>> test_arr_ptr = &test_arr; // &test_arr is on the stack
    // unique_ptr<array<string,2>> test_arr_ptr2 = test_arr_ptr;

    array<string,2> *p = new array<string,2>();
    p[0][0]="does it work ?";
 
    //unique pointers doesnt give you access via square brackets
    //test_arr_ptr[0][0]="test3";   
    (*test_arr_ptr)[0]="test3";
    // change in this: (*test_arr_ptr), will not affect test_arr
    cout<<(*test_arr_ptr)[0]<<" not same as: "<<test_arr[0]<<endl;

    //use at function to avoid confusion with dereferencing unique pointers 
    // (*test_arr_ptr)[0] same as test_arr_ptr->at(0)
    cout<<test_arr_ptr->at(0)<<" "<<test_arr_ptr->at(1)<<endl;


    //syntax for creating arrays of objects on heap 
    //like in project 1: array<Object,2> *sequence_= new array<Object,2>[size_];
    unique_ptr<array<int, 3>[]> arr2 = make_unique<array<int,3>[]>(3);
    // below is its dual from
    // cons: inefficient, default constructor gets called twice, 
    unique_ptr<array<int, 3>[]> arr3(new array<int, 3>[3]);

    arr2[0]={1,11,111}; // we can use [], instead of pointers because [] is overloaded. on line81, unique_ptr is an object of []
    arr2[1]={1,2,3};
    arr2[2]={7,7,7}; 

    arr3[0]={-1,-2,-3};
    arr3[1]={-1,-1,-1};
    arr3[2]={2,2,2};

    for (int i = 0; i < 3; i++)
    {
        cout<<"Point "<<i<<": ("<<arr2[i][0]<<", "<<arr2[i][1]<<", "
            <<arr2[i][2]<<") \n";

        cout<<"Point "<<i<<": ("<<arr3[i][0]<<", "<<arr3[i][1]<<", "
            <<arr3[i][2]<<") \n";

        cout<<endl;
    }   
}


//Shared pointer are pointers that allocate memory onto the heap 
//Multiple shared pointers can point to the same object. Destructor is invoked
//when object has no shared pointers(uses algorithm reference counting). 
///////////////////////////////////////////////////////////////////////////////
// part2, shared pointer,
// think of it like an extension of unique pointer,
// shared_ptr can do 2 additional things: copy constructor and copy assignment
void test_shared_ptrs()
{
    unique_ptr<Temp> obj1 = make_unique<Temp>();

    //shared_ptr<Temp> obj2 = obj1; //not allowed
    // deep copy
    shared_ptr<Temp> obj2 = make_shared<Temp>(*obj1); // always gonna allocate new memory, not allowed to point to unique_ptr, mkaing a deep copy
    //do these point at the same ?
    obj1->temp1=74;
    obj1->print();
    obj2->print();
    cout<<endl;

    // copy constructor works!
    // shallow copy
    shared_ptr<Temp> obj3 = obj2;
    //do these point at the same ?
    obj2->temp1=88;
    obj2->print();
    obj3->print();
    cout<<endl;
}

void test_raw_pointers()
{
        // Create an object using raw pointer
        Temp ok;
        Temp* ptr = new Temp(ok);

    // // Perform deep copy
    Temp* ptr2 = new Temp(*ptr); // Using the deep copy constructor

    // Print addresses to confirm they are different
    std::cout << "ptr: " << ptr << "\n";
    std::cout << "ptr2: " << ptr2 << "\n";

    // Print the contents of each object
    std::cout << "Contents of ptr:\n";
    ptr->print();
    std::cout << "Contents of ptr2 (deep copy):\n";
    ptr2->print();

    // auto ptr3 = new Temp(*ptr);
    // std::cout << ptr3 << "\n";

}

///////////////////////////////////////////////////////////////////////////////
int main()
{
    // test_shared_ptrs();
    // test_unique_ptrs();    
    test_raw_pointers();
    return 0;   
}