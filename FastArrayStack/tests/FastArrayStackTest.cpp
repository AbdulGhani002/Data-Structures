#include "gtest/gtest.h"
#include "../FastArrayStack.h"

TEST(FastArrayStackTest, PushAndPop) {
  FastArrayStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);
}

TEST(FastArrayStackTest, Size) {
  FastArrayStack stack;

  EXPECT_EQ(stack.size, 0);

  stack.push(1);
  EXPECT_EQ(stack.size, 1);

  stack.push(2);
  EXPECT_EQ(stack.size, 2);

  stack.pop();
  EXPECT_EQ(stack.size, 1);
}