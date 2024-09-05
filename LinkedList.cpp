#include "LinkedList.h"
#include <iostream>
#include <limits>

// Initialises an empty linked list
LinkedList::LinkedList() : head(nullptr) {}

// Each element in the array is added to the list in order
LinkedList::LinkedList(int *array, int len) : head(nullptr) {
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]); // Insert each array element into the list
    }
}

// Deletes nodes in the list
LinkedList::~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->getLink();
        delete current; // Delete the current node
        current = next; // Move to the next node
    }
}

// Inserts a new node containing newNum at position pos
void LinkedList::insertPosition(int pos, int newNum) {
    Node *newNode = new Node(newNum);

    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node *current = head;
    // finds the correct position within the linkedlis
    for (int i = 1; i < pos - 1 && current->getLink() != nullptr; i++) {
        current = current->getLink();
    }

    // Insert the new node at the correct position
    newNode->setLink(current->getLink());
    current->setLink(newNode);
}

// Deletes the node at position pos from the list
bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || head == nullptr)
        return false; // Invalid

    Node *temp;

    if (pos == 1) { // Deleting the head node
        temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node *current = head;
    // Traverse the list to find the node just before the one which gets removed from list
    for (int i = 1; i < pos - 1 && current->getLink() != nullptr; i++) {
        current = current->getLink();
    }

    if (current->getLink() == nullptr)
        return false; // Position out of bounds

    temp = current->getLink();         // Node to be deleted
    current->setLink(temp->getLink()); // Remove it from the list
    delete temp;                       // Free the memory
    return true;
}

// Returns the data of the node at position pos
int LinkedList::get(int pos) {
    if (pos < 1)
        return std::numeric_limits<int>::max(); // Invalid position

    Node *current = head;
    // Traverse the list to find the node at the given position
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->getLink();
    }

    if (current == nullptr)
        return std::numeric_limits<int>::max(); // Position out of bounds

    return current->getData();
}

// Searches for the first occurrence of target in the list, returns -1 if not in list
int LinkedList::search(int target) {
    Node *current = head;
    int   pos     = 1;

    // Traverse the list to find the target
    while (current != nullptr) {
        if (current->getData() == target)
            return pos;
        current = current->getLink();
        pos++;
    }

    return -1; // Target not found
}

// Prints the list in the format [elem1 elem2 ... elemN]
void LinkedList::printList() {
    Node *current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->getData();
        if (current->getLink() != nullptr)
            std::cout << " ";
        current = current->getLink();
    }
    std::cout << "]" << std::endl;
}
