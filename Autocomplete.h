#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Defines the trienode class
class TrieNode {
  public:
    unordered_map<char, TrieNode *>
         children;    // Maps each character to its corresponding child TrieNode
    bool isEndOfWord; // True/false which indicates the end of a valid word in the Trie

    TrieNode(); // Constructor
};

// Autocomplete class definition
class Autocomplete {
  private:
    TrieNode *root; // Root node of the Trie data structure

    // Helper function to collect all word in the Trie with the given prefix
    void collectWords(TrieNode *node, string prefix, vector<string> &results);

  public:
    Autocomplete(); // Constructor to initialise the AUTOCOMPLETE system and root node
    void           insert(string word);                // Inserts word into the Trie
    vector<string> getSuggestions(string partialWord); // Retrieves all words given the partial word
};

#endif
