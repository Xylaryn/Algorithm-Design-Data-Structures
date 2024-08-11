#include "EfficientTruckloads.h"

EfficientTruckloads::EfficientTruckloads() {
}

// numTrucks method with memoisation
int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    // Check if the result is already in the memo
    if (memo.find(numCrates) != memo.end() && memo[numCrates].find(loadSize) != memo[numCrates].end()) {
        return memo[numCrates][loadSize];
    }

    // If the number of crates is less than or equal to loadSize, then it can fit on one truck
    if (numCrates <= loadSize) {
        return memo[numCrates][loadSize] = 1;
    }

    // Divides the crates into two smaller piles
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;

    // Stores the result in the memo before returning it
    return memo[numCrates][loadSize] = numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
}
