// Heap.tpp

#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template<typename T>
class Heap {
    private:
        // Define an alias for the underlying data structure (vector) and its size type
        typedef std::vector<T> heap;
        typedef heap::size_type heapIndex;
        
        // Internal storage for the heap elements
        heap tree;
        
        // Helper functions to calculate child and parent node positions based on index
        heapIndex getLeftChildPosition(heapIndex i) {
            // Left child is at index 2 * i + 1 (adjusted for 0-based indexing)
            return (2 * i + 1);
        }
        
        heapIndex getRightChildPosition(heapIndex i) {
            // Right child is at index (2 * i) + 2 (adjusted for 0-based indexing)
            return (2 * i + 2);
        }
        
        heapIndex getParentPosition(heapIndex i) {
            // Parent is at (i - 1) / 2 using integer division
            return (i - 1) / 2;
        }
        
        // Function to maintain the min-heap property by swapping elements down the tree
        heapIndex heapifyDown(heapIndex index) {
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            T leftChild = (leftChildIndex < this->tree.size()) ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();
            
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size()) ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();
            
            // Find the child with the smaller value
            heapIndex minValueChildIndex = (leftChild < rightChild) ? leftChildIndex : rightChildIndex;
            
            // If a child has a smaller value, swap it with the parent and recursively heapify down
            if (minValueChildIndex < this->tree.size() && this->tree[minValueChildIndex] < this->tree[index]) {
                std::swap(this->tree[minValueChildIndex], this->tree[index]);
                return heapifyDown(minValueChildIndex);
            }
            return index;
        }

        // Function to restore the min-heap property by moving elements up the tree
        void heapifyUp(heapIndex index) {
            while (index > 0 && tree[index] < tree[getParentPosition(index)]) {
                std::swap(tree[index], tree[getParentPosition(index)]);
                index = getParentPosition(index);
            }
        }
    
    public:
        // Default constructor
        Heap() = default;

        // Constructor that takes a vector and builds a heap from its elements
        Heap(const std::vector<T>& values) {
            for (const T& value : values) {
                insert(value);  // Insert each element to maintain the heap property
            }
        }

        // Check if the heap is empty
        bool isHeapEmpty() {
            return tree.empty();
        }
        
        // Insert an element into the heap
        void insert(T element) {
            tree.push_back(element); // Adds the new element at the end
            heapifyUp(tree.size() - 1); // Restores min-heap property
        }

        // Remove an element from the heap
        void remove(T value) {
            // Find the value within the heap
            heapIndex indexToRemove = 0; // Fixed missing semicolon
            for (heapIndex i = 0; i < tree.size(); ++i) { 
                if (tree[i] == value) {
                    indexToRemove = i;
                    break;
                }
            }
            if (indexToRemove == tree.size()) return; // If value isn't found

            // Swaps with the last element and remove from the tree
            std::swap(tree[indexToRemove], tree.back());
            tree.pop_back();

            // Restores min-heap
            if (indexToRemove < tree.size()) {
                heapifyDown(indexToRemove);
                heapifyUp(indexToRemove);
            }
        }

        // Get the minimum element (in this case, the minimum element of the min-heap)
        T getMin() {
            if (tree.size() > 0) {
                return tree[0]; // Returns the root which should be the min element
            }
            throw std::out_of_range("Heap is empty");
        }
};

#endif /* Tree_hpp */
