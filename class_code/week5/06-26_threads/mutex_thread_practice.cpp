#include <iostream>
#include <chrono> // for concurrent programming
#include <map>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

std::map<std::string, std::string> dic;
mutex sue_mutex;

void print(const std::string& url, int sec)
{
    // auto 
    this_thread::sleep_for(chrono::milliseconds(sec));
    std::string result = "something";
    lock_guard<mutex> guard(sue_mutex);

    std::cout << "Thread's is is: " << this_thread::get_id() << " : " << url << " " << sec << std::endl;

    // dic[url] = result; // pair key to its value
}

int main()
{

    // std::cout << "Parent process: number of cores of this computer is: " << thread::hardware_concurrency() << "\n";
    thread t1(print, "http:://github.com/suesui117", 1);
    thread t2(print, "http:://linkedin/suesui117", 1);
    t1.join();
    t2.join();
    

    // std::cout << dic.size() << " size of dic is\n";
    // for (const auto& pair : dic) 
    //     cout << pair.first << " => " << pair.second << '\n';

    return 0;
}
