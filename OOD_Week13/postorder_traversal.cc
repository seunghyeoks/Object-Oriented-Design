#include "postorder_traversal.h"

void PostorderTraversal::EnterIntNode(IntNode* node) {}

void PostorderTraversal::ExitIntNode(IntNode* node) {
    if (result_ == "")
        result_ += "(Int " + node->value() + ")";
    else
        result_ += " :: (Int " + node->value() + ")";
}

void PostorderTraversal::EnterStringNode(StringNode* node) {}

void PostorderTraversal::ExitStringNode(StringNode* node) {
    if (result_ == "")
        result_ += "(String " + node->value() + ")";
    else
        result_ += " :: (String " + node->value() + ")";
}

std::string PostorderTraversal::Result() {
    return result_;
}
