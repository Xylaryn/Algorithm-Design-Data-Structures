#ifndef NODE_H
#define NODE_H

// Node class representing sole element in a linked list
class Node {
  private:
    // Private member variables for encapsulation
    int   data; // Data contained in the node
    Node *link; // A pointer to the next node in the list

  public:
    // Constructor to initialise the node with data and set the link to nullptr
    Node(int data);

    // Getter for data in the node
    int getData() const;

    // Setter for the data in the node
    void setData(int data);

    // Getter for the link node
    Node *getLink() const;

    // Setter for the link node
    void setLink(Node *link);
};

#endif // NODE_H