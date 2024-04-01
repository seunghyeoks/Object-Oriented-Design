#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"
#include "node.h"
#include "int_node.h"
#include "string_node.h"
#include "visitor.h"
#include "preorder_traversal.h"
#include "postorder_traversal.h"

class Visitor_Test : public ::testing::Test {
 public:
  Visitor_Test() {}
  std::string expect;
 protected:
  void SetUp() override {};
  void TearDown() override {};
};


TEST_F(Visitor_Test, visit_test_1) {
    Node* n33 = new IntNode(0, nullptr, nullptr);
    Node* n34 = new StringNode("bye", nullptr, nullptr);

    Node* n21 = new StringNode("hi", nullptr, nullptr);
    Node* n22 = new IntNode(-42, n33, n34);

    Node* n1 = new IntNode(3, n21, n22);

    PreorderTraversal pre_visitor;

    n1->Visit(&pre_visitor);

    expect = "(Int 3) :: (String hi) :: (Int -42) :: (Int 0) :: (String bye)";
    EXPECT_EQ(pre_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_2) {
    Node* n33 = new IntNode(0, nullptr, nullptr);
    Node* n34 = new StringNode("bye", nullptr, nullptr);

    Node* n21 = new StringNode("hi", nullptr, nullptr);
    Node* n22 = new IntNode(-42, n33, n34);

    Node* n1 = new IntNode(3, n21, n22);

    PostorderTraversal pos_visitor;

    n1->Visit(&pos_visitor);

    expect = "(String hi) :: (Int 0) :: (String bye) :: (Int -42) :: (Int 3)";
    EXPECT_EQ(pos_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_3) {
    Node* n31 = new IntNode(31, nullptr, nullptr);
    Node* n32 = new StringNode("n32", nullptr, nullptr);
    Node* n33 = new IntNode(33, nullptr, nullptr);
    Node* n34 = new StringNode("n34", nullptr, nullptr);

    Node* n21 = new StringNode("n21", n31, n32);
    Node* n22 = new IntNode(22, n33, n34);

    Node* n1 = new IntNode(1, n21, n22);

    PreorderTraversal pre_visitor;

    n1->Visit(&pre_visitor);

    expect = "(Int 1) :: (String n21) :: (Int 31) :: (String n32) :: ";
    expect += "(Int 22) :: (Int 33) :: (String n34)";
    EXPECT_EQ(pre_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_4) {
    Node* n31 = new IntNode(31, nullptr, nullptr);
    Node* n32 = new StringNode("n32", nullptr, nullptr);
    Node* n33 = new IntNode(33, nullptr, nullptr);
    Node* n34 = new StringNode("n34", nullptr, nullptr);

    Node* n21 = new StringNode("n21", n31, n32);
    Node* n22 = new IntNode(22, n33, n34);

    Node* n1 = new IntNode(1, n21, n22);

    PostorderTraversal pos_visitor;

    n1->Visit(&pos_visitor);

    expect = "(Int 31) :: (String n32) :: (String n21) :: ";
    expect += "(Int 33) :: (String n34) :: (Int 22) :: (Int 1)";
    EXPECT_EQ(pos_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_5) {
    Node* n21 = new StringNode("left", nullptr, nullptr);
    Node* n22 = new StringNode("right", nullptr, nullptr);

    Node* n1 = new StringNode("parent", n21, n22);

    PreorderTraversal pre_visitor;

    n1->Visit(&pre_visitor);

    expect = "(String parent) :: (String left) :: (String right)";
    EXPECT_EQ(pre_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_6) {
    Node* n21 = new StringNode("left", nullptr, nullptr);
    Node* n22 = new StringNode("right", nullptr, nullptr);

    Node* n1 = new StringNode("parent", n21, n22);

    PostorderTraversal pos_visitor;

    n1->Visit(&pos_visitor);

    expect = "(String left) :: (String right) :: (String parent)";
    EXPECT_EQ(pos_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_7) {
    Node* n21 = new IntNode(1, nullptr, nullptr);
    Node* n22 = new IntNode(2, nullptr, nullptr);

    Node* n1 = new IntNode(0, n21, n22);

    PreorderTraversal pre_visitor;

    n1->Visit(&pre_visitor);

    expect = "(Int 0) :: (Int 1) :: (Int 2)";
    EXPECT_EQ(pre_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_8) {
    Node* n21 = new IntNode(1, nullptr, nullptr);
    Node* n22 = new IntNode(2, nullptr, nullptr);

    Node* n1 = new IntNode(0, n21, n22);

    PostorderTraversal pos_visitor;

    n1->Visit(&pos_visitor);

    expect = "(Int 1) :: (Int 2) :: (Int 0)";
    EXPECT_EQ(pos_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_9) {
    Node* n41 = new IntNode(10, nullptr, nullptr);
    Node* n42 = new StringNode("hello", nullptr, nullptr);

    Node* n31 = new IntNode(0, n41, n42);
    Node* n32 = new StringNode("bye", nullptr, nullptr);

    Node* n21 = new StringNode("hi", n31, n32);
    Node* n22 = new IntNode(-42, nullptr, nullptr);

    Node* n1 = new IntNode(3, n21, n22);

    PreorderTraversal pre_visitor;

    n1->Visit(&pre_visitor);

    expect = "(Int 3) :: (String hi) :: (Int 0) :: (Int 10) :: ";
    expect += "(String hello) :: (String bye) :: (Int -42)";
    EXPECT_EQ(pre_visitor.Result(), expect);
}


TEST_F(Visitor_Test, visit_test_10) {
    Node* n41 = new IntNode(10, nullptr, nullptr);
    Node* n42 = new StringNode("hello", nullptr, nullptr);

    Node* n31 = new IntNode(0, n41, n42);
    Node* n32 = new StringNode("bye", nullptr, nullptr);

    Node* n21 = new StringNode("hi", n31, n32);
    Node* n22 = new IntNode(-42, nullptr, nullptr);

    Node* n1 = new IntNode(3, n21, n22);

    PostorderTraversal pos_visitor;

    n1->Visit(&pos_visitor);

    expect = "(Int 10) :: (String hello) :: (Int 0) :: (String bye) :: ";
    expect += "(String hi) :: (Int -42) :: (Int 3)";
    EXPECT_EQ(pos_visitor.Result(), expect);
}
