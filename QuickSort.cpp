#include "QuickSort.h"
#include <algorithm>

std::vector<int> QuickSort::sort(std::vector<int> list) {
    quicksort(list, 0, list.size() - 1);
    return list;
}

void QuickSort::quicksort(std::vector<int> &list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quicksort(list, low, pi - 1);
        quicksort(list, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int> &list, int low, int high) {
    int pivotIndex = (low + 2 >= high) ? low : low + 2; // Third element acts as a pivot point
    int pivot      = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]); // Move to pivot end element
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (list[j] <= pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}