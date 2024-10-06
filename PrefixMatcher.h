#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children; // Child nodes to store each bit (0 or 1)
    int routerNumber; // stores the relevant prefix's corresponding to the router number

    TrieNode(); // Constructor
};

class PrefixMatcher {
private:
    TrieNode* root; // Root of the Trie

public:
    PrefixMatcher(); // Constructor

    // Adds a binary IP address and corresponding router number to the Trie
    void insert(std::string address, int routerNumber);

    // For a given address, pick the router with the largest matching prefix
    int selectRouter(std::string networkAddress);
};

#endif // PREFIXMATCHER_H
