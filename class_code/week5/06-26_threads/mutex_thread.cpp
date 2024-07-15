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
// the same memory, maybe program wants to modify g_pages, threads1 maybe also modifying g_pages. 
// to solve the problem, thread1 puts a lock on g_pages once its done, it unlocks.
// should always use mutex with threads together if have global variables. 

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
    this_thread::sleep_for(chrono::seconds(second_param)); // sleep the function for 1 second
    string result = "fake content";
    
    
    lock_guard<mutex> guard(g_pages_mutex); // where we grab mutex, its global variable, so threads all have access to global variable.
    // mutex itself is a lock, it locks the shared memory globals    cout<<"Thread "<<this_thread::get_id()<<": "<<url<<" "<<second_param<<endl;
    cout<<"Thread: " << this_thread::get_id() << " " << url << " " << second_param <<endl;

    g_pages[url] = result;
}
 
int main()
{
    cout<< "Parent Process: num of cores: " << thread::hardware_concurrency() << endl;
    // 8 cores = 8 cpu
    // parent takes one cpu, so a parent and 7 threads = 8 total.
    // openNP can assign what core to run your cpus on
    // selection sort O(n^2)/8 can be divided by 8, use parallelism for complex things
    // Javascript is a call back language, you create call back functions
    // thread is like a call back, waiting for a click, running in parallel. while you're playing the video.

    thread t1(save_page, "http://foo", 1); // thread is a class
    thread t2(save_page, "http://bar", 1); // save_page is the code you wanna it to run
    // thread takes in function pointers, and parameters of functions you wanna pass
    

    //write other code you need here
    cout<<"Parent Process: "<< "Hello" <<endl; //runs concurrently  with t1 and t2

    // while t1 is running, t2 is running as well. 
    t1.join(); //waits for thread 1 to end and then kills it
    t2.join(); //waits for thread 2 to end and then kills it
   
 
    // t1 and t2 no longer exist
    // safe to access g_pages without lock now, as the threads are joined
    cout<<"Parent Process: ";
    for (const auto& pair : g_pages) 
        cout << pair.first << " => " << pair.second << '\n';
}