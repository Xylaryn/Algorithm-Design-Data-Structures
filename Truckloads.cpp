#include <iostream>

int numTrucks(int numItems, int truckCapacity) {
    if (numItems <= truckCapacity) {
        return 1;
    }

    // Splits the number of items into two groups
    int half1 = numItems / 2;
    int half2 = numItems - half1;

    return numTrucks(half1, truckCapacity) + numTrucks(half2, truckCapacity);
}

int main() {
    int numItems = 14;
    int truckCapacity = 3;

    std::cout << "Number of trucks needed: " << numTrucks(numItems, truckCapacity) << std::endl;
    return 0;
}
    