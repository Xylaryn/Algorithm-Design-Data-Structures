#ifndef EFFICIENT_TRUCKLOADS_H
#define EFFICIENT_TRUCKLOADS_H

#include <unordered_map>

class EfficientTruckloads {
public:
    // Constructor
    EfficientTruckloads();

    // Method to calculate the number of trucks required with memoization
    int numTrucks(int numCrates, int loadSize);

private:
    // A map to store previously computed results (memoization)
    std::unordered_map<int, std::unordered_map<int, int>> memo;
};

#endif // EFFICIENT_TRUCKLOADS_H