#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test {
 public:
  IntAccTest() : accumulator_(3) {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
  int_accumulator::Accumulator accumulator_;
};

class FloatAccTest : public ::testing::Test {
 public:
  FloatAccTest() : accumulator_(3.0) {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
  float_accumulator::Accumulator accumulator_;
};

TEST_F(IntAccTest, AddTestI1) {
    accumulator_.Add(3);
    EXPECT_EQ(accumulator_.acc(), 6);
}

TEST_F(IntAccTest, AddTestI2) {
    accumulator_.Add(10);
    EXPECT_EQ(accumulator_.acc(), 13);
}

TEST_F(IntAccTest, AddTestI3) {
    accumulator_.Add(7);
    EXPECT_EQ(accumulator_.acc(), 10);
}

TEST_F(FloatAccTest, AddTestF1) {
    accumulator_.Add(7);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 10);
}

TEST_F(FloatAccTest, AddTestF2) {
    accumulator_.Add(100);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 103);
}

TEST_F(FloatAccTest, AddTestF3) {
    accumulator_.Add(3);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 6);
}



TEST_F(IntAccTest, SubTestI1) {
    accumulator_.Sub(3);
    EXPECT_EQ(accumulator_.acc(), 0);
}

TEST_F(IntAccTest, SubTestI2) {
    accumulator_.Sub(10);
    EXPECT_EQ(accumulator_.acc(), -7);
}

TEST_F(IntAccTest, SubTestI3) {
    accumulator_.Sub(0);
    EXPECT_EQ(accumulator_.acc(), 3);
}

TEST_F(FloatAccTest, SubTestF1) {
    accumulator_.Sub(0.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 2.5);
}

TEST_F(FloatAccTest, SubTestF2) {
    accumulator_.Sub(1.1);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 1.9);
}

TEST_F(FloatAccTest, SubTestF3) {
    accumulator_.Sub(3.0);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 0);
}



TEST_F(IntAccTest, MultTestI1) {
    accumulator_.Mult(3);
    EXPECT_EQ(accumulator_.acc(), 9);
}

TEST_F(IntAccTest, MultTestI2) {
    accumulator_.Mult(10);
    EXPECT_EQ(accumulator_.acc(), 30);
}

TEST_F(IntAccTest, MultTestI3) {
    accumulator_.Mult(0);
    EXPECT_EQ(accumulator_.acc(), 0);
}

TEST_F(FloatAccTest, MultTestF1) {
    accumulator_.Mult(0.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 1.5);
}

TEST_F(FloatAccTest, MultTestF2) {
    accumulator_.Mult(2.2);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 6.6);
}

TEST_F(FloatAccTest, MultTestF3) {
    accumulator_.Mult(3.0);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 9.0);
}



TEST_F(IntAccTest, DivTestI1) {
    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}

TEST_F(IntAccTest, DivTestI2) {
    accumulator_.Div(1);
    EXPECT_EQ(accumulator_.acc(), 3);
}

TEST_F(IntAccTest, DivTestI3) {
    accumulator_.Div(3);
    EXPECT_EQ(accumulator_.acc(), 1);
}

TEST_F(FloatAccTest, DivTestF1) {
    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}

TEST_F(FloatAccTest, DivTestF2) {
    accumulator_.Div(1.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 2);
}

TEST_F(FloatAccTest, DivTestF3) {
    accumulator_.Div(0.1);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 30);
}
