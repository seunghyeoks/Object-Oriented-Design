#include "string_node.h"

#include <string>

StringNode::StringNode(std::string value, Node* left, Node* right)
          : Node(left, right) { value_ = value; }

void StringNode::Visit(Visitor* visitor) {
    visitor->EnterStringNode(this);
    if (left() != NULL)
        left()->Visit(visitor);
    if (right() != NULL)
        right()->Visit(visitor);
    visitor->ExitStringNode(this);
}


std::string StringNode::value() {
    return value_;
}
