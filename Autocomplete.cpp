#include "Autocomplete.h"
#include <iostream>

// Class TrieNode constructor declaration
TrieNode::TrieNode() {
    isEndOfWord = false; // Sets the node's initial value to false
}

// Constructor for Autocomplete class
Autocomplete::Autocomplete() {
    root = new TrieNode(); // Initialises root node
}

// Adds a word to the Trie
void Autocomplete::insert(std::string word) {
    TrieNode* current = root;
    for (char c : word) {
        // If the character is missing, create a new TrieNode
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true; // Indicates the strings end
}

// A helper function to discover every word beginning at the current node recursively
void Autocomplete::findAllWords(TrieNode* node, std::string currentWord, std::vector<std::string>& results) {
    if (node->isEndOfWord) {
        results.push_back(currentWord); // Add word to results if it's a complete string
    }
    // Recursively search for all possible words
    for (auto it : node->children) {
        findAllWords(it.second, currentWord + it.first, results);
    }
}

// Returns every suggestion that fits the provided partial word
std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    TrieNode* current = root;
    std::vector<std::string> results;

    // Traverses the Trie to reach the end of the partial word
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            return results; // Return empty if no match found
        }
        current = current->children[c];
    }

    // Compiles a list of all words that include the given prefix
    findAllWords(current, partialWord, results);
    return results;
}
