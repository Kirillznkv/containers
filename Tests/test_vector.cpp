#include <gtest/gtest.h>

#include <vector>
#include "../vector/vector.hpp"

TEST(Vector, Empty) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
}

TEST(Vector, BaseType) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;

	stdInt.push_back(21);
	stdInt.push_back(42);
	stdInt.push_back(777);
	stdInt.pop_back();
	ftInt.push_back(21);
	ftInt.push_back(42);
	ftInt.push_back(777);
	ftInt.pop_back();

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
	EXPECT_EQ(stdInt.at(1), ftInt.at(1));
	EXPECT_EQ(stdInt[0], ftInt[0]);
}

TEST(Vector, iterator) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;

	stdInt.push_back(21);
	stdInt.push_back(42);
	stdInt.push_back(777);
	stdInt.pop_back();
	ftInt.push_back(21);
	ftInt.push_back(42);
	ftInt.push_back(777);
	ftInt.pop_back();

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); ++sIt, ++fIt) {
		EXPECT_EQ(*sIt, *fIt);
	}
	auto sRIt = stdInt.rbegin();
	auto fRIt = ftInt.rbegin();
	for (; sRIt != stdInt.rend() && fRIt != ftInt.rend(); ++sRIt, ++fRIt) {
		EXPECT_EQ(*sRIt, *fRIt);
	}
}

TEST(Vector, AssignBase) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;

	stdInt.assign(10, 42);
	ftInt.assign(10, 42);

	EXPECT_EQ(stdInt.at(5), ftInt.at(5));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, AssignIterator) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	int arr[] = {1, 2, 3, 4 ,5};

	stdInt.assign(arr, arr + 3);
	ftInt.assign(arr, arr + 3);

	EXPECT_EQ(stdInt.at(1), ftInt.at(1));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, InsertOneElem) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;

	stdInt.insert(stdInt.begin(), 123);
	ftInt.insert(ftInt.begin(), 123);

	EXPECT_EQ(stdInt.at(0), ftInt.at(0));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, InsertMoreElem) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;

	stdInt.insert(stdInt.begin(), 10, 111);
	ftInt.insert(ftInt.begin(), 10, 111);

	EXPECT_EQ(stdInt.at(5), ftInt.at(5));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, InsertIterators) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	int arr[] = {1, 2, 3, 4 ,5};

	stdInt.insert(stdInt.begin(), arr, arr + 3);
	ftInt.insert(ftInt.begin(), arr, arr + 3);

	EXPECT_EQ(stdInt.at(2), ftInt.at(2));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, EraseOneElem) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	int arr[] = {1, 2, 3, 4 ,5};

	stdInt.insert(stdInt.begin(), arr, arr + 3);
	ftInt.insert(ftInt.begin(), arr, arr + 3);
	stdInt.erase(stdInt.begin());
	ftInt.erase(ftInt.begin());

	EXPECT_EQ(stdInt.at(0), ftInt.at(0));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, EraseIterators) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	int arr[] = {1, 2, 3, 4 ,5};

	stdInt.insert(stdInt.begin(), arr, arr + 3);
	ftInt.insert(ftInt.begin(), arr, arr + 3);
	stdInt.erase(stdInt.begin(), stdInt.begin() + 1);
	ftInt.erase(ftInt.begin(), ftInt.begin() + 1);

	EXPECT_EQ(stdInt.at(0), ftInt.at(0));
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}

TEST(Vector, Swap) {
	std::vector<int> stdInt1, stdInt2;
	ft::vector<int> ftInt1, ftInt2;
	int arr1[] = {1, 2, 3, 4 ,5};
	int arr2[] = {1, 1, 1};

	stdInt1.insert(stdInt1.begin(), arr1, arr1 + 4);
	ftInt1.insert(ftInt1.begin(), arr1, arr1 + 4);
	stdInt2.insert(stdInt2.begin(), arr2, arr2 + 2);
	ftInt2.insert(ftInt2.begin(), arr2, arr2 + 2);
	stdInt1.swap(stdInt2);
	ftInt1.swap(ftInt2);

	EXPECT_EQ(stdInt1.at(1), ftInt1.at(1));
	EXPECT_EQ(stdInt1.empty(), ftInt1.empty());
	EXPECT_EQ(stdInt1.size(), ftInt1.size());
	EXPECT_EQ(stdInt1.max_size(), ftInt1.max_size());
	EXPECT_EQ(stdInt1.capacity(), ftInt1.capacity());
}

TEST(Vector, Clear) {
	std::vector<int> stdInt;
	ft::vector<int> ftInt;
	int arr[] = {1, 2, 3, 4 ,5};

	stdInt.insert(stdInt.begin(), arr, arr + 3);
	ftInt.insert(ftInt.begin(), arr, arr + 3);
	stdInt.clear();
	ftInt.clear();

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.max_size(), ftInt.max_size());
	EXPECT_EQ(stdInt.capacity(), ftInt.capacity());
}
