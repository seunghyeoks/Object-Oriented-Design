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
    Stack s(4);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 0);

    s.Push(0);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 1);
}

TEST_F(VLSQTest, stack_test_2) {
    Stack s(4);

    EXPECT_EQ(s.capacity(), 4);
    EXPECT_EQ(s.size(), 0);

    s.Push(0);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    EXPECT_EQ(s.size(), 9);
    EXPECT_EQ(s.capacity(), 12);

    EXPECT_EQ(s.Pop(), 8);
    EXPECT_EQ(s.size(), 8);
    EXPECT_EQ(s.capacity(), 12);
}

TEST_F(VLSQTest, stack_test_3) {
    Stack s(4);

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
    Stack s(2);

    ASSERT_DEATH(s.Pop(), "Out-of-bound");

    s.Push(0);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);

    EXPECT_EQ(s.size(), 7);
    EXPECT_EQ(s.capacity(), 10);

    EXPECT_EQ(s.Pop(), 6);
    EXPECT_EQ(s.Pop(), 5);
    EXPECT_EQ(s.Pop(), 4);
    EXPECT_EQ(s.Pop(), 3);
    EXPECT_EQ(s.Pop(), 2);
    EXPECT_EQ(s.Pop(), 1);
    EXPECT_EQ(s.Pop(), 0);
    ASSERT_DEATH(s.Pop(), "Out-of-bound");
}

TEST_F(VLSQTest, stack_test_5) {
    Stack s(4);

    s.Push(0);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    Stack s2 = s;
    Stack s3(s);

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
    Queue q;

    q.Add(1);
    q.Add(2);
    q.Add(3);

    EXPECT_EQ(q.size(), 3);
}

TEST_F(VLSQTest, queue_test_2) {
    Queue q;

    q.Add(1);
    EXPECT_EQ(q.size(), 1);

    q.Add(2);
    q.Add(3);
    EXPECT_EQ(q.size(), 3);

    q.Poll();
    EXPECT_EQ(q.size(), 2);

    q.Poll();
    q.Poll();
    EXPECT_EQ(q.IsEmpty(), true);
}

TEST_F(VLSQTest, queue_test_3) {
    Queue q;

    q.Add(0);
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(4);

    EXPECT_EQ(q.size(), 5);

    EXPECT_EQ(q.Poll(), 0);
    EXPECT_EQ(q.Poll(), 1);
    EXPECT_EQ(q.Poll(), 2);
    EXPECT_EQ(q.Poll(), 3);
    EXPECT_EQ(q.Poll(), 4);
    ASSERT_DEATH(q.Poll(), "Out-of-bound");
}

TEST_F(VLSQTest, queue_test_4) {
    Queue q;

    q.Add(0);
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(4);

    Queue q2(q);

    EXPECT_EQ(q2.size(), 5);
    EXPECT_EQ(q2.Poll(), 0);
    EXPECT_EQ(q2.Poll(), 1);
    EXPECT_EQ(q2.Poll(), 2);
    EXPECT_EQ(q2.Poll(), 3);
    EXPECT_EQ(q2.Poll(), 4);
    ASSERT_DEATH(q2.Poll(), "Out-of-bound");
}

TEST_F(VLSQTest, queue_test_5) {
    Queue q;

    q.Add(0);
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(4);

    Queue q2(q);
    Queue q3 = q;

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

TEST_F(VLSQTest, test_6) {
    List l;

    l.PushBack(1);

    ASSERT_DEATH(l.At(2), "Out-of-bound");
}
