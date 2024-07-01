/*
    Author: Xin (Sue) Sui
*/
#include <fstream> // file stream
#include <iostream>
#include <string>
#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"

using namespace std;


// You can add more functions here

// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable
(HashTableType &hash_table, const string &words_filename, const string &query_filename, const string &param_flag, const int& R = 89)                  
{
    hash_table.MakeEmpty(); // step 1. clear the HashTable
    std::cout << "\nBefore insertion table size is: " <<hash_table.tableSize() << "\n";
    std::cout << "Before insertion elements count is: " <<hash_table.size() << "\n";


    ifstream words_file(words_filename); // words_file is file handler
    string word;

    while (getline(words_file, word)) // reading into word
    {
        if (!hash_table.Insert(word))
        {
            std::cout << "could not be inserted\n";
        }
    }

    if (param_flag == "quadratic")
        std::cout << "\nThis is quadratic_probing: \n";
    else if(param_flag == "linear")
        std::cout << "\nThis is linear_probing: \n";
    else if(param_flag == "double")
        std::cout << "\nThis is double_hashing: \n";

    std::cout << "number_of_elements: " <<hash_table.size() <<
    "\nsize_of_table: " << hash_table.tableSize() << 
    "\nload_factor: " << hash_table.loadFactor() <<
    "\ncollisions: " << hash_table.totalCollision() <<
    "\navg_collisions: " << hash_table.averageCollision() << "\n\n";

    ifstream query_file(query_filename); // words_file is file handler
    string query;
    while (getline(query_file, query)) // reading into query
    {
        hash_table.Contains(query);
        auto [flag, probe] = hash_table.FindProbe(query);
        if (flag)
            std::cout << query <<" Found " << probe << "\n";
        else
            std::cout << query <<" Not_Found " << probe << "\n";
    }
}



// @argument_count: argc as provided in main
// @argument_list: argv as provided in imain
// Calls the specific testing function for hash table (linear, quadratic, or double).
int testHashingWrapper(int argument_count, char **argument_list) 
{
    const string words_filename(argument_list[1]);
    const string query_filename(argument_list[2]);
    const string param_flag(argument_list[3]);
    int R = 89; // by default int R is 89, unless passed in by user

    if (argument_count == 5) 
    {
        const string rvalue(argument_list[4]);
        R = stoi(rvalue);
    }

    if (param_flag == "linear") 
    {
        // Uncomment below when you have implemented linear probing.
        HashTableLinear<string> linear_probing_table;
        TestFunctionForHashTable(linear_probing_table, words_filename,
        query_filename, param_flag);
    } 

    else if (param_flag == "quadratic") 
    {
        // size_t size = 1000;

        HashTable<string> quadratic_probing_table; // create a hashtable of of string as key
        
        TestFunctionForHashTable(quadratic_probing_table, words_filename,
                    query_filename, param_flag, R);
    } 

    else if (param_flag == "double") 
    {
        cout << "r_value: " << R << endl;
        HashTableDouble<string> double_probing_table(101, R);
        TestFunctionForHashTable(double_probing_table, words_filename,
        			 query_filename, param_flag, R);
    }

    else 
    {
        cout << "Unknown tree type " << param_flag
            << " (User should provide linear, quadratic, or double)" << endl;
    }

    return 0;
}

// Sample main for program create_and_test_hash. DO NOT CHANGE IT.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testHashingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char **argv) 
{
    if (argc != 4 and argc != 5) 
    {
        cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
        cout << "or Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag> <rvalue>" << endl;
        
        return 0;
    }

    testHashingWrapper(argc, argv);

    return 0;
}
