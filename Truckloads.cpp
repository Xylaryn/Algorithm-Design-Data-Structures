#include <iostream>

class Truckloads {
public:
    int numTrucks(int numCrates, int loadSize) {
        if (numCrates <= loadSize) {
            return 1;
        }
        
        // Recursive case which divides the crates into two smaller piles
        int half1 = numCrates / 2;
        int half2 = numCrates - half1;
        
        // Calcs the sum of the trucks required for both piles
        return numTrucks(half1, loadSize) + numTrucks(half2, loadSize);
    }
};

int main() {
    Truckloads tl;
    std::cout << tl.numTrucks(14, 3) << std::endl; // Must return 6
    std::cout << tl.numTrucks(15, 1) << std::endl; // Must return 15
    std::cout << tl.numTrucks(1024, 5) << std::endl; // Must return 256
    return 0;
}
