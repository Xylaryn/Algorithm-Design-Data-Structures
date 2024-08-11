#ifndef EFFICIENT_TRUCKLOADS_H
#define EFFICIENT_TRUCKLOADS_H

#include <unordered_map> // Required for a container which stores previous values

class EfficientTruckloads {
public:
    EfficientTruckloads();

    // Function signature which calculates the number of trucks required with memoisation 
    int numTrucks(int numCrates, int loadSize);

private:
    // Map which stores previously computed results
    std::unordered_map<int, std::unordered_map<int, int>> memo;
};

#endif // EFFICIENT_TRUCKLOADS_H
