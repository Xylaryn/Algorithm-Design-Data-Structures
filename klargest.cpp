#include <queue>
#include <vector>
#include <functional>

int kth_largest(std::vector<int> values, int k) {
    // Min-heap which stores the largest elements of k
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    // Process each element stored in the input vector
    for (int value : values) {  // Fixed typo, changed `value` to `values`
        min_heap.push(value);
        // If the heap exceeds the size of int k, remove the smallest element
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // Returns the top element of the min-heap which will be the kth largest element
    return min_heap.top();
}
