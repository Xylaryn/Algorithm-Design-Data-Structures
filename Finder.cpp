#include "Finder.h"
using namespace std;

// Defines the recursive helper function
vector<int> Finder::findSubstrings(string &s1, string &s2, int left, int right) {
    if (left > right) {
        return {}; // Returns empty vector
    }

    int mid = left + (right - left) / 2;
    string prefix = s2.substr(0, mid + 1);

    size_t found = s1.find(prefix);
    vector<int> result;

    if (found != string::npos) {
        // If prefix is found the index is added and the program continues the search in the right
        // half
        result.push_back(found);
        vector<int> rightResult = findSubstrings(s1, s2, mid + 1, right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
    } else {
        // If prefix wasn't found the loop stops and result is filled with -1
        result.push_back(-1);
        for (int i = mid + 1; i <= right; i++) {
            result.push_back(-1);
        }
    }

    // Recursively search in the left half and combine the results in the vector
    vector<int> leftResult = findSubstrings(s1, s2, left, mid - 1);
    result.insert(result.begin(), leftResult.begin(), leftResult.end());
    return result;
}

// Defines the non-recursive version of findSubstrings
vector<int> Finder::findSubstrings(string s1, string s2) {
    return findSubstrings(s1, s2, 0, s2.size() - 1);
}
