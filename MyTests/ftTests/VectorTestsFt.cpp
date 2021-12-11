#include "../../container/vector.hpp"
#include "TestsUtils.hpp"

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
	typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
	for (--n; n > 0; n -= 2) {
		typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
		*first++ = *--last;
		*last = tmp;
	}
}

void	vectorTestBaseFt(){
	fFtVector<<"---Vector-Test-Base-(namespace:ft)---"<<std::endl;
	//Test size, capacity, max_size
	ft::vector<int> v1;
	outSizes(v1, fFtVector);
	v1.push_back(21);
	outSizes(v1, fFtVector);
	v1.push_back(42);
	outSizes(v1, fFtVector);
	//Test front/back
	fFtVector<<v1.front()<<std::endl;
	fFtVector<<++(v1.front())<<std::endl;
	fFtVector<<v1.back()<<std::endl;
	fFtVector<<++(v1.back())<<std::endl;
	//Test [] / at()
	fFtVector<<v1[1]<<std::endl;
	fFtVector<<v1.at(1)<<std::endl;
	//Test reserve
	ft::vector<int> vec1;
	vec1.reserve(100);
	outSizes(vec1, fFtVector);
	vec1.push_back(21);
	outSizes(vec1, fFtVector);
	vec1.push_back(42);
	outSizes(vec1, fFtVector);
	//Test resize
	v1.resize(2);
	outSizes(v1, fFtVector);
	v1.resize(12);
	outSizes(v1, fFtVector);
	v1.resize(1);
	outSizes(v1, fFtVector);
	ft::vector<int> t1;
	t1.resize(20);
	outSizes(t1, fFtVector);
	//Test create
	ft::vector<int> ve(2, 1);
	outSizes(ve, fFtVector);
	fFtVector<<ve.front()<<std::endl;
	ft::vector<int> ve1(2);
	outSizes(ve1, fFtVector);
	fFtVector<<ve1.front()<<std::endl;
	//Test v1(Iter, Iter)
	ft::vector<int> s21(ve.begin(), ve.end());
	outSizes(s21, fFtVector);
	fFtVector<<"front = "<<s21.front()<<std::endl;
	//Test iterator_traits
	fFtVector<<"---Vector-Test-Iterator_traits-(namespace:std)---"<<std::endl;
    {
		ft::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		my_reverse(v.begin(), v.end());
		for (int n = 0; n < (int)v.size();++n)
			fFtVector << v[n] << ' ';
		fFtVector << std::endl;
	
		ft::vector<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		my_reverse(l.begin(), l.end());
		for (int n = 0; n < (int)l.size();++n)
			fFtVector << l[n] << ' ';
		fFtVector << std::endl;
	
		int a[] = {1, 2, 3, 4, 5};
		my_reverse(a, a + 5);
		for (int n = 0; n < 5;++n)
			fFtVector << a[n] << ' ';
		fFtVector << std::endl;
	}
}

void	vectorTestDoubleFt(){
	fFtVector<<"---Vector-Test-Double-(namespace:ft)---"<<std::endl;
	ft::vector<double> v1;
	for (double i = 0.01; i < 5.078; i += 0.035)
		v1.push_back(i);
	outSizes(v1, fFtVector);
	ft::vector<double> vec1;
	vec1.reserve(144);
	for (double i = 0.01; i < 5.078; i += 0.035)
		vec1.push_back(i);
	outSizes(vec1, fFtVector);
	// Test base iterators
	ft::vector<double>::iterator it1 = vec1.begin();
	for (;it1 < vec1.end(); it1 += 10)
		fFtVector<<*it1<<std::endl;
}

void	vectorTestListFt(){
	fFtVector<<"---Vector-Test-List-(namespace:ft)---"<<std::endl;
	ft::vector<ft::vector<int> > v1;
	ft::vector<int> vec1[5];
	for (int i = 0; i < 5; ++i){
		for (int val = 10; val < 1000; val += 13 + i)
			vec1[i].push_back(val);
		v1.push_back(vec1[i]);
	}
	outSizes(v1, fFtVector);
}

