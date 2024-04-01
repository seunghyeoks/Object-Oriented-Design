#include "tree_util.h"

#include <iostream>
#include <string>

#include "int_node.h"
#include "string_node.h"

TreeUtil* TreeUtil::instance_ = NULL;

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
    if (instance_ == NULL) {
        instance_ = new TreeUtil;
    }
    return instance_;
}



std::string PreOrderTraversal(const Node* node, int i) {
    std::string result;
    if (node != NULL) {
        if (node == dynamic_cast<const IntNode*>(node)) {
            result += ",";
            result += std::to_string(
                dynamic_cast<const IntNode*>(node)->value());
        } else {
            result += ",";
            result += dynamic_cast<const StringNode*>(node)->value();
        }
        result += PreOrderTraversal(node->left(), 1);
        result += PreOrderTraversal(node->right(), 1);
    }

    return result;
}

const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
    std::string Result = ::PreOrderTraversal(node, 1);

    Result.erase(0, 1);

    return Result;
}




std::string InOrderTraversal(const Node* node, int i) {
    std::string result;
    if (node != NULL) {
        result += InOrderTraversal(node->left(), 1);
        if (node == dynamic_cast<const IntNode*>(node)) {
            result += ",";
            result += std::to_string(
                dynamic_cast<const IntNode*>(node)->value());
        } else {
            result += ",";
            result += dynamic_cast<const StringNode*>(node)->value();
        }
        result += InOrderTraversal(node->right(), 1);
    }

    return result;
}

const std::string TreeUtil::InOrderTraversal(const Node* node) const {
    std::string Result = ::InOrderTraversal(node, 1);

    Result.erase(0, 1);

    return Result;
}




std::string PostOrderTraversal(const Node* node, int i) {
    std::string result;
    if (node != NULL) {
        result += PostOrderTraversal(node->left(), 1);
        result += PostOrderTraversal(node->right(), 1);
        if (node == dynamic_cast<const IntNode*>(node)) {
            result += ",";
            result += std::to_string(
                dynamic_cast<const IntNode*>(node)->value());
        } else {
            result += ",";
            result += dynamic_cast<const StringNode*>(node)->value();
        }
    }

    return result;
}

const std::string TreeUtil::PostOrderTraversal(const Node* node) const {
    std::string Result = ::PostOrderTraversal(node, 1);

    Result.erase(0, 1);

    return Result;
}
