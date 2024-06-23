/*For more details on what was covered on 06.17.2024, you can visit: 
https://cplusplus.com/reference/stl/ and review information on vectors, list,
and unordered_maps. In particular, review iterators for each template class,
insert and erase for each template class, and the find function for unordered 
maps. We also discussed using the limits library for finding largest and 
smallest value, and using the "?" ternary operator.*/

#include <iostream> 
#include <vector> // learning today, dynamically sized
#include <list> // learning today (infamous linkedlist, cpp stl provides us one)
#include <unordered_map> // learning today
#include <limits>
#include <algorithm>
#include <time.h>

using namespace std;


///////////////////////////////////////////////////////////////////////////////
// void test_vector()
// {
//     // //iterators are pointers used in stl for traversing through data structures
//     vector<int> vec( {2,4,6,8,10,47,5} );

//     // vector<int>::iterator itr; // declartion of iterator inside vector template class, we have a iterator class

//     // // auto itr = vec.begin(); // auto is popular for iterators, auto determines the type of itr based on the rhs

//     // for (itr = vec.begin(); itr != vec.end(); itr++)
    
//     //     std::cout << *itr << " "; // dereference the itr to get the value
        
//     // cout<<"printed with iterators"<<endl;

//     // int max_val = std::numeric_limits<int>::min(); // from <limits> library, popular library, gives us the smallest int data type value possible

//     // int min_val = std::numeric_limits<int>::max(); // from <limits> library, popular library, gives us the largest int data type value possible

//     // cout<<"minimum int value: "<< max_val <<endl;

//     // cout<<"maximum int value: "<< min_val <<endl;

//     // for(int x : vec) max_val = ( x > max_val ) ? x:max_val; //ternary operator ?, it takes 3 inouts: conditional input, return x if true, else max_val if false

//     // cout<<"max value in vec "<< max_val <<endl;

//     // // //use cases for iterators insert 
//     // // O(n) for vector insert
//     // // O(1) constant time for list insert
//     // for (auto x: vec) cout<<x<<" ";
//     // cout << "Original vector, before insertion: \n";
//     // vec.insert(vec.begin()+2, 399); // insert at position 3
//     // // vec.insert(vec.end()-5, 399); // equivalent

//     // for (auto x: vec) cout<<x<<" ";
//     // cout<<"Inserted element 399"<<endl;

//     // vector<int> sub_vec = {3,2,1}; // sub_vec to be insereted
//     // vec.insert(vec.begin()+4, sub_vec.begin(), sub_vec.end()); // insert into 5th position, from sub_vec.begin() till sub_vec.end(), 
//     // // sub_vec.end() is actually an emoty space: 
//     // // [start, stop)

//     // for (auto x: vec) cout<<x<<" ";
//     // cout<<"Inserted sub vector {3,2,1}"<<endl;
    
//     // //sort vector (quick sort) from the <algorithms> library
//     // sort(vec.begin(), vec.end()); // 3rd parameter can be a function itself, like how to sort, largest to smallest
//     // for (auto x: vec) cout<<x<<" ";
//     // cout<<"Sorted Vec"<<endl;

//     // //use cases for iterators erase 
//     // vec.erase(vec.begin()+5); // erase is also O(n), have to move everything after it to the left
//     // for (auto x: vec) cout<<x<<" ";
//     // cout<<"\nerase 5th element"<<endl;
    
//     // vec.erase(vec.begin()+1, vec.begin()+3); // not including that element itself, offset by one. 
//     // for (auto x: vec) cout<<x<<" ";
//     // cout<<"erase 2nd and 3rd element (index 1 and 2)"<<endl;
    
//     // Increment each element in vector by 3
//     for( auto& x : vec)
//     {
//         x += 3;
//     }
//     for (auto x: vec) cout<<x<<" ";

//     // Increment iterator by 3 and print
//     auto it = vec.begin();

//     while(it < vec.end())
//     {
//         std::cout << *it << endl;
//         advance(it, 3);
//     }


// }


