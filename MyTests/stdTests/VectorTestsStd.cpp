#include <iostream>
#include <vector>
#include "TestsUtils.hpp"

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
	typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
	for (--n; n > 0; n -= 2) {
		typename std::iterator_traits<BidirIt>::value_type tmp = *first;
		*first++ = *--last;
		*last = tmp;
	}
}

void	vectorTestBaseStd(){
	fStdVector<<"---Vector-Test-Base-(namespace:std)---"<<std::endl;
	//Test size, capacity, max_size
	std::vector<int> v1;
	outSizes(v1, fStdVector);
	v1.push_back(21);
	outSizes(v1, fStdVector);
	v1.push_back(42);
	outSizes(v1, fStdVector);
	//Test front/back
	fStdVector<<v1.front()<<std::endl;
	fStdVector<<++(v1.front())<<std::endl;
	fStdVector<<v1.back()<<std::endl;
	fStdVector<<++(v1.back())<<std::endl;
	//Test [] / at()
	fStdVector<<v1[1]<<std::endl;
	fStdVector<<v1.at(1)<<std::endl;
	//Test reserve
	std::vector<int> vec1;
	vec1.reserve(100);
	outSizes(vec1, fStdVector);
	vec1.push_back(21);
	outSizes(vec1, fStdVector);
	vec1.push_back(42);
	outSizes(vec1, fStdVector);
	//Test resize
	v1.resize(2);
	outSizes(v1, fStdVector);
	v1.resize(12);
	outSizes(v1, fStdVector);
	v1.resize(1);
	outSizes(v1, fStdVector);
	std::vector<int> t1;
	t1.resize(20);
	outSizes(t1, fStdVector);
	//Test create
	std::vector<int> ve(2, 1);
	outSizes(ve, fStdVector);
	fStdVector<<ve.front()<<std::endl;
	std::vector<int> ve1(2);
	outSizes(ve1, fStdVector);
	fStdVector<<ve1.front()<<std::endl;
	//Test v1(Iter, Iter)
	std::vector<int> s21(ve.begin(), ve.end());
	outSizes(s21, fStdVector);
	fStdVector<<"front = "<<s21.front()<<std::endl;
	//Test iterator_traits
	fStdVector<<"---Vector-Test-Iterator_traits-(namespace:std)---"<<std::endl;
    {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		my_reverse(v.begin(), v.end());
		for (int n = 0; n < (int)v.size();++n)
			fStdVector << v[n] << ' ';
		fStdVector << '\n';
	
		std::vector<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		my_reverse(l.begin(), l.end());
		for (int n = 0; n < (int)l.size();++n)
			fStdVector << l[n] << ' ';
		fStdVector << '\n';
	
		int a[] = {1, 2, 3, 4, 5};
		my_reverse(a, a + 5);
		for (int n = 0; n < 5;++n)
			fStdVector << a[n] << ' ';
		fStdVector << '\n';
	}
	//Test pair
	fStdVector<<"---Vector-Test-Pair-(namespace:std)---"<<std::endl;
	{
		std::pair<int, int> p;
		p.first = 1;
		p.second = -1;
		std::pair<int, int> pp;
		pp.first = 1;
		pp.second = -2;
		fStdVector<<pp.first<<pp.second<<std::endl;
		std::pair<int, std::string> p2;
		p2.first = 1;
		p2.second = "hello";
		fStdVector<<p2.first<<p2.second<<std::endl;
		std::pair<int, std::string> p3;
		p3.first = 2;
		p3.second = "hello";
		fStdVector<<p3.first<<p3.second<<std::endl;
		std::pair<int, std::string> p4;
		p4.first = 2;
		p4.second = "hell";
		fStdVector<<p4.first<<p4.second<<std::endl;
		boolTest(p, pp, fStdVector);
		boolTest(p2, p3, fStdVector);
		boolTest(p3, p4, fStdVector);
		boolTest(p2, p4, fStdVector);
		std::pair<int, int> m = std::make_pair(10, 111);
		fStdVector<<m.first<<m.second<<std::endl;
	}
}

void	vectorTestDoubleStd(){
	fStdVector<<"---Vector-Test-Double-(namespace:std)---"<<std::endl;
	std::vector<double> v1;
	for (double i = 0.01; i < 5.078; i += 0.035)
		v1.push_back(i);
	outSizes(v1, fStdVector);
	std::vector<double> vec1;
	vec1.reserve(144);
	for (double i = 0.01; i < 5.078; i += 0.035)
		vec1.push_back(i);
	outSizes(vec1, fStdVector);
	// Test base iterators
	std::vector<double>::iterator it1 = vec1.begin();
	for (;it1 < vec1.end(); it1 += 10)
		fStdVector<<*it1<<std::endl;
}