void	vectorTestIteratorFt(){
	fFtVector<<"---Vector-Test-Iterator-(namespace:ft)---"<<std::endl;
	// Test ++ -- += -= ...
	ft::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	ft::vector<char>::iterator itStd;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); ++itStd)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd += 1)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd = itStd + 1)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.begin(); itStd < stdVec.end(); itStd += 3, i += 3){
		++(*itStd);
		fFtVector<<*itStd<<stdVec[i];
	}
	fFtVector<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.end() - 1; itStd >= stdVec.begin(); itStd--, i--){
		fFtVector<<*itStd<<stdVec[i];
	}
	fFtVector<<std::endl;
	///////////////////// Test post++ prev++ iterator
	ft::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	fFtVector<<*(++stdVec2.begin())<<std::endl;
	fFtVector<<*(stdVec2.begin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	ft::vector<char>::iterator it1Beg = stdVec2.begin();
	ft::vector<char>::iterator it1End = stdVec2.end();
	fFtVector<<*(it1End - 1)<<std::endl;
	fFtVector<<it1End - it1Beg<<std::endl;
}

void vectorTestReverseIteratorFt(){
	fFtVector<<"---Vector-Test-ReverseIterator-(namespace:ft)---"<<std::endl;
	// Test ++ -- += -= ...
	ft::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	ft::vector<char>::reverse_iterator itStd;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); ++itStd)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd += 1)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd = itStd + 1)
		fFtVector<<*itStd;
	fFtVector<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.rbegin(); itStd < stdVec.rend(); itStd += 3, i += 3){
		++(*itStd);
		fFtVector<<*itStd<<stdVec[i];
	}
	fFtVector<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.rend() - 1; itStd >= stdVec.rbegin(); itStd--, i--){
		fFtVector<<*itStd<<stdVec[i];
	}
	///////////////////// Test post++ prev++ iterator
	ft::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	fFtVector<<*(++stdVec2.rbegin())<<std::endl;
	fFtVector<<*(stdVec2.rbegin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	ft::vector<char>::reverse_iterator it1Beg = stdVec2.rbegin();
	ft::vector<char>::reverse_iterator it1End = stdVec2.rend();
	fFtVector<<*(it1End - 1)<<std::endl;
	fFtVector<<it1End - it1Beg<<std::endl;
}

