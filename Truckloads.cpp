#include <iostream>
#include "Truckloads.h"  

// numTrucks method
int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    }
    
    // Recursive case which divides the crates into two smaller piles
    int half1 = numCrates / 2;
    int half2 = numCrates - half1;
    
    // Calcs the sum of the trucks required for both piles
    return numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
}
