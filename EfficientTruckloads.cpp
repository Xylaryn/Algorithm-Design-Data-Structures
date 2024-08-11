#include "EfficientTruckloads.h"

// Constructor
EfficientTruckloads::EfficientTruckloads() {
    // Initialization if needed
}

// Implementation of the numTrucks method with memoization
int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    // Check if the result is already in the memo
    if (memo.find(numCrates) != memo.end() && memo[numCrates].find(loadSize) != memo[numCrates].end()) {
        return memo[numCrates][loadSize];
    }

    // Base case: If the number of crates is less than or equal to loadSize,
    // then it can fit on one truck.
    if (numCrates <= loadSize) {
        return memo[numCrates][loadSize] = 1;
    }

    // Recursive case: divide the crates into two smaller piles.
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;

    // Store the result in the memo before returning it
    return memo[numCrates][loadSize] = numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
}