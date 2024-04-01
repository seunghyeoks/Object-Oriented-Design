#include "int_node.h"

#include <string>

IntNode::IntNode(int value, Node* left, Node* right) : Node(left, right) {
    value_ = value;
}

void IntNode::Visit(Visitor* visitor) {
    visitor->EnterIntNode(this);
    if (left() != NULL)
        left()->Visit(visitor);
    if (right() != NULL)
        right()->Visit(visitor);
    visitor->ExitIntNode(this);
}

std::string IntNode::value() {
    return std::to_string(value_);
}
