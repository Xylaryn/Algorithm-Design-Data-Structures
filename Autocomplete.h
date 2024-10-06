#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <unordered_map>
#include <vector>

namespace AutocompleteNS {

class TrieNode {
  public:
    std::unordered_map<char, TrieNode *>
         children;    // Creates child nodes each of which corresponds to a specific letter
    bool isEndOfWord; // Indicates a word's end

    TrieNode(); // Constructor
};

class Autocomplete {
  private:
    TrieNode *root; // Root of the Trie

    // A helper method that collects all words beginning at a certain node
    void findAllWords(TrieNode *node, std::string currentWord, std::vector<std::string> &results);

  public:
    Autocomplete(); // Constructor

    // Adds the word to the Trie
    void insert(std::string word);

    // Based on a partial word this function returns a vector of recommendations
    std::vector<std::string> getSuggestions(std::string partialWord);
};

} // namespace AutocompleteNS

#endif // AUTOCOMPLETE_H