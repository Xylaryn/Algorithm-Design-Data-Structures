#include "PrefixMatcher.h"

// Constructor for TrieNode class
TrieNode::TrieNode() : routerNumber(-1) {
    // Sets the router number to -1 (because there isn't a router yet)
}

// PrefixMatcher class constructor
PrefixMatcher::PrefixMatcher() {
    root = new TrieNode(); // Initialises root node
}

// Adds a binary address and associates it with a router number in the Trie
void PrefixMatcher::insert(std::string address, int routerNumber) {
    TrieNode* current = root;
    for (char bit : address) {
        // If a TrieNode doesn't already exist for each bit, create a new one
        if (current->children.find(bit) == current->children.end()) {
            current->children[bit] = new TrieNode();
        }
        current = current->children[bit];
    }
    current->routerNumber = routerNumber; // Add the router number to the address at the end
}

// Returns the router matching the provided IP and longest prefix
int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNode* current = root;
    int bestMatch = -1; // Stores the router that matches the longest prefix

    // Traverses the Trie following the bits of the network address
    for (char bit : networkAddress) {
        if (current->routerNumber != -1) {
            bestMatch = current->routerNumber; // If a router is located, update the best match
        }
        if (current->children.find(bit) == current->children.end()) {
            break; // Terminates the function if no additional matching bits are discovered
        }
        current = current->children[bit];
    }

    return bestMatch; // Returns the best match
}
