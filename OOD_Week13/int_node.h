#ifndef _INT_NODE_H_
#define _INT_NODE_H_

#include <string>

#include "node.h"
#include "visitor.h"

class IntNode : public Node {
 public:
    explicit IntNode(int value, Node* left, Node* right);
    void Visit(Visitor* visitor);
    std::string value();
 private:
    int value_;
};

#endif  // _INT_NODE_H_
