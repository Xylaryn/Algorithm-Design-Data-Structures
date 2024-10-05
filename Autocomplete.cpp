#include "Autocomplete.h"

// TrieNode constructor
TrieNode::TrieNode() {
    isEndOfWord = false;
}

// Autocomplete constructor
Autocomplete::Autocomplete() {
    root = new TrieNode(); // Creates the root node of the Trie
}

// Insert word into Trie function
void Autocomplete::insert(string word) {
    TrieNode* current = root; // Starts traversing from the root node start
    for (char ch : word) { // Iterates of each char in the word
        if (!current->children[ch]) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch]; // Moves to the child node based on the current char
    }
    current->isEndOfWord = true; // Mark the last node as the end of a word
}

// Helper function which collects words recursively
void Autocomplete::collectWords(TrieNode* node, string prefix, vector<string>& results) {
    if (node->isEndOfWord) { 
        results.push_back(prefix); // Adds the current prefix to the vector results
    }
    for (auto& child : node->children) {
        collectWords(child.second, prefix + child.first, results);
    }
}

// Gets the autocomplete suggestions for the given prefix
vector<string> Autocomplete::getSuggestions(string partialWord) {
    TrieNode* current = root; // Starts traversing the list from the root node 
    vector<string> suggestions; // Initialise a vector to store suggestions

    for (char ch : partialWord) {
        if (!current->children[ch]) {
            return suggestions; // No suggestions if prefix doesn't exist
        }
        current = current->children[ch]; // Moves the child node which corresponds to the current char 
    }

    collectWords(current, partialWord, suggestions); // Collects all the words starting from the current node
    return suggestions; // Returns the list of autofill suggestions
}
