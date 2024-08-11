#include "Reverser.h"
#include <cmath>

// Recursive method which reverses the digits of any given integer
int Reverser::reverseDigit(int value) {
    if (value < 10) {
        return value;
    }
    
    // Gets the number of digits stored in value and stores it in new variable numDigits
    int numDigits = static_cast<int>(std::log10(value)) + 1;

    // Gets the last digit and appends it to the front, then the recursive function sorts the remaining digits
    return (value % 10) * static_cast<int>(std::pow(10, numDigits - 1)) + reverseDigit(value / 10);
}

// Recursive method to reverse string input
std::string Reverser::reverseString(const std::string &characters) {
    if (characters.length() <= 1) {
        return characters;
    }
    
    // Moves the last character to the front, and reverse the remaining chars of the entered string
    return characters.back() + reverseString(characters.substr(0, characters.length() - 1));
}
