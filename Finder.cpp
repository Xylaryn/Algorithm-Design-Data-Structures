#include "Finder.h"
#include <vector>

using namespace std;

// Function signature
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    int n = s1.length(); // Length of main string s1
    int m = s2.length(); // Length of the prefix string s2

    // Iterates over each prefix length of s2
    for (int i = 1; i <= m; i++) {
        string current_prefix = s2.substr(0, i);

        // Boolean value to track whether the current prefix was found in s1
        bool found = false;

        // Iterates over all possible starting positions in s1
        for (int j = 0; j <= n - i; ++j) {
            if (s1.compare(j, i, current_prefix) == 0) { // Compares the substring of s1 
            // starting at index j with the current prefix
                result.push_back(j); // If prefix is found store its starting position
                found = true;
                break; // Stops search since prefix was already found
            }
        }

        // if the current prefix was not found in s1 record -1 and terminates loop given that larger
        // prefixes will not be found
        if (!found) {
            result.push_back(-1);
            break;
        }
    }

    // If the loop breaks early in the step above indicating a prefix wasn't found the remaining
    // positions in the vector are set to -1 which indicates that no more valid prefixes exist in
    // the string
    while (result.size() < m) {
        result.push_back(-1);
    }

    // Returns the result of the algorithm
    return result;
}
