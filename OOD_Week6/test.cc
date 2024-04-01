#include "gtest/gtest.h"
#include "node.h"
#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"


class TreeTest : public ::testing::Test {
 public:
  TreeTest() :
    int_node(0, new IntNode(1, NULL, NULL), new IntNode(2, NULL, NULL)) {
    }
 protected:
  void SetUp() override {};
  void TearDown() override {};
  TreeUtil* treeUtil;
  IntNode int_node;
};


TEST_F(TreeTest, PreOrder_test1) {
    std::string result = treeUtil->PreOrderTraversal(&int_node);

    EXPECT_EQ(result, "0,1,2");
}

TEST_F(TreeTest, PreOrder_test2) {
    StringNode* c = new StringNode("3c", NULL, NULL);
    StringNode* d = new StringNode("4d", NULL, NULL);
    IntNode* e = new IntNode(5, NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);

    StringNode* a = new StringNode("1a", c, d);
    IntNode* b = new IntNode(2, e, f);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->PreOrderTraversal(root);
    EXPECT_EQ(result, "0,1a,3c,4d,2,5,6f");
}

TEST_F(TreeTest, PreOrder_test3) {
    StringNode* e = new StringNode("", NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);
    IntNode* g = new IntNode(7, NULL, NULL);
    StringNode* i = new StringNode("9i", NULL, NULL);

    StringNode* c = new StringNode("3c", e, f);
    IntNode* d = new IntNode(4, g, NULL);
    IntNode* h = new IntNode(8, NULL, i);

    StringNode* a = new StringNode("1a", c, d);
    StringNode* b = new StringNode("2b", NULL, h);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->PreOrderTraversal(root);
    EXPECT_EQ(result, "0,1a,3c,,6f,4,7,2b,8,9i");
}


TEST_F(TreeTest, InOrder_test1) {
    std::string result = treeUtil->InOrderTraversal(&int_node);

    EXPECT_EQ(result, "1,0,2");
}

TEST_F(TreeTest, InOrder_test2) {
    StringNode* c = new StringNode("3c", NULL, NULL);
    StringNode* d = new StringNode("4d", NULL, NULL);
    IntNode* e = new IntNode(5, NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);

    StringNode* a = new StringNode("1a", c, d);
    IntNode* b = new IntNode(2, e, f);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->InOrderTraversal(root);
    EXPECT_EQ(result, "3c,1a,4d,0,5,2,6f");
}

TEST_F(TreeTest, InOrder_test3) {
    StringNode* e = new StringNode("", NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);
    IntNode* g = new IntNode(7, NULL, NULL);
    StringNode* i = new StringNode("9i", NULL, NULL);

    StringNode* c = new StringNode("3c", e, f);
    IntNode* d = new IntNode(4, g, NULL);
    IntNode* h = new IntNode(8, NULL, i);

    StringNode* a = new StringNode("1a", c, d);
    StringNode* b = new StringNode("2b", NULL, h);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->InOrderTraversal(root);
    EXPECT_EQ(result, ",3c,6f,1a,7,4,0,2b,8,9i");
}


TEST_F(TreeTest, PostOrder_test1) {
    std::string result = treeUtil->PostOrderTraversal(&int_node);
    EXPECT_EQ(result, "1,2,0");
}

TEST_F(TreeTest, PostOrder_test2) {
    StringNode* c = new StringNode("3c", NULL, NULL);
    StringNode* d = new StringNode("4d", NULL, NULL);
    IntNode* e = new IntNode(5, NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);

    StringNode* a = new StringNode("1a", c, d);
    IntNode* b = new IntNode(2, e, f);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->PostOrderTraversal(root);
    EXPECT_EQ(result, "3c,4d,1a,5,6f,2,0");
}

TEST_F(TreeTest, PostOrder_test3) {
    StringNode* e = new StringNode("", NULL, NULL);
    StringNode* f = new StringNode("6f", NULL, NULL);
    IntNode* g = new IntNode(7, NULL, NULL);
    StringNode* i = new StringNode("9i", NULL, NULL);

    StringNode* c = new StringNode("3c", e, f);
    IntNode* d = new IntNode(4, g, NULL);
    IntNode* h = new IntNode(8, NULL, i);

    StringNode* a = new StringNode("1a", c, d);
    StringNode* b = new StringNode("2b", NULL, h);

    IntNode* root = new IntNode(0, a, b);

    std::string result = treeUtil->PostOrderTraversal(root);
    EXPECT_EQ(result, ",6f,3c,7,4,1a,9i,8,2b,0");
}
