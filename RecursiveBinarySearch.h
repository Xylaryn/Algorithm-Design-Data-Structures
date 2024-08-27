#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
    public: 
    bool search(std::vector<int> list, int target);

    private:
    bool binarySearch(std::vector<int>& list, int target, int low, int high);
};

#endif // RECURSIVEBINARYSEARCH