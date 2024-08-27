#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <sstream> // Standard Template Lib

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<int>  list;
    int               number;
    while (ss >> number) {
        list.push_back(number);
    }

    QuickSort sorter;
    list = sorter.sort(list);

    RecursiveBinarySearch searcher;
    bool                  found = searcher.search(list, 1);

    std::cout << (found ? "true" : "false");
    for (int num : list) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    return 0;
}