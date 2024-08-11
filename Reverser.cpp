#include "Reverser.h"

// Function signature
int Reverser::reverseDigit(int value) {
    if (value < 10) {
        return value;
    }

    // Helper function to reverse the digits in reverse recursively
    return reverseDigitHelper(value, 0);
}

int Reverser::reverseDigitHelper(int value, int reversedValue) {
    // Base case where no digits are left to process
    if (value == 0) {
        return reversedValue;
    }

    // Add the last digit of 'value' to 'reversedValue'
    reversedValue = reversedValue * 10 + (value % 10);

    // Recursively calls upon the helper function to obtain the next digit
    return reverseDigitHelper(value / 10, reversedValue);
}

// Recursive method to reverse a string
std::string Reverser::reverseString(const std::string &characters) {
    if (characters.length() <= 1) {
        return characters;
    }

    // Move the last character to the front, and recursively reverse the rest
    return characters.back() + reverseString(characters.substr(0, characters.length() - 1));
}
