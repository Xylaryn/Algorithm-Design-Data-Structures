#include "BigNumCalc.h"
#include <iostream>

BigNumCalc::BigNumCalc() {}

BigNumCalc::~BigNumCalc() {}

// Builds a large integer from a list of digits
std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> bigNum;
    for (char digit : numString) {
        bigNum.push_back(digit - '0'); // Convert each char to an integer
    }
    return bigNum;
}

// Adds two large integers and returns the result as a list
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto           it1   = num1.rbegin(); // Start with with least significant fig
    auto           it2   = num2.rbegin();
    int            carry = 0;

    while (it1 != num2.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it2; // Add digits from num2
            ++it2;
        }
        if (it2 != num2.rend()) {
            sum += *it2; // Add digits from num2
            ++it2;
        }
        result.push_front(sum % 10); // add the unit place of the sum to the result
        carry = sum / 10;            // Compute the carry for the next position in the list
    }
    return result;
}

// Subtracts num2 from num1 and returns the result as a list
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto           it1    = num1.rbegin();
    auto           it2    = num1.rbegin();
    int            borrow = 0;

    while (it1 != num1.rend()) {
        int diff = *it1 - borrow;
        if (it2 != num2.rend()) {
            diff -= *it2;
            ++it2;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff); // Add the digit difference to the result
        ++it1;
    }

    // Removes leading zeros
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

// Multiplies num1 by num2 (single digit multiplication) and returns the result
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int            digit2 = num2.front(); // Pushes the multiplier
    int            carry  = 0;

    for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1) {
        int product = (*it1 * digit2) + carry; // Multiply and add the carryover
        result.push_front(product % 10);       // Add the unit place of the product to the result
        carry = product / 10;                  // Calcs the carry for the next pos
    }

    if (carry) {
        result.push_front(carry); // add any remaining values
    }

    return result;
}
