/* Author: Xin (Sue) Sui
spell_check.cc: A simple spell checker.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <quadratic_probing.h>
#include <linear_probing.h>
#include <double_hashing.h>

using namespace std;

// You can add more functions here.

// Creates and fills double hashing hash table with all words from
// dictionary_file
HashTableDouble<string> MakeDictionary(const string &dictionary_file) 
{
    HashTableDouble<string> dictionary_hash;
    dictionary_hash.MakeEmpty(); // step 1. clear the HashTable
    std::cout << "\nBefore insertion table size is: " << dictionary_hash.tableSize() << "\n";
    std::cout << "Before insertion elements count is: " << dictionary_hash.size() << "\n";


    ifstream words_file(dictionary_file); // words_file is file handler
    string word;

    while (getline(words_file, word)) // reading into word
    {
        // Fill dictionary_hash.
        if (!dictionary_hash.Insert(word))
        {
            std::cout << "could not be inserted\n";
        }
    }

    std::cout << "number_of_elements: " << dictionary_hash.size() <<
    "\nsize_of_table: " << dictionary_hash.tableSize() << 
    "\nload_factor: " << dictionary_hash.loadFactor() <<
    "\ncollisions: " << dictionary_hash.totalCollision() <<
    "\navg_collisions: " << dictionary_hash.averageCollision() << "\n\n";


    return dictionary_hash;
}

// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(const HashTableDouble<string>& dictionary,
		  const string &document_file) 
{
  // open the file, parse each word,
  // find it in the dictionary, if exists, and if correct
    ifstream words_file(document_file); // words_file is file handler
    string line;

    size_t start = line.find_first_not_of(" \t\r\n");
    size_t end = line.find_last_not_of(" \t\r\n");
    // Read each line from the file
    std::regex pattern("\\s+");


    while (getline(words_file, line)) {
        stringstream ss(line);
        string word;

        
        while (ss >> word)
        {
          if(dictionary.Contains(word))
            std::cout << "Word is: ->>> " << word << " " << dictionary.Contains(word) << " \n";
        }
    }

}

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) 
{
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);

    // Call functions implementing the assignment requirements.
    HashTableDouble<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}



// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"
         << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}