void	vectorTestListStd(){
	fStdVector<<"---Vector-Test-List-(namespace:std)---"<<std::endl;
	std::vector<std::vector<int> > v1;
	std::vector<int> vec1[5];
	for (int i = 0; i < 5; ++i){
		for (int val = 10; val < 1000; val += 13 + i)
			vec1[i].push_back(val);
		v1.push_back(vec1[i]);
	}
	outSizes(v1, fStdVector);
	std::vector<std::vector<int> > v2;
	std::vector<int> vec2[6];
	for (int i = 0; i < 6; ++i){
		for (int val = 9; val < 1000; val += 13 + i)
			vec2[i].push_back(val);
		v2.push_back(vec2[i]);
	}
	outSizes(v2, fStdVector);
	boolTest(v1, v2, fStdVector);
}

void	vectorTestIteratorStd(){
	fStdVector<<"---Vector-Test-Iterator-(namespace:std)---"<<std::endl;
	// Test ++ -- += -= ...
	std::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	std::vector<char>::iterator itStd;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); ++itStd)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd += 1)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd = itStd + 1)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.begin(); itStd < stdVec.end(); itStd += 3, i += 3){
		++(*itStd);
		fStdVector<<*itStd<<stdVec[i];
	}
	fStdVector<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.end() - 1; itStd >= stdVec.begin(); itStd--, i--){
		fStdVector<<*itStd<<stdVec[i];
	}
	fStdVector<<std::endl;
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	fStdVector<<*(++stdVec2.begin())<<std::endl;
	fStdVector<<*(stdVec2.begin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::iterator it1Beg = stdVec2.begin();
	std::vector<char>::iterator it1End = stdVec2.end();
	fStdVector<<*(it1End - 1)<<std::endl;
	fStdVector<<it1End - it1Beg<<std::endl;
}

void vectorTestReverseIteratorStd(){
	fStdVector<<"---Vector-Test-ReverseIterator-(namespace:std)---"<<std::endl;
	// Test ++ -- += -= ...
	std::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	std::vector<char>::reverse_iterator itStd;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); ++itStd)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd += 1)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd = itStd + 1)
		fStdVector<<*itStd;
	fStdVector<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.rbegin(); itStd < stdVec.rend(); itStd += 3, i += 3){
		++(*itStd);
		fStdVector<<*itStd<<stdVec[i];
	}
	fStdVector<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.rend() - 1; itStd >= stdVec.rbegin(); itStd--, i--){
		fStdVector<<*itStd<<stdVec[i];
	}
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	fStdVector<<*(++stdVec2.rbegin())<<std::endl;
	fStdVector<<*(stdVec2.rbegin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::reverse_iterator it1Beg = stdVec2.rbegin();
	std::vector<char>::reverse_iterator it1End = stdVec2.rend();
	fStdVector<<*(it1End - 1)<<std::endl;
	fStdVector<<it1End - it1Beg<<std::endl;
}

