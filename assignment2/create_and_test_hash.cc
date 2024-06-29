/*
    Author: Xin (Sue) Sui
*/
#include <fstream> // file stream
#include <iostream>
#include <string>
#include "quadratic_probing.h"
using namespace std;


// Uncomment when you implemented linear probing & double hashing
// #include "linear_probing.h"
// #include "double_hashing.h"

// You can add more functions here

// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table,
			      const string &words_filename,
			      const string &query_filename)                  
{
    std::cout << "hello \n";
    hash_table.MakeEmpty();
    std::cout << "Current size is: " <<hash_table.size() << "\n";
    
    ifstream words_file(query_filename); // words_file is file handler
    string word;

    while (getline(words_file, word)) // reading into word
    {
        hash_table.Insert(word);
    }

    std::cout << "YOOOOOO Current size is: " <<hash_table.size() << "\n";

    std::cout << hash_table[0] << "\n";
    int counter = 0;
    for(int i = 0; i < hash_table.size(); ++i)
    {
        // if(hash_table[i] == "")
        // {
        //     // std::cout << hash_table[i] << "\n";
        //     ++counter;
        // }
       
    //    else{
        std::cout << hash_table[i] << "\n";
       }
        // ++counter;
    

    std::cout << counter << "\n";

    std::cout << "table size is: " << hash_table.tableSize();
    std::cout << "\nelement size is: " << hash_table.size();



    
    

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
        // HashTableLinear<string> linear_probing_table;
        // TestFunctionForHashTable(linear_probing_table, words_filename,
        // query_filename);
    } 

    else if (param_flag == "quadratic") 
    {
        HashTable<string> quadratic_probing_table; // create a hashtable of of string as key
        TestFunctionForHashTable(quadratic_probing_table, words_filename,
                    query_filename);
    } 
    else if (param_flag == "double") 
    {
        cout << "r_value: " << R << endl;
            // Uncomment below when you have implemented double hashing.
        // HashTableDouble<string> double_probing_table;
        // TestFunctionForHashTable(double_probing_table, words_filename,
        // 			 query_filename);
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
