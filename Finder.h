#ifndef FINDER_H
#define FINDER_H
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class Finder {
  public:
    // Declares non-recursive version of findSubstrings
    std::vector<int> findSubstrings(std::string s1, std::string s2);

  private:
    // Declares recursive function
    std::vector<int> findSubstrings(std::string &s1, std::string &s2, int left, int right);
};

#endif
