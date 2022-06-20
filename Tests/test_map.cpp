#include <gtest/gtest.h>

#include <map>
#include "../map/map.hpp"

TEST(Map, Empty) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;

	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.count(""), ftInt.count(""));
}

TEST(Map, BaseType) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;

	stdInt["hello"] = 21;
	stdInt["world"] = 42;
	stdInt[""] = 21;
	ftInt["hello"] = 21;
	ftInt["world"] = 42;
	ftInt[""] = 42;

	EXPECT_EQ(stdInt["hello"], ftInt["hello"]);
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.count("hello"), ftInt.count("hello"));
}

TEST(Map, Clear) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;

	stdInt["hello"] = 21;
	stdInt["world"] = 42;
	stdInt[""] = 21;
	ftInt["hello"] = 21;
	ftInt["world"] = 42;
	ftInt[""] = 42;
	stdInt.clear();
	ftInt.clear();

	EXPECT_EQ(stdInt["hello"], ftInt["hello"]);
	EXPECT_EQ(stdInt.empty(), ftInt.empty());
	EXPECT_EQ(stdInt.size(), ftInt.size());
	EXPECT_EQ(stdInt.count("hello"), ftInt.count("hello"));
}

TEST(Map, Swap) {
	std::map<std::string, int> stdInt1, stdInt2;
	ft::map<std::string, int> ftInt1, ftInt2;

	stdInt1["hello"] = 21;
	stdInt1["world"] = 42;
	stdInt2["a"] = 1;
	stdInt2["b"] = 2;
	ftInt1["hello"] = 21;
	ftInt1["world"] = 42;
	ftInt2["a"] = 1;
	ftInt2["b"] = 2;
	stdInt1.swap(stdInt2);
	ftInt1.swap(ftInt2);

	EXPECT_EQ(stdInt1["hello"], ftInt1["hello"]);
	EXPECT_EQ(stdInt1.empty(), ftInt1.empty());
	EXPECT_EQ(stdInt1.size(), ftInt1.size());
	EXPECT_EQ(stdInt1.count("hello"), ftInt1.count("hello"));

	EXPECT_EQ(stdInt2["hello"], ftInt2["hello"]);
	EXPECT_EQ(stdInt2.empty(), ftInt2.empty());
	EXPECT_EQ(stdInt2.size(), ftInt2.size());
	EXPECT_EQ(stdInt2.count("hello"), ftInt2.count("hello"));
}

TEST(Map, Iterator) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;

	stdInt["hello"] = 21;
	stdInt["world"] = 42;
	ftInt["hello"] = 21;
	ftInt["world"] = 42;

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->first, fIt->first);
	}
	auto sRIt = stdInt.rbegin();
	auto fRIt = ftInt.rbegin();
	for (; sRIt != stdInt.rend() && fRIt != ftInt.rend(); sRIt++, fRIt++) {
		EXPECT_EQ(sRIt->first, fRIt->first);
	}
}

TEST(Map, KeyComp) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;
	auto sCmp = stdInt.key_comp();
	auto fCmp = ftInt.key_comp();

	stdInt["hello"] = 21;
	stdInt["world"] = 42;
	ftInt["hello"] = 21;
	ftInt["world"] = 42;
	bool res1 = sCmp(stdInt.begin()->first, stdInt.rbegin()->first);
	bool res2 = fCmp(ftInt.begin()->first, ftInt.rbegin()->first);

	EXPECT_EQ(res1, res2);
}

TEST(Map, Find) {
	std::map<std::string, int> stdInt;
	ft::map<std::string, int> ftInt;

	stdInt["hello"] = 21;
	stdInt["world"] = 42;
	ftInt["hello"] = 21;
	ftInt["world"] = 42;

	EXPECT_EQ(stdInt.find("world")->second, ftInt.find("world")->second);
}

TEST(Map, LowerBound) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['d'] = 80;
	stdInt['e'] = 100;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['d'] = 80;
	ftInt['e'] = 100;

	EXPECT_EQ(stdInt.lower_bound('b')->first, ftInt.lower_bound('b')->first);
	EXPECT_EQ(stdInt.lower_bound('c')->first, ftInt.lower_bound('c')->first);
}

TEST(Map, UpperBound) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['d'] = 80;
	stdInt['e'] = 100;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['d'] = 80;
	ftInt['e'] = 100;

	EXPECT_EQ(stdInt.upper_bound('b')->first, ftInt.upper_bound('b')->first);
	EXPECT_EQ(stdInt.upper_bound('c')->first, ftInt.upper_bound('c')->first);
}

TEST(Map, EqualRange) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	auto res1 = stdInt.equal_range('b');
	auto res2 = ftInt.equal_range('b');

	EXPECT_EQ(res1.first->first, res2.first->first);
	EXPECT_EQ(res1.second->first, res2.second->first);
}

TEST(Map, EraseOneElemIterator) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.erase(stdInt.begin());
	ftInt.erase(ftInt.begin());

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}

TEST(Map, EraseOneElemKey) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.erase('b');
	ftInt.erase('b');

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}

TEST(Map, EraseRangeIterators) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.erase(stdInt.find('b'), stdInt.end());
	ftInt.erase(ftInt.find('b'), ftInt.end());

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}

TEST(Map, Insert1) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.insert(std::pair<char, int>('1', 1));
	ftInt.insert(ft::pair<char, int>('1', 1));

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}

TEST(Map, InsertWhisIterator) {
	std::map<char, int> stdInt;
	ft::map<char, int> ftInt;

	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.insert(stdInt.end(), std::pair<char, int>('1', 1));
	ftInt.insert(ftInt.end(), ft::pair<char, int>('1', 1));

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}

TEST(Map, InsertRangeIterators) {
	std::map<char, int> stdInt, sBuf;
	ft::map<char, int> ftInt, fBuf;

	sBuf['1'] = 1;
	fBuf['1'] = 1;
	stdInt['a'] = 20;
	stdInt['b'] = 40;
	stdInt['c'] = 40;
	ftInt['a'] = 20;
	ftInt['b'] = 40;
	ftInt['c'] = 40;
	stdInt.insert(sBuf.find('1'), sBuf.end());
	ftInt.insert(fBuf.find('1'), fBuf.end());

	auto sIt = stdInt.begin();
	auto fIt = ftInt.begin();
	for (; sIt != stdInt.end() && fIt != ftInt.end(); sIt++, fIt++) {
		EXPECT_EQ(sIt->second, fIt->second);
	}
}
