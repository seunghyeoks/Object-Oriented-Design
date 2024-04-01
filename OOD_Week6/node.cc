#include "node.h"

Node::Node(const Node* left, const Node* right) {
    Node::left_ = left;
    Node::right_ = right;
}

const Node* Node::left() const {
    return Node::left_;
}

const Node* Node::right() const {
    return Node::right_;
}

Node::~Node() {}
