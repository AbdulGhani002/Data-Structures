#include <gtest/gtest.h>
#include "Stack.h"

// main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Test fixture for Stack class
class StackTest : public ::testing::Test {
protected:
    data_structures::Stack<int> stack;

    void SetUp() override {
        stack.init(5);
    }
};

TEST_F(StackTest, Insert) {
    EXPECT_EQ(stack.insert(5), 0);
    EXPECT_EQ(stack.insert(10), 1);
    EXPECT_EQ(stack.peek(), 10);
}

TEST_F(StackTest, Pop) {
    stack.insert(5);
    stack.insert(10);
    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.pop(), -1);
}

TEST_F(StackTest, Overflow) {
    for (int i = 0; i < 5; i++) {
        stack.insert(i);
    }
    EXPECT_EQ(stack.insert(6), -1);
}

