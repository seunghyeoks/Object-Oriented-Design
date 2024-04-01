#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "safe_math.h"
#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"

class VLM_throw_Test : public ::testing::Test {
 public:
  VLM_throw_Test() {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
};




TEST_F(VLM_throw_Test, vector_throw_test_1) {
    try {
        Vector<int> v(4);
        v.PopBack();
    }
    catch (EmptyContainerException& e) {
        EXPECT_EQ(e.what(), std::string("This vector is empty."));
    }
}

TEST_F(VLM_throw_Test, vector_throw_test_2) {
    try {
        Vector<int> v(4);
        v[4];
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 4, but the size is 0."));
    }
}

TEST_F(VLM_throw_Test, vector_throw_test_3) {
    try {
        Vector<int> v(3);
        v.PushBack(0);
        EXPECT_EQ(v[2], 2);
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 2, but the size is 1."));
    }
}

TEST_F(VLM_throw_Test, vector_throw_test_4) {
    try {
        Vector<int> v(3);
        v.PushBack(0);
        v.PushBack(1);
        v.PushBack(2);
        v.PushBack(3);
        v.PushBack(4);

        EXPECT_EQ(v.size(), 5);
        EXPECT_EQ(v.capacity(), 7);
        EXPECT_EQ(v[2], 2);

        v.PopBack();
        v.PopBack();
        v.PopBack();
        v.PopBack();
        v.PopBack();

        EXPECT_EQ(v.size(), 0);
        EXPECT_EQ(v.capacity(), 7);
        EXPECT_EQ(v[1], 2);
    }
    catch (EmptyContainerException& e) {
        EXPECT_EQ(e.what(), std::string("This vector is empty."));
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 1, but the size is 0."));
    }
}




TEST_F(VLM_throw_Test, list_throw_test_1) {
    try {
        List<int> l;
        l.PopBack();
    }
    catch (EmptyContainerException& e) {
        EXPECT_EQ(e.what(), std::string("This list is empty."));
    }
}

TEST_F(VLM_throw_Test, list_throw_test_2) {
    try {
        List<int> l;
        l.At(4);
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 4, but the size is 0."));
    }
}

TEST_F(VLM_throw_Test, list_throw_test_3) {
    try {
        List<int> l;
        l.PushBack(0);
        EXPECT_EQ(l.At(3), 0);
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 3, but the size is 1."));
    }
}

TEST_F(VLM_throw_Test, list_throw_test_4) {
    try {
        List<int> l;
        l.PushBack(0);
        l.PushBack(1);
        l.PushBack(2);
        l.PushBack(3);
        l.PushBack(4);

        EXPECT_EQ(l.size(), 5);
        EXPECT_EQ(l.At(2), 2);

        l.PopFront();
        l.PopFront();
        l.PopFront();
        l.PopFront();
        l.PopFront();

        EXPECT_EQ(l.size(), 0);
        EXPECT_EQ(l.At(2), 2);
    }
    catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("The index is 2, but the size is 0."));
    }
}




TEST_F(VLM_throw_Test, safe_math_throw_test_1) {
    try {
        SafeMath::Add(2147483647, 1);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in 2147483647 + 1.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_2) {
    try {
        SafeMath::Sub(-2147483648, 1);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in -2147483648 - 1.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_3) {
    try {
        SafeMath::Mul(32768, 65536);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in 32768 * 65536.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_4) {
    try {
        SafeMath::Div(123456, 0);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Divide-by-zero exception occurs in 123456 / 0.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_5) {
    try {
        SafeMath::Mod(456789, 0);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Divide-by-zero exception occurs in 456789 % 0.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_6) {
    try {
        SafeMath::Add(-2147483648, -1);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in -2147483648 + -1.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_7) {
    try {
        SafeMath::Sub(-2147483648, 1);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in -2147483648 - 1.";
        EXPECT_EQ(e.what(), cmp);
    }
}

TEST_F(VLM_throw_Test, safe_math_throw_test_8) {
    try {
        SafeMath::Mul(-65536, 65536);
    }
    catch (std::overflow_error& e) {
        std::string cmp = "Interger overflow occurs in -65536 * 65536.";
        EXPECT_EQ(e.what(), cmp);
    }
}