///////////////////////////////////////////////////////////////////////////////
// downside of docker is that you sees all gits as new modifications.
// unless put gits credentials in docker, but its not generalized anymore.
void test_list()
{   
    // this is the linkedlist, fun fact: list is a unary tree on mathematical level
    list<int> my_list1({1,2,30,4});
    // 1->2->30->4.2

    //print list1
    cout<<"List 1: ";
    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl;

    // cout<<"list 1: ";
    list<int>::iterator it=my_list1.begin();
    for (it=my_list1.begin(); it!=my_list1.end(); ++it)
        cout<<*it<<" ";
    cout<<endl; 

    // Accessing list elements
    // cout<<my_list1[1]<<endl; //not allowed
    // in list, cannot do list.begin() + 3
    //cout<<my_list1[3]<<endl; //not allowed
    // int i = 0;
    // for(auto x : my_list1)
    // {
    //     if (i == 3) cout<<"Iterate through list: "<<x<<endl;
    //     i++;
    // } 
    

    // list<int>::iterator it=my_list1.begin();
    advance(it, 3); // linear time, O(n)
    // in vector access an element is O(1)
    cout<<"Use advance function to access: "<<*it<<endl;

    // manually implement insert using iterator, insert at index 2, the element 1.618
    it = my_list1.begin();
    int end_pos = 2; // try 10

    for (int i = 0; i < end_pos && it!=my_list1.end(); i++)
    {
        it++;
    }
    for(auto x : my_list1)
    {
        cout<<"hi " <<x<<" ";
    }

    cout<<endl;


    cout<<"*itr is before insertion: " << *it << "\n";
    if(it!=my_list1.end())
    {
        my_list1.insert(it, 1);
    }

    for(auto x : my_list1)
    {
        cout<<x<<" ";
    }

    cout<<"\n after insertion" <<endl;

    // BUT advance function is more efficient: insert at index 2, the element 5
    it = my_list1.begin();
    advance(it, 2); // advance change it by reference, if hover over, &
    my_list1.insert(it, 5);
    cout<<"\n after inserting 5 at index 2" <<endl;

    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl;

    //erase index 1
    cout<<"\n\ntesting erasing now, erasing index 1 " <<endl;

    my_list1.erase(++my_list1.begin());
    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl<<endl;

    //merge
    cout<<"\n\ntesting merging now, erasing index 1 " <<endl;
    list<int> my_list2({9,8,7,6});
    cout<<"List 2: ";
    for(auto x : my_list2) cout<<x<<" ";
    cout<<endl;
    
    //merge
    my_list1.sort(); // 
    my_list2.sort(); // 
    my_list1.merge(my_list2); // merge only exist for the list container
    // merge 2 linkedlists, leetcode problem:
    // https://leetcode.com/problems/merge-two-sorted-lists/description/
    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl;
    cout<<"List2: ";
    for(auto x : my_list2) cout<<x<<" "; //empty now
    cout<<endl;

    //splice, this is the seed
    srand(time(0));
    // refill list2 with 5 random numbers
    for(int i = 0; i < 5; i++) my_list2.insert(my_list2.end(),rand() % 200 - 100); // rand() gives you numbers between 0 and 1, % means always gonna give us integers,
    // - 100, means the range
    for(auto x : my_list2) cout<<x<<" "; 
    cout<<endl;
    
    my_list1.splice ( my_list1.begin(), my_list2); // splice similar to merge
    // put list2 at the beginning of list1
    for(auto x : my_list1) cout<<x<<" ";
    cout<<endl;
    for(auto x : my_list2) cout<<x<<" "; //empty now
    cout<<endl;
}


///////////////////////////////////////////////////////////////////////////////
void test_unordered_maps()
{
    // hashing, calls the hash function
    unordered_map<int, string> my_map1;
    my_map1[1]="data1";
    my_map1[2]="data2";
    my_map1[3]="data1";
    my_map1[1]="data3"; //rewrites first assignment, all keys unique
    my_map1[4]="data4";

    for(auto x : my_map1)
        cout<<x.first<<" "<<x.second<<";";
    cout<<endl;

    auto search1 = my_map1.find(4); // O(constant time) O(1) leverage the hash function
    // Find and erase in one statement
    std::cout << "hey before key 4 is deleted " << search1->second << std::endl;

    search1 = my_map1.erase(search1);  // Erase the element with key 1


    std::cout << "hey after key 4 is deleted: " << search1->first << " :  "<<search1->second << std::endl;
    // std::cout << "hey " << (*search1).second << std::endl;

    
    if(search1 != my_map1.end())
        cout << "Found " << search1->first << " " << search1->second << endl;
    else
        cout<<"Not found"<<endl;

    auto search2 = my_map1.find(2);
    if(search2 != my_map1.end())
        cout << "Found " << search2->first << " " << search2->second << endl;
    else
        cout<<"Not found"<<endl; 

    my_map1.erase(search1);

    for(auto x : my_map1)
        cout<<x.first<<" "<<x.second<<";";
    cout<<endl;   
}



void partition(std::list<int> &nums, const int x)
{
    auto it = nums.begin();
    auto last = prev(nums.end()); // make sure to set last to the last element, not past-the-last element

    std::cout << *last << endl;

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

int main()
{

    // test_vector();
    test_list();
    // test_unordered_maps();

    // test the functionality of iterators in list
    list<int> lis({1,2,3,4,5,6,7});
    auto it = lis.end();

    // std::cout << *prev(it, 3) << endl; // start from one-past-last-element, making 3 jumps, lands on 5

    // vector<int> vec({1,2,3,4,5,6,7});

    // auto itr = vec.begin();
    // std::cout << itr[2] << " and original itr is " << *itr <<std::endl; // same as *(itr + 1)
    // offset of 1 relative to the current position of the iterator.
    // but doesnt increment the itr,
    // this increment the itr: *(++itr);
    



   return 0;
}
