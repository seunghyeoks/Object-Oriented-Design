#include <array>
#include <vector>
#include <list>
#include <deque>

#include "gtest/gtest.h"
#include "sort.h"

class iterator_functor_Test : public ::testing::Test {
 public:
  iterator_functor_Test() {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
};

class IntIncreasingOrder{
 public:
    int operator() (const int& x, const int& y) {
        if (x > y)
            return 1;
        else
            return 0;
    }
};

class IntDecreasingOrder{
 public:
    int operator() (const int& x, const int& y) {
        if (x < y)
            return 1;
        else
            return 0;
    }
};


TEST_F(iterator_functor_Test, array_test_1) {
    std::array<int, 8> arr = {1, 3, 5, 2, 6, 8, 4, 0};

    Sort<std::array<int, 8>, IntIncreasingOrder> (arr.begin(), arr.end());

    EXPECT_EQ(arr[1], 1);
}

TEST_F(iterator_functor_Test, array_test_2) {
    std::array<int, 8> arr = {1, 3, 5, 2, 6, 8, 4, 0};
    EXPECT_EQ(arr[0], 1);

    Sort<std::array<int, 8>, IntIncreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[7], 8);

    Sort<std::array<int, 8>, IntDecreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 8);
    EXPECT_EQ(arr[7], 0);
}

TEST_F(iterator_functor_Test, array_test_3) {
    std::array<int, 11> arr = {1, 3, 5, 2, 6, 8, 4, 0, 9, 10, 11};
    EXPECT_EQ(arr[0], 1);

    Sort<std::array<int, 11>, IntIncreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[10], 11);
    EXPECT_EQ(arr.size(), 11);

    Sort<std::array<int, 11>, IntDecreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 11);
    EXPECT_EQ(arr[10], 0);
}

TEST_F(iterator_functor_Test, array_test_4) {
    std::array<int, 5> arr = {1, 3, 4, 2, 0};
    EXPECT_EQ(arr[0], 1);

    Sort<std::array<int, 5>, IntDecreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 4);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 1);
    EXPECT_EQ(arr[4], 0);

    Sort<std::array<int, 5>, IntIncreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 4);

    Sort<std::array<int, 5>, IntDecreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 4);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 1);
    EXPECT_EQ(arr[4], 0);

    Sort<std::array<int, 5>, IntIncreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 4);

    Sort<std::array<int, 5>, IntIncreasingOrder> (arr.begin(), arr.end());
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 4);
}





TEST_F(iterator_functor_Test, vector_test_1) {
    std::vector<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};

    Sort<std::vector<int>, IntIncreasingOrder> (temp.begin(), temp.end());

    EXPECT_EQ(temp[1], 1);
}

TEST_F(iterator_functor_Test, vector_test_2) {
    std::vector<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[7], 0);

    Sort<std::vector<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[7], 8);

    Sort<std::vector<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[7], 0);
    EXPECT_EQ(temp[1], 6);
}

TEST_F(iterator_functor_Test, vector_test_3) {
    std::vector<int> temp = {1, 3, 5, 2, 6, 8, 4, 0, 9, 10, 11};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[8], 9);

    Sort<std::vector<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[10], 11);
    EXPECT_EQ(temp.size(), 11);
    temp.push_back(-1);
    EXPECT_EQ(temp.size(), 12);

    Sort<std::vector<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[11], -1);
    EXPECT_EQ(temp[1], 10);
}

TEST_F(iterator_functor_Test, vector_test_4) {
    std::vector<int> temp = {1, 3, 4, 2, 0};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 4);
    EXPECT_EQ(temp[3], 2);
    EXPECT_EQ(temp[4], 0);

    Sort<std::vector<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 4);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 1);
    EXPECT_EQ(temp[4], 0);

    Sort<std::vector<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 0);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 3);
    EXPECT_EQ(temp[4], 4);

    Sort<std::vector<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 4);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 1);
    EXPECT_EQ(temp[4], 0);

    Sort<std::vector<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 0);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 3);
    EXPECT_EQ(temp[4], 4);
}






TEST_F(iterator_functor_Test, list_test_1) {
    std::list<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};

    Sort<std::list<int>, IntIncreasingOrder> (temp.begin(), temp.end());

    EXPECT_EQ(temp.front(), 0);
}

TEST_F(iterator_functor_Test, list_test_2) {
    std::list<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};
    EXPECT_EQ(temp.front(), 1);
    EXPECT_EQ(temp.back(), 0);

    Sort<std::list<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 0);
    EXPECT_EQ(temp.back(), 8);

    Sort<std::list<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 8);
    EXPECT_EQ(temp.back(), 0);
}

TEST_F(iterator_functor_Test, list_test_3) {
    std::list<int> temp = {1, 3, 5, 2, 6, 8, 4, 0, 9, 10, 11};
    EXPECT_EQ(temp.front(), 1);
    EXPECT_EQ(temp.back(), 11);

    Sort<std::list<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 0);
    EXPECT_EQ(temp.back(), 11);
    EXPECT_EQ(temp.size(), 11);
    temp.push_back(-1);
    EXPECT_EQ(temp.size(), 12);

    Sort<std::list<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 11);
    EXPECT_EQ(temp.back(), -1);
}

TEST_F(iterator_functor_Test, list_test_4) {
    std::list<int> temp = {1, 3, 4, 2, 0};
    EXPECT_EQ(temp.front(), 1);
    EXPECT_EQ(temp.back(), 0);

    Sort<std::list<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 4);
    EXPECT_EQ(temp.back(), 0);

    Sort<std::list<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 0);
    EXPECT_EQ(temp.back(), 4);

    Sort<std::list<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 4);
    EXPECT_EQ(temp.back(), 0);

    Sort<std::list<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp.front(), 0);
    EXPECT_EQ(temp.back(), 4);
}





TEST_F(iterator_functor_Test, deque_test_1) {
    std::deque<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};

    Sort<std::deque<int>, IntIncreasingOrder> (temp.begin(), temp.end());

    EXPECT_EQ(temp[1], 1);
}

TEST_F(iterator_functor_Test, deque_test_2) {
    std::deque<int> temp = {1, 3, 5, 2, 6, 8, 4, 0};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[7], 0);

    Sort<std::deque<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[7], 8);

    Sort<std::deque<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[7], 0);
    EXPECT_EQ(temp[1], 6);
}

TEST_F(iterator_functor_Test, deque_test_3) {
    std::deque<int> temp = {1, 3, 5, 2, 6, 8, 4, 0, 9, 10, 11};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[8], 9);

    Sort<std::deque<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[10], 11);
    EXPECT_EQ(temp.size(), 11);
    temp.push_back(-1);
    EXPECT_EQ(temp.size(), 12);

    Sort<std::deque<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[11], -1);
    EXPECT_EQ(temp[1], 10);
}

TEST_F(iterator_functor_Test, deque_test_4) {
    std::deque<int> temp = {1, 3, 4, 2, 0};
    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 4);
    EXPECT_EQ(temp[3], 2);
    EXPECT_EQ(temp[4], 0);

    Sort<std::deque<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 4);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 1);
    EXPECT_EQ(temp[4], 0);

    Sort<std::deque<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 0);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 3);
    EXPECT_EQ(temp[4], 4);

    Sort<std::deque<int>, IntDecreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 4);
    EXPECT_EQ(temp[1], 3);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 1);
    EXPECT_EQ(temp[4], 0);

    Sort<std::deque<int>, IntIncreasingOrder> (temp.begin(), temp.end());
    EXPECT_EQ(temp[0], 0);
    EXPECT_EQ(temp[1], 1);
    EXPECT_EQ(temp[2], 2);
    EXPECT_EQ(temp[3], 3);
    EXPECT_EQ(temp[4], 4);
}
