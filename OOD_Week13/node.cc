#include "node.h"

Node::Node(Node* left, Node* right) {
    left_ = left;
    right_ = right;
}

Node* Node::left() {
    return left_;
}

Node* Node::right() {
    return right_;
}
