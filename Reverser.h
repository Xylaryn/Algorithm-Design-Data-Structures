#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    // Function Signature
    int reverseDigit(int value);

    // Method to reverse a string using recursion
    std::string reverseString(const std::string &characters);
};

#endif // REVERSER_H