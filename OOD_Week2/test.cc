#include "gtest/gtest.h"
#include "util.h"

class UtilTest : public ::testing::Test {
 protected:
  void SetUp() override {};
  void TearDown() override {};
  Util u;
};


TEST_F(UtilTest, AddTest1) {
    EXPECT_EQ(u.Add(1, 3), 4);
}

TEST_F(UtilTest, AddTest2) {
    EXPECT_EQ(u.Add(1, 9), 10);
}

TEST_F(UtilTest, AddTest3) {
    EXPECT_EQ(u.Add(10, 3), 13);
}


TEST_F(UtilTest, SubTest1) {
    EXPECT_EQ(u.Sub(10, 3), 7);
}

TEST_F(UtilTest, SubTest2) {
    EXPECT_EQ(u.Sub(5, 2), 3);
}

TEST_F(UtilTest, SubTest3) {
    EXPECT_EQ(u.Sub(20, 10), 10);
}


TEST_F(UtilTest, MultTest1) {
    EXPECT_EQ(u.Mult(2, 3), 6);
}

TEST_F(UtilTest, MultTest2) {
    EXPECT_EQ(u.Mult(4, 4), 16);
}

TEST_F(UtilTest, MultTest3) {
    EXPECT_EQ(u.Mult(10, 10), 100);
}


TEST_F(UtilTest, DivTest1) {
    ASSERT_DEATH(u.Div(1, 0), "Divide-by-zero");
}

TEST_F(UtilTest, DivTest2) {
    EXPECT_EQ(u.Div(10, 1), 10);
}

TEST_F(UtilTest, DivTest3) {
    EXPECT_EQ(u.Div(10, 2), 5);
}
