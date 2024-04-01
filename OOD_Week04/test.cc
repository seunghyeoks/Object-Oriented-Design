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
TEST_F(IntSetTest, ConstructorTest1) {
    int_set_.Add(1);
    IntSet temp = IntSet(int_set_);
    EXPECT_EQ(temp.capacity() == int_set_.capacity(), true);
    EXPECT_EQ(temp.size() == int_set_.size(), true);
}

TEST_F(IntSetTest, ConstructorTest2) {
    int_set_.Add(4);
    int_set_.Add(3);
    int_set_.Add(1);
    IntSet temp = IntSet(int_set_);
    EXPECT_EQ(temp.elements()[0] == int_set_.elements()[0], true);
    EXPECT_EQ(temp.elements()[1] == int_set_.elements()[1], true);
    EXPECT_EQ(temp.elements()[2] == int_set_.elements()[2], true);
}

TEST_F(IntSetTest, ConstructorTest3) {
    int_set_.Add(4);
    int_set_.Add(3);
    int_set_.Add(1);
    IntSet temp = IntSet(int_set_);
    IntSet * ptr1 = &temp;
    IntSet * ptr2 = &int_set_;
    EXPECT_EQ(ptr1 == ptr2, false);
}

TEST_F(IntSetTest, AddTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    ASSERT_DEATH(int_set_.Add(4), "Exceeded capacity");
}

TEST_F(IntSetTest, AddTest2) {
    int_set_.Add(4);
    EXPECT_EQ(int_set_.size(), 1);
}

TEST_F(IntSetTest, AddTest3) {
    int_set_.Add(4);
    int_set_.Add(4);
    int_set_.Add(4);
    EXPECT_EQ(int_set_.size(), 1);
}

TEST_F(IntSetTest, AddOverTest1) {
    IntSet setA = IntSet(3);
    setA.Add(1);
    int_set_.Add(setA);
    EXPECT_EQ(int_set_.size(), 1);
}

TEST_F(IntSetTest, AddOverTest2) {
    IntSet setA = IntSet(3);
    int_set_.Add(1);
    int_set_.Add(2);
    setA.Add(2);
    setA.Add(3);
    int_set_.Add(setA);
    EXPECT_EQ(int_set_.size(), 3);
}

TEST_F(IntSetTest, AddOverTest3) {
    IntSet setA = IntSet(3);
    int_set_.Add(1);
    int_set_.Add(2);
    setA.Add(2);
    setA.Add(3);
    setA.Add(4);
    ASSERT_DEATH(int_set_.Add(setA), "Exceeded capacity");
}

TEST_F(IntSetTest, MapTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Map([](int i){return i * 2;});
    EXPECT_EQ(int_set_.elements()[0], 2);
    EXPECT_EQ(int_set_.elements()[1], 4);
    EXPECT_EQ(int_set_.elements()[2], 6);
}

TEST_F(IntSetTest, MapTest2) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Map([](int i){return i + 10;});
    EXPECT_EQ(int_set_.elements()[0], 11);
    EXPECT_EQ(int_set_.elements()[1], 12);
    EXPECT_EQ(int_set_.elements()[2], 13);
}

TEST_F(IntSetTest, MapTest3) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Map([](int i){return i / 2;});
    EXPECT_EQ(int_set_.elements()[0], 0);
    EXPECT_EQ(int_set_.elements()[1], 1);
    EXPECT_EQ(int_set_.elements()[2], 1);
}

TEST_F(IntSetTest, ForAllTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    EXPECT_EQ(int_set_.ForAll([](int i){
        if (i < 10) {return true;
        } else {return false;
        }}), true);

    int_set_.Add(12);
    EXPECT_EQ(int_set_.ForAll([](int i){
        if (i < 10) {return true;
        } else {return false;
        }}), false);
}

TEST_F(IntSetTest, ForAllTest2) {
    int_set_.Add(10);
    int_set_.Add(100);
    EXPECT_EQ(int_set_.ForAll([](int i){
        if (i % 2 == 0) {return true;
        } else {return false;
        }}), true);

    int_set_.Add(51);
    EXPECT_EQ(int_set_.ForAll([](int i){
        if (i < 10) {return true;
        } else {return false;
        }}), false);
}

TEST_F(IntSetTest, ForAllTest3) {
    int_set_.Add(16);
    int_set_.Add(24);
    int_set_.Add(32);
    EXPECT_EQ(int_set_.ForAll([](int i){
        if (i % 8 == 0) {return true;
        } else {return false;
        }}), true);
}

TEST_F(IntSetTest, AddAssert) {
    IntSet setA = IntSet(1);
    setA.Add(0);
    setA.Add(0);

    EXPECT_EQ(setA.ForAll([](int i) { 
        return i == 0 ;
        }), true);
}
