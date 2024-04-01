#ifndef _NODE_H_
#define _NODE_H_

#include <string>

#include "visitor.h"

class Node {
 public:
    explicit Node(Node* left, Node* right);
    Node* left();
    Node* right();
    virtual void Visit(Visitor* visitor) = 0;
    virtual std::string value() = 0;
 protected:
    Node* left_;
    Node* right_;
};

#endif  // _NODE_H_
