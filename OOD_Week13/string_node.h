#ifndef _STRING_NODE_H_
#define _STRING_NODE_H_

#include <string>

#include "node.h"
#include "visitor.h"

class StringNode : public Node {
 public:
    explicit StringNode(std::string value, Node* left, Node* right);
    void Visit(Visitor* visitor);
    std::string value();
 private:
    std::string value_;
};

#endif  // _STRING_NODE_H_
