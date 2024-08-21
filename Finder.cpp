#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    string prefix = ""; // Empty prefix

    // Iterates over all chars in s2 to build prefix
    for (size_t i = 0; i < s2.size(); i++) {
        prefix += s2[i];                // Increment the prefix by one char
        size_t found = s1.find(prefix); // Search for the current prefix in s1

        if (found != string::npos) {
            // If the prefix is found the starting index is stored in result
            result.push_back(found);
        } else {
            // If the prefix isn't found -1 will be stored and the loop will 
            // terminate because no larger prefix will be found
            result.push_back(-1);
            break;
        }
    }

    // Fills the rest with -1 if prefix isn't found
    while (result.size() < s2.size()) {
        result.push_back(-1);
    }

    return result;
}
