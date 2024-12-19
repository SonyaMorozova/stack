#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> stack);
}

TEST(Stack, can_push) {
	Stack<int> stack;

	ASSERT_NO_THROW(stack.push(5));
}

TEST(Stack, correct_size) {
	Stack<int> stack;

	stack.push(5);
	stack.push(-10);

	ASSERT_EQ(stack.size(), 2);
}

TEST(Stack, get_top) {
	Stack<int> stack;

	stack.push(5);
	stack.push(-10);
	stack.push(15);

	ASSERT_EQ(stack.top(), 15);
}

TEST(Stack, pop) {
	Stack<int> stack;

	stack.push(5);
	stack.push(-10);
	stack.push(15);
	stack.pop();

	ASSERT_EQ(stack.size(), 2);
	ASSERT_EQ(stack.top(), -10);
}

TEST(Stack, is_empty) {
	Stack<int> stack;

	ASSERT_TRUE(stack.is_empty());
}

TEST(Stack, is_not_empty) {
	Stack<int> stack;

	stack.push(5);
	stack.push(-10);

	ASSERT_FALSE(stack.is_empty());
}

TEST(Stack, can_clear) {
	Stack<int> stack;

	stack.push(5);
	stack.push(-10);
	stack.clear();

	ASSERT_TRUE(stack.is_empty());
}

TEST(Stack, identical_stacks_are_equal) {
	Stack<int> stack1;
	Stack<int> stack2;

	stack1.push(5);
	stack1.push(-10);
	stack2.push(5);
	stack2.push(-10);

	ASSERT_EQ(stack1 == stack2, 1);
}

TEST(Stack, stacks_different_lengths_are_not_equal) {
	Stack<int> stack1;
	Stack<int> stack2;

	stack1.push(5);
	stack1.push(-10);

	stack2.push(15);
	stack2.push(20);
	stack2.push(25);
	ASSERT_EQ(stack1 == stack2, 0);
}

TEST(Stack, the_operator_is_not_equal_to) {
	Stack<int> stack1;
	Stack<int> stack2;

	stack1.push(5);
	stack1.push(-10);
	stack2.push(5);
	stack2.push(-10);

	ASSERT_EQ(stack1 != stack2, 0);
}

TEST(Stack, assignment) {
	Stack<int> stack1;
	Stack<int> stack2;

	stack1.push(5);
	stack1.push(-10);
	stack2.push(15);
	stack2.push(20);
	stack2.push(25);
	stack1 = stack2;

	ASSERT_EQ(stack1 == stack2, 1);
	ASSERT_EQ(stack1.top(), 25);
}

TEST(Stack, can_swap) {
	Stack<int> stack1;
	Stack<int> stack2;

	stack1.push(5);
	stack1.push(-10);
	stack2.push(15);
	stack2.push(20);
	stack2.push(25);

	stack1.swap(stack2);
	ASSERT_EQ(stack1.top(), 25);
	ASSERT_EQ(stack2.top(), -10);
}