#include <iostream>
#include <map>
#include <string>
#include <chrono> //* for concurrent programming, alot of algorithm
#include <thread> //* ability to create our threads
#include <mutex> // mutex objects

using namespace std;

// set up 2 global variables
map<string, string> g_pages;  // a map 
mutex g_pages_mutex; // a mutex is a lock, when using shared memeory model, all concurrent processes, the program itself, threads1, thread2, all accessing
// the same memory, maybe program wants to modify g_pages, threads1 maybe also modigying g_pages. 
// to solve the problem, mutex comes in

/* mutex and threads are two different things
there are 2 types of concurrent programming:
1. shared memory model: when you create thread on the same computer, its storing info onto the RAM
threads share it with the parents, all have access to whatever you made global available. concurrent threads all have access to the same memory
2. message passing: when you have computer1, computer2,  and you have ./a.out, you can send it to computer1 and some commads to computer2,
and you can setup some communication between computer1 and computer2 like web application requesting from one to another.
*/
 
void save_page(const string &url, int second_param)
{
    // simulate a long page fetch
    this_thread::sleep_for(chrono::seconds(second_param));
    string result = "fake content";
 
    lock_guard<mutex> guard(g_pages_mutex);
    cout<<url<<" "<<second_param<<endl;
    g_pages[url] = result;
}
 
int main() 
{
    cout<<"num of cores: "<<thread::hardware_concurrency()<<endl;
    thread t1(save_page, "http://foo", 1);
    thread t2(save_page, "http://bar", 1);

    //write other code you need here
    cout<<"Hello"<<endl; //runs concurrently  with t1 and t2

    t1.join(); //waits for thread 1 to end and then kills it
    t2.join(); //waits for thread 2 to end and then kills it
 
    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) 
        cout << pair.first << " => " << pair.second << '\n';
}