#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <limits>

// Linkedlist class
class LinkedList {
  private:
    Node *head; // A pointer to the first node in the linked list

  public:
    // Default constructor to initialise an empty list
    LinkedList();

    // Constructor that initialises a list from an array
    LinkedList(int *array, int len);

    // Destructor to delete current node contained in the list
    ~LinkedList();

    // Method to insert a new node with the value newNum at position pos
    void insertPosition(int pos, int newNum);

    // Method to delete the node at position pos
    bool deletePosition(int pos);

    // Method to return the data of the node at position pos
    int get(int pos);

    // Method to search for the first occurrence of the target contained in the list
    int search(int target);

    // Method to print the list in the format [elem1 elem2 .. elemN]
    void printList();
};

#endif // LINKEDLIST_H
