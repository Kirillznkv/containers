#include <gtest/gtest.h>

#include <stack>
#include "../stack/stack.hpp"

TEST(Stack, Empty) {
	std::stack<int> stdInt;
	ft::stack<int> ftInt;
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
}

TEST(Stack, BaseType) {
	std::stack<int> stdInt;
	ft::stack<int> ftInt;

	stdInt.push(21);
	stdInt.push(42);
	stdInt.push(777);
	stdInt.pop();
	ftInt.push(21);
	ftInt.push(42);
	ftInt.push(777);
	ftInt.pop();

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.top(), ftInt.top());
}

TEST(Stack, ClassType) {
	std::stack<std::string> stdInt;
	ft::stack<std::string> ftInt;

	stdInt.push("hello");
	stdInt.push("world");
	stdInt.push("!");
	stdInt.pop();
	ftInt.push("hello");
	ftInt.push("world");
	ftInt.push("!");
	ftInt.pop();

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.top(), ftInt.top());
}

TEST(Stack, ListType) {
	std::stack< std::stack<int> > stdInt;
	ft::stack< std::stack<int> > ftInt;
	std::stack<int> st;
	st.push(21);
	st.push(42);
	st.push(777);

	stdInt.push(st);
	ftInt.push(st);

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
}

TEST(Stack, Operators) {
	std::stack<int> std1, std11, std12;
	ft::stack<int> ft1, ft11, ft12;

	std1.push(1);
	std11.push(1);
	std11.push(1);
	std12.push(1);
	std12.push(2);
	ft1.push(1);
	ft11.push(1);
	ft11.push(1);
	ft12.push(1);
	ft12.push(2);

	EXPECT_EQ(std11 < std11, ft11 < ft11);
	EXPECT_EQ(std11 > std11, ft11 > ft11);
	EXPECT_EQ(std11 == std11, ft11 == ft11);
	EXPECT_EQ(std11 != std11, ft11 != ft11);

	EXPECT_EQ(std11 < std12, ft11 < ft12);
	EXPECT_EQ(std11 > std12, ft11 > ft12);
	EXPECT_EQ(std11 == std12, ft11 == ft12);
	EXPECT_EQ(std11 != std12, ft11 != ft12);

	EXPECT_EQ(std1 < std12, ft1 < ft12);
	EXPECT_EQ(std1 > std12, ft1 > ft12);
	EXPECT_EQ(std1 == std12, ft1 == ft12);
	EXPECT_EQ(std1 != std12, ft1 != ft12);
}
