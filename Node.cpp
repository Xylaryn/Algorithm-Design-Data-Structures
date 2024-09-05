#include "Node.h"

// Constructor which initialises the nodes data and sets the link to nullptr
Node::Node(int data) : data(data), link(nullptr) {}

// Returns the data from the node
int Node::getData() const {
    return data;
}

// Sets the data for the node
void Node::setData(int data) {
    this->data = data;
}

// Pointer to the next node
Node *Node::getLink() const {
    return link;
}

// Sets the link to the next node
void Node::setLink(Node *link) {
    this->link = link;
}