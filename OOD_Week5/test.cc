#include "gtest/gtest.h"
#include "int_set.h"


class IntSetTest : public ::testing::Test {
 public:
  IntSetTest() : int_set_(3) {}
 protected:
  void SetUp() override {};  // Do nothing
  void TearDown() override {};  // Do nothing
  IntSet int_set_;
};


// test : default capacity = 3
TEST_F(IntSetTest, OpOverTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    EXPECT_EQ(int_set_[0], 1);
}

TEST_F(IntSetTest, OpOverTest2) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    EXPECT_EQ(int_set_[2], 3);
}

TEST_F(IntSetTest, OpOverTest3) {
    int_set_.Add(20);
    ASSERT_DEATH(int_set_[1], "Out-of-bound");
}


TEST_F(IntSetTest, AddCapTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Add(4);
    EXPECT_EQ(int_set_.capacity(), 7);
}

TEST_F(IntSetTest, AddCapTest2) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Add(3);
    EXPECT_EQ(int_set_.capacity(), 3);
}

TEST_F(IntSetTest, AddCapTest3) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Add(4);
    EXPECT_EQ(int_set_[3], 4);
}


TEST_F(IntSetTest, AddCapOverTest1) {
    IntSet setA = IntSet(3);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    setA.Add(4);
    setA.Add(5);
    int_set_.Add(setA);
    EXPECT_EQ(int_set_.capacity(), 7);
}

TEST_F(IntSetTest, AddCapOverTest2) {
    IntSet setA = IntSet(3);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    setA.Add(3);
    setA.Add(4);
    int_set_.Add(setA);
    EXPECT_EQ(int_set_.size(), 4);
    EXPECT_EQ(int_set_.capacity(), 7);
}

TEST_F(IntSetTest, AddCapOverTest3) {
    IntSet setA = IntSet(3);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    setA.Add(4);
    setA.Add(5);
    setA.Add(6);
    int_set_.Add(setA);
    setA.Add(6);
    setA.Add(7);
    setA.Add(8);
    int_set_.Add(setA);
    EXPECT_EQ(int_set_.size(), 8);
    EXPECT_EQ(int_set_.capacity(), 11);
}

TEST_F(IntSetTest, AddAssert) {
    IntSet setA = IntSet(1);
    setA.Add(0);
    setA.Add(0);

    EXPECT_EQ(setA.ForAll([](int i) { 
        return i == 0 ;
        }), true);
}
