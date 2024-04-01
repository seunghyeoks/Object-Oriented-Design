#include "preorder_traversal.h"

void PreorderTraversal::EnterIntNode(IntNode* node) {
    if (result_ == "")
        result_ += "(Int " + node->value() + ")";
    else
        result_ += " :: (Int " + node->value() + ")";
}

void PreorderTraversal::ExitIntNode(IntNode* node) {}

void PreorderTraversal::EnterStringNode(StringNode* node) {
    if (result_ == "")
        result_ += "(String " + node->value() + ")";
    else
        result_ += " :: (String " + node->value() + ")";
}

void PreorderTraversal::ExitStringNode(StringNode* node) {}

std::string PreorderTraversal::Result() {
    return result_;
}
