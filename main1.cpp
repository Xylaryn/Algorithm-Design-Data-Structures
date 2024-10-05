#include "Autocomplete.h"
#include <iostream>
using namespace std;

// Helper function to display suggestions
void printSuggestions(const vector<string>& suggestions) {
    for (const string& suggestion : suggestions) {
        cout << suggestion << " ";
    }
    cout << endl;
}

int main() {
    Autocomplete autocomplete;

    // Test Case 1: Insert words and check autocomplete suggestions
    cout << "Test Case 1: Basic functionality" << endl;
    autocomplete.insert("apple");
    autocomplete.insert("app");
    autocomplete.insert("application");
    autocomplete.insert("apply");

    vector<string> suggestions = autocomplete.getSuggestions("app");
    cout << "Suggestions for 'app': ";
    printSuggestions(suggestions); // Expected output: "app apple application apply"
    cout << endl;

    // Test Case 2: No suggestions for an unrelated prefix
    cout << "Test Case 2: Unrelated prefix" << endl;
    suggestions = autocomplete.getSuggestions("banana");
    cout << "Suggestions for 'banana': ";
    printSuggestions(suggestions); // Expected output: (empty)
    cout << endl;

    // Test Case 3: Check for a specific deeper match
    cout << "Test Case 3: Specific match" << endl;
    suggestions = autocomplete.getSuggestions("appl");
    cout << "Suggestions for 'appl': ";
    printSuggestions(suggestions); // Expected output: "apple application apply"
    cout << endl;

    return 0;
}