void	vectorTestModifiersStd(){
	fStdVector<<"---Vector-Test-Modifiers-(namespace:std)---"<<std::endl;
	///////////////////// Test assign #1
	std::vector<int> v1, v1New;
	for (int i = 0; i < 10; ++i)
		v1.push_back(i);
	for (int i = 0; i < 100; ++i)
		v1New.push_back(i);
	outSizes(v1, fStdVector);
	outSizes(v1New, fStdVector);
	v1.assign(5, 123);
	outSizes(v1, fStdVector);
	v1.assign(50, 2);
	outSizes(v1, fStdVector);
	///////////////////// Test assign #2
	v1.assign(v1New.begin(), v1New.end());
	outSizes(v1, fStdVector);
	v1.assign(v1New.begin(), v1New.begin() + 10);
	outSizes(v1, fStdVector);
	int myints[] = {1776,7,4};
	v1.assign(myints,myints+3);
	outSizes(v1, fStdVector);
	///////////////////// Test insert #1
	std::vector<int>::iterator it = v1.insert(v1.begin(), 100);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i]<<" ";
	outSizes(v1, fStdVector);
	fStdVector<<"\t"<<*it<<std::endl;
	///////////////////// Test insert #2
	v1.insert(v1.begin(), 5, 1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i]<<" ";
	outSizes(v1, fStdVector);
	///////////////////// Test insert #3
	std::vector<int> putVec1(10, 0);
	v1.insert(v1.begin() + 1, putVec1.begin(), putVec1.end());
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i]<<" ";
	outSizes(v1, fStdVector);
	std::vector<int> a, b;
	a.insert(a.begin(), putVec1.begin(), putVec1.end());
	b.insert(b.end(), putVec1.begin(), putVec1.end());
	for (int i = 0; i < (int)a.size(); ++i)
		fStdVector<<a[i]<<" ";
	outSizes(a, fStdVector);
	for (int i = 0; i < (int)b.size(); ++i)
		fStdVector<<b[i]<<" ";
	outSizes(b, fStdVector);
	///////////////////// Test erase #1
	std::vector<int>::iterator itEr1 = v1.erase(v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i]<<" ";
	fStdVector<<*itEr1<<std::endl;
	outSizes(v1, fStdVector);
	///////////////////// Test erase #2
	std::vector<int>::iterator itEr12 = v1.erase(v1.begin(), v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i]<<" ";
	fStdVector<<*itEr12<<std::endl;
	///////////////////// Test swap
	{
	std::vector<int> v1(20, 5);
	std::vector<int> putVec1(10, 0);
	v1.swap(putVec1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i];
	fStdVector<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		fStdVector<<putVec1[i];
	fStdVector<<")"<<std::endl;
	outSizes(v1, fStdVector);
	outSizes(putVec1, fStdVector);
	std::swap(v1,putVec1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fStdVector<<v1[i];
	fStdVector<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		fStdVector<<putVec1[i];
	fStdVector<<")"<<std::endl;
	outSizes(v1, fStdVector);
	outSizes(putVec1, fStdVector);
	}
	///////////////////// Test clear
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	fStdVector << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		fStdVector << ' ' << myvector[i];
	fStdVector << std::endl;
	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	fStdVector << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		fStdVector << ' ' << myvector[i];
	fStdVector << std::endl;
}

void vectorTestExeptStd(){
	fStdVector<<"---Vector-Test-Exept-(namespace:std)---"<<std::endl;
	///////////////////// Test at
	std::vector<long long> v1;
	try { fStdVector<<v1.at(-1)<<std::endl; }
	catch (std::exception &e) { fStdVector<<"Error0: "<<e.what()<<std::endl; }
	try { fStdVector<<v1.at(0)<<std::endl; }
	catch (std::exception &e) { fStdVector<<"Error1: "<<e.what()<<std::endl; }
	///////////////////// Test erase
	try { v1.resize(-10, 12); }
	catch (std::exception &e) { fStdVector<<"Error2: "<<e.what()<<std::endl; }
	///////////////////// Test reserve
	try {v1.reserve(-10);}
	catch (std::exception &e) { fStdVector<<"Error3: "<<e.what()<<std::endl; }
	///////////////////// Test Vector
	try {std::vector<int> v(-1, 10);}
	catch (std::exception &e) { fStdVector<<"Error4: "<<e.what()<<std::endl; }
	///////////////////// Test insert
	std::vector<int> v(5, 0);
	try {v.insert(v.begin(), -10, 5);}
	catch (std::exception &e) { fStdVector<<"Error5: "<<e.what()<<std::endl; }
	///////////////////// Test assign
	try {v.assign(-10, 5);}
	catch (std::exception &e) { fStdVector<<"Error6: "<<e.what()<<std::endl; }
}

void vectorTestRelationalOperatorsStd(){
	fStdVector<<"---Vector-Test-RelationalOperators-(namespace:std)---"<<std::endl;
	std::vector<int> std1;
	std::vector<int> std2;
	std::vector<int> std11;
	std::vector<int> std12;
	boolTest(std1, std2, fStdVector);
	std1.push_back(1);
	std2.push_back(2);
	std11.push_back(1);
	std11.push_back(1);
	std12.push_back(1);
	std12.push_back(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11, fStdVector);
	boolTest(std11, std12, fStdVector);
	boolTest(std1, std11, fStdVector);
	boolTest(std12, std11, fStdVector);
	boolTest(std11, std1, fStdVector);
	boolTest(std11, std2, fStdVector);
	std1.clear();
	std2.clear();
	boolTest(std1, std2, fStdVector);
	fStdVector<<(int)std::lexicographical_compare(std1.begin(), std1.end(), std2.begin(), std2.end())<<std::endl;
	fStdVector<<(int)std::lexicographical_compare(std11.begin(), std11.end(), std2.begin(), std2.end())<<std::endl;
	fStdVector<<(int)std::lexicographical_compare(std12.begin(), std12.end(), std2.begin(), std2.end())<<std::endl;
	fStdVector<<(int)std::lexicographical_compare(std2.begin(), std2.end(), std2.begin(), std2.end())<<std::endl;
	fStdVector<<(int)std::lexicographical_compare(std2.begin(), std2.end(), std12.begin(), std12.end())<<std::endl;
}