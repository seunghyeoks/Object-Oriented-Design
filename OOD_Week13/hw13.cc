#include <string>
#include <vector>
#include <iostream>

#include "int_node.h"
#include "string_node.h"
#include "preorder_traversal.h"
#include "postorder_traversal.h"

int main() {
    Node* n33 = new IntNode(0, nullptr, nullptr);
    Node* n34 = new StringNode("bye", nullptr, nullptr);

    Node* n21 = new StringNode("hi", nullptr, nullptr);
    Node* n22 = new IntNode(-42, n33, n34);

    Node* n1 = new IntNode(3, n21, n22);

    PreorderTraversal pre_visitor;
    PostorderTraversal pos_visitor;

    n1->Visit(&pre_visitor);
    n1->Visit(&pos_visitor);

    std::cout << pre_visitor.Result() << std::endl;
    std::cout << pos_visitor.Result() << std::endl;

    return 0;
}
