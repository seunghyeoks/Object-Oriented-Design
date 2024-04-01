#ifndef _POSTORDER_TRAVERSAL_H_
#define _POSTORDER_TRAVERSAL_H_

#include <string>

#include "int_node.h"
#include "string_node.h"

class PostorderTraversal : public Visitor {
 public:
    void EnterIntNode(IntNode* node);
    void ExitIntNode(IntNode* node);
    void EnterStringNode(StringNode* node);
    void ExitStringNode(StringNode* node);
    std::string Result();
 private:
    std::string result_;
};

#endif  // _POSTORDER_TRAVERSAL_H_
