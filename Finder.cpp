#include "Finder.h"
// Best case: the time complexity of the following optimised algorithm is O(n) given if the first
// few prefixes are found and then a prefix is not found early leading the code to terminte the loop
// checks early Worst case: the time complexity of the algorithm is O(n * m), where n is the length
// of0 s2 and m is the length of s1 which only occurs when each prefix of s2 is found in s1 thus all
// substrings are checked hurting efficiency

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    string current_prefix = "";

    for (size_t i = 1; i <= s2.size(); i++) {
        current_prefix += s2[i - 1];
        size_t found = s1.find(current_prefix);
        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
            break; // if the required prefix is not found, there is no need to check for larger
                   // prefixes
        }
    }

    // Fills the remaining entries with -1 since larger prefixes will not be found by using a while
    // loop
    while (result.size() < s2.size()) {
        result.push_back(-1);
    }

    return result;
}
