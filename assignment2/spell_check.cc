/* Author: Xin (Sue) Sui
spell_check.cc: A simple spell checker.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hashing.h"

using namespace std;


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


    std::cout << "\nAfter insertion table size is: " << dictionary_hash.tableSize() << "\n";
    std::cout << "After insertion elements count is: " << dictionary_hash.size() << "\n\n";
    return dictionary_hash;
}



// case 1: adding one character in any possible position
void addChar(const std::string& token, const HashTableDouble<std::string>& dictionary) {
    std::cout << "** " << token << " -> " << " case a\n";

    std::string new_word;

    for (size_t i = 0; i <= token.length(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            new_word = token.substr(0, i) + c + token.substr(i);
            // std::cout << new_word << " hi im the new word\n";

            // // Check if the modified word exists in the dictionary
            // if ( dictionary.Contains(new_word) ) {
            //     std::cout << "Misspelled word: " << token << ", Corrected to: " << new_word << "\n";
            //     return; // Stop after finding the first correction
            // }
        }
    }

    // If no corrections found, print that the word was not found
    std::cout << "not found ->>> " << token << "\n";
}



void removeChar(const std::string& token, const HashTableDouble<std::string>& dictionary)
{
      std::cout << "** " << token << " -> " << " case b\n";

}

void swapChar(const std::string& token, const HashTableDouble<std::string>& dictionary)
{
    std::cout << "** " << token << " -> " << " case c\n";

}



// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(const HashTableDouble<std::string>& dictionary, const std::string& document_file)
{
    std::ifstream words_file(document_file);
    std::string line;

    while (std::getline(words_file, line)) {
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            // Convert to lowercase using lambda func
            std::transform(word.begin(), word.end(), word.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            // Remove punctuations
            std::vector<char> punctuations = { '\'', '.', ',', '!', '"', ':', ';' };
            for (char punctuation : punctuations)
            {
                word.erase(std::remove(word.begin(), word.end(), punctuation), word.end());
            }

            // Split by '--' and process tokens
            std::istringstream iss(word);
            std::string token;
            while (std::getline(iss, token, '-')) 
            {
                if (!token.empty()) 
                {
                  // Check if token is in the dictionary
                  if (dictionary.Contains(token)) 
                  {
                      // std::cout << token << " is CORRECT\n";
                  }
                  else
                  {
                    // else should try 3 different methods:
                    std::cout << token << " is CORRECT\n";

                    addChar(token, dictionary);
                    removeChar(token, dictionary);
                    swapChar(token, dictionary);

                  }
                }
            }
        }
    }
} // end spell checker




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