void	vectorTestModifiersFt(){
	fFtVector<<"---Vector-Test-Modifiers-(namespace:ft)---"<<std::endl;
	///////////////////// Test assign #1
	ft::vector<int> v1, v1New;
	for (int i = 0; i < 10; ++i)
		v1.push_back(i);
	for (int i = 0; i < 100; ++i)
		v1New.push_back(i);
	outSizes(v1, fFtVector);
	outSizes(v1New, fFtVector);
	v1.assign(5, 123);
	outSizes(v1, fFtVector);
	v1.assign(50, 2);
	outSizes(v1, fFtVector);
	///////////////////// Test assign #2
	v1.assign(v1New.begin(), v1New.end());
	outSizes(v1, fFtVector);
	v1.assign(v1New.begin(), v1New.begin() + 10);
	outSizes(v1, fFtVector);
	int myints[] = {1776,7,4};
	v1.assign(myints,myints+3);
	outSizes(v1, fFtVector);
	///////////////////// Test insert #1
	ft::vector<int>::iterator it = v1.insert(v1.begin(), 100);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i]<<" ";
	outSizes(v1, fFtVector);
	fFtVector<<"\t"<<*it<<std::endl;
	///////////////////// Test insert #2
	v1.insert(v1.begin(), 5, 1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i]<<" ";
	outSizes(v1, fFtVector);
	///////////////////// Test insert #3
	ft::vector<int> putVec1(10, 0);
	v1.insert(v1.begin() + 1, putVec1.begin(), putVec1.end());
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i]<<" ";
	outSizes(v1, fFtVector);
	ft::vector<int> a, b;
	a.insert(a.begin(), putVec1.begin(), putVec1.end());
	b.insert(b.end(), putVec1.begin(), putVec1.end());
	for (int i = 0; i < (int)a.size(); ++i)
		fFtVector<<a[i]<<" ";
	outSizes(a, fFtVector);
	for (int i = 0; i < (int)b.size(); ++i)
		fFtVector<<b[i]<<" ";
	outSizes(b, fFtVector);
	///////////////////// Test erase #1
	ft::vector<int>::iterator itEr1 = v1.erase(v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i]<<" ";
	fFtVector<<*itEr1<<std::endl;
	outSizes(v1, fFtVector);
	///////////////////// Test erase #2
	ft::vector<int>::iterator itEr12 = v1.erase(v1.begin(), v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i]<<" ";
	fFtVector<<*itEr12<<std::endl;
	///////////////////// Test swap
	{
	ft::vector<int> v1(20, 5);
	ft::vector<int> putVec1(10, 0);
	v1.swap(putVec1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i];
	fFtVector<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		fFtVector<<putVec1[i];
	fFtVector<<")"<<std::endl;
	outSizes(v1, fFtVector);
	outSizes(putVec1, fFtVector);
	ft::swap(v1, putVec1);
	for (int i = 0; i < (int)v1.size(); ++i)
		fFtVector<<v1[i];
	fFtVector<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		fFtVector<<putVec1[i];
	fFtVector<<")"<<std::endl;
	outSizes(v1, fFtVector);
	outSizes(putVec1, fFtVector);
	}
	///////////////////// Test clear
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	fFtVector << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		fFtVector << ' ' << myvector[i];
	fFtVector << std::endl;
	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	fFtVector << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		fFtVector << ' ' << myvector[i];
	fFtVector << std::endl;
}

void vectorTestExeptFt(){
	fFtVector<<"---Vector-Test-Exept-(namespace:ft)---"<<std::endl;
	///////////////////// Test at
	ft::vector<long long> v1;
	try { fFtVector<<v1.at(0)<<std::endl; }
	catch (std::exception &e) { fFtVector<<"Error1: "<<e.what()<<std::endl; }
	///////////////////// Test erase
	try { v1.resize(-10, 12); }
	catch (std::exception &e) { fFtVector<<"Error2: "<<e.what()<<std::endl; }
}

void vectorTestRelationalOperatorsFt(){
	fFtVector<<"---Vector-Test-RelationalOperators-(namespace:ft)---"<<std::endl;
	ft::vector<int> std1;
	ft::vector<int> std2;
	ft::vector<int> std11;
	ft::vector<int> std12;
	boolTest(std1, std2, fFtVector);
	std1.push_back(1);
	std2.push_back(2);
	std11.push_back(1);
	std11.push_back(1);
	std12.push_back(1);
	std12.push_back(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11, fFtVector);
	boolTest(std11, std12, fFtVector);
	boolTest(std1, std11, fFtVector);
	boolTest(std12, std11, fFtVector);
	boolTest(std11, std1, fFtVector);
	boolTest(std11, std2, fFtVector);
	std1.clear();
	std2.clear();
	boolTest(std1, std2, fFtVector);
	fFtVector<<(int)ft::lexicographical_compare(std1.begin(), std1.end(), std2.begin(), std2.end())<<std::endl;
	fFtVector<<(int)ft::lexicographical_compare(std11.begin(), std11.end(), std2.begin(), std2.end())<<std::endl;
	fFtVector<<(int)ft::lexicographical_compare(std12.begin(), std12.end(), std2.begin(), std2.end())<<std::endl;
	fFtVector<<(int)ft::lexicographical_compare(std2.begin(), std2.end(), std2.begin(), std2.end())<<std::endl;
	fFtVector<<(int)ft::lexicographical_compare(std2.begin(), std2.end(), std12.begin(), std12.end())<<std::endl;
}