#include <stack>
#include <sstream>
#include "TestsUtils.hpp"


// template <typename T>
// void boolTest(T v1, T v2, std::ofstream & out){
// 	out			<<(int)(v1 == v2)<<" " \
// 				<<(int)(v1 != v2)<<" " \
// 				<<(int)(v1 <= v2)<<" " \
// 				<<(int)(v1 >= v2)<<" " \
// 				<<(int)(v1 < v2)<<" " \
// 				<<(int)(v1 > v2)<<std::endl;
// }

// Empty, Size, Push, Pop, Top + copy constructor + operator=
void stackTestIntStd(void){
	fStdStack<<"---Stack-Test-Int-(namespace:std)---"<<std::endl;
	std::stack<int> s1;
	fStdStack<<s1.empty()<<std::endl; // Empty
	s1.push(4); // Push
	fStdStack<<s1.top()<<std::endl; // Top
	s1.push(40);
	fStdStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i)
		s1.push(i);
	fStdStack<<s1.top()<<std::endl;
	fStdStack<<s1.size()<<std::endl; // Size
	fStdStack<<s1.empty()<<std::endl;
	std::stack<int> s1_copy(s1);
	fStdStack<<s1_copy.top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<int> s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1_copy2.top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
}

// Test whis classes into arg
void stackTestStringStd(void){
	fStdStack<<"---Stack-Test-String-(namespace:std)---"<<std::endl;
	std::stack<std::string> s1;
	fStdStack<<s1.empty()<<std::endl; // Empty
	s1.push("Hello"); // Push
	fStdStack<<s1.top()<<std::endl; //Top
	s1.push("World");
	fStdStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		std::ostringstream ss;
		ss << i;
		std::string str(ss.str());
		s1.push("Str #" + str);
	}
	fStdStack<<s1.top()<<std::endl;
	fStdStack<<s1.size()<<std::endl; // Size
	fStdStack<<s1.empty()<<std::endl;
	std::stack<std::string> s1_copy(s1);
	fStdStack<<s1_copy.top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<std::string> s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1_copy2.top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
}

// Test whis template into arg
void stackTestListStd(void){
	fStdStack<<"---Stack-Test-List-(namespace:std)---"<<std::endl;
	std::stack<std::stack<int> > s1;
	std::stack<int> myList;
	fStdStack<<s1.empty()<<std::endl;
	myList.push(5);
	s1.push(myList); // Push
	fStdStack<<s1.top().top()<<std::endl;
	myList.push(10);
	s1.push(myList);
	fStdStack<<s1.top().top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top().top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		myList.push(i);
		s1.push(myList);
	}
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1.size()<<std::endl;
	fStdStack<<s1.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy(s1);
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
	fStdStack<<(int)(s1_copy2.top().top() == s1_copy2.top().top())<<std::endl;
	boolTest(s1, s1_copy, fStdStack);
}

void stackTestRelationalOperatorsStd(){
	fStdStack<<"---Vector-Test-RelationalOperators-(namespace:std)---"<<std::endl;
	std::stack<int> std1;
	std::stack<int> std2;
	std::stack<int> std11;
	std::stack<int> std12;
	boolTest(std1, std2, fStdStack);
	std1.push(1);
	std2.push(2);
	std11.push(1);
	std11.push(1);
	std12.push(1);
	std12.push(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11, fStdStack);
	boolTest(std11, std12, fStdStack);
	boolTest(std1, std11, fStdStack);
	boolTest(std12, std11, fStdStack);
	boolTest(std11, std1, fStdStack);
	boolTest(std11, std2, fStdStack);
}