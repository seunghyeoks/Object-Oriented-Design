#include <string>

#include "gtest/gtest.h"
#include "vector.h"
#include "stack.h"
#include "list.h"
#include "queue.h"

class VLSQTest : public ::testing::Test {
 public:
  VLSQTest() {}
 protected:
  void SetUp() override {};
  void TearDown() override {};
};


TEST_F(VLSQTest, stack_test_1) {
    Stack<int> s(4);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 0);

    s.Push(0);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 1);
}

TEST_F(VLSQTest, stack_test_2) {
    Stack<std::string> s(4);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 0);

    s.Push("Apple");
    s.Push("Banana");
    s.Push("Camera");
    s.Push("Digital");
    s.Push("Eticket");
    s.Push("Front");
    s.Push("Game");
    s.Push("Hello");
    s.Push("International");

    EXPECT_EQ(s.size(), 9);
    EXPECT_EQ(s.capacity(), 12);

    EXPECT_EQ(s.Pop(), "International");
    EXPECT_EQ(s.size(), 8);
    EXPECT_EQ(s.capacity(), 12);
}

TEST_F(VLSQTest, stack_test_3) {
    Stack<int> s(4);

    s.Push(0);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    EXPECT_EQ(s.Pop(), 4);
    EXPECT_EQ(s.Pop(), 3);
    EXPECT_EQ(s.Pop(), 2);
    EXPECT_EQ(s.Pop(), 1);
    EXPECT_EQ(s.Pop(), 0);
    ASSERT_DEATH(s.Pop(), "Out-of-bound");
}

TEST_F(VLSQTest, stack_test_4) {
    Stack<float> s(2.0);

    ASSERT_DEATH(s.Pop(), "Out-of-bound");

    s.Push(0.1);
    s.Push(1.4);
    s.Push(2.2);
    s.Push(3.6);
    s.Push(4.5);
    s.Push(5.8);
    s.Push(6.5);

    EXPECT_EQ(s.size(), 7);
    EXPECT_EQ(s.capacity(), 10);

    EXPECT_EQ(s.Pop(), (float)6.5);
    EXPECT_EQ(s.Pop(), (float)5.8);
    EXPECT_EQ(s.Pop(), (float)4.5);
    EXPECT_EQ(s.Pop(), (float)3.6);
    EXPECT_EQ(s.Pop(), (float)2.2);
    EXPECT_EQ(s.Pop(), (float)1.4);
    EXPECT_EQ(s.Pop(), (float)0.1);
    ASSERT_DEATH(s.Pop(), "Out-of-bound");
}

TEST_F(VLSQTest, stack_test_5) {
    Stack<double> s(4);

    s.Push(0.1);
    s.Push(1.2);
    s.Push(2.5);
    s.Push(3.9);
    s.Push(4.4);

    Stack<double> s2 = s;
    Stack<double> s3(s);

    EXPECT_EQ(s2.Pop() == s3.Pop(), true);

    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(s2.size() == s3.size(), true);
    EXPECT_EQ(s2.capacity(), 8);
    EXPECT_EQ(s2.capacity() == s3.capacity(), true);

    EXPECT_EQ(s2.Pop() == s3.Pop(), true);
    EXPECT_EQ(s2.Pop() == s3.Pop(), true);
    EXPECT_EQ(s2.Pop() == s3.Pop(), true);
    EXPECT_EQ(s2.Pop() == s3.Pop(), true);

    EXPECT_EQ(s2.IsEmpty(), true);
    EXPECT_EQ(s3.IsEmpty(), true);

    ASSERT_DEATH(s2.Pop(), "Out-of-bound");
    ASSERT_DEATH(s3.Pop(), "Out-of-bound");
}


TEST_F(VLSQTest, queue_test_1) {
    Queue<int> q;

    q.Add(1);
    q.Add(2);
    q.Add(3);

    EXPECT_EQ(q.size(), 3);
}

TEST_F(VLSQTest, queue_test_2) {
    Queue<std::string> q;

    q.Add("Hello");
    EXPECT_EQ(q.size(), 1);

    q.Add("world");
    q.Add("again");
    EXPECT_EQ(q.size(), 3);

    q.Poll();
    EXPECT_EQ(q.size(), 2);

    q.Poll();
    q.Poll();
    EXPECT_EQ(q.IsEmpty(), true);
}

TEST_F(VLSQTest, queue_test_3) {
    Queue<float> q;

    q.Add(0.0);
    q.Add(1.1);
    q.Add(2.3);
    q.Add(3.3);
    q.Add(4.4);

    EXPECT_EQ(q.size(), 5);

    EXPECT_EQ(q.Poll(), (float)0.0);
    EXPECT_EQ(q.Poll(), (float)1.1);
    EXPECT_EQ(q.Poll(), (float)2.3);
    EXPECT_EQ(q.Poll(), (float)3.3);
    EXPECT_EQ(q.Poll(), (float)4.4);
    ASSERT_DEATH(q.Poll(), "Out-of-bound");
}

TEST_F(VLSQTest, queue_test_4) {
    Queue<int> q;

    q.Add(0);
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(4);

    Queue<int> q2(q);

    EXPECT_EQ(q2.size(), 5);
    EXPECT_EQ(q2.Poll(), 0);
    EXPECT_EQ(q2.Poll(), 1);
    EXPECT_EQ(q2.Poll(), 2);
    EXPECT_EQ(q2.Poll(), 3);
    EXPECT_EQ(q2.Poll(), 4);
    ASSERT_DEATH(q2.Poll(), "Out-of-bound");
}

TEST_F(VLSQTest, queue_test_5) {
    Queue<double> q;

    q.Add(0.1);
    q.Add(1.2);
    q.Add(2.3);
    q.Add(3.5);
    q.Add(4.6);

    Queue<double> q2(q);
    Queue<double> q3 = q;

    EXPECT_EQ(q2.size() == q3.size(), true);
    EXPECT_EQ(q2.Poll() == q3.Poll(), true);
    EXPECT_EQ(q2.Poll() == q3.Poll(), true);
    EXPECT_EQ(q2.Poll() == q3.Poll(), true);
    EXPECT_EQ(q2.Poll() == q3.Poll(), true);
    EXPECT_EQ(q2.Poll() == q3.Poll(), true);

    EXPECT_EQ(q2.size(), 0);
    EXPECT_EQ(q2.size() == q3.size(), true);

    ASSERT_DEATH(q2.Poll(), "Out-of-bound");
    ASSERT_DEATH(q3.Poll(), "Out-of-bound");
}
