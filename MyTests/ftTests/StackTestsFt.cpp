#include "../../container/stack/stack.hpp"
#include <sstream>
#include "TestsUtils.hpp"
#include <string>

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
void stackTestIntFt(void){
	fFtStack<<"---Stack-Test-Int-(namespace:ft)---"<<std::endl;
	ft::stack<int> s1;
	fFtStack<<s1.empty()<<std::endl; // Empty
	s1.push(4); // Push
	fFtStack<<s1.top()<<std::endl; // Top
	s1.push(40);
	fFtStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fFtStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i)
		s1.push(i);
	fFtStack<<s1.top()<<std::endl;
	fFtStack<<s1.size()<<std::endl; // Size
	fFtStack<<s1.empty()<<std::endl;
	ft::stack<int> s1_copy(s1);
	fFtStack<<s1_copy.top()<<std::endl;
	fFtStack<<s1_copy.size()<<std::endl;
	fFtStack<<s1_copy.empty()<<std::endl;
	ft::stack<int> s1_copy2;
	s1_copy2 = s1;
	fFtStack<<s1_copy2.top()<<std::endl;
	fFtStack<<s1_copy2.size()<<std::endl;
	fFtStack<<s1_copy2.empty()<<std::endl;
}

// Test whis classes into arg
void stackTestStringFt(void){
	fFtStack<<"---Stack-Test-String-(namespace:ft)---"<<std::endl;
	ft::stack<std::string> s1;
	fFtStack<<s1.empty()<<std::endl; // Empty
	s1.push("Hello"); // Push
	fFtStack<<s1.top()<<std::endl; //Top
	s1.push("World");
	fFtStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fFtStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		std::ostringstream ss;
		ss << i;
		std::string str(ss.str());
		s1.push("Str #" + str);
	}
	fFtStack<<s1.top()<<std::endl;
	fFtStack<<s1.size()<<std::endl; // Size
	fFtStack<<s1.empty()<<std::endl;
	ft::stack<std::string> s1_copy(s1);
	fFtStack<<s1_copy.top()<<std::endl;
	fFtStack<<s1_copy.size()<<std::endl;
	fFtStack<<s1_copy.empty()<<std::endl;
	ft::stack<std::string> s1_copy2;
	s1_copy2 = s1;
	fFtStack<<s1_copy2.top()<<std::endl;
	fFtStack<<s1_copy2.size()<<std::endl;
	fFtStack<<s1_copy2.empty()<<std::endl;
}

// Test whis template into arg
void stackTestListFt(void){
	fFtStack<<"---Stack-Test-List-(namespace:ft)---"<<std::endl;
	ft::stack<ft::stack<int> > s1;
	ft::stack<int> myList;
	fFtStack<<s1.empty()<<std::endl;
	myList.push(5);
	s1.push(myList); // Push
	fFtStack<<s1.top().top()<<std::endl;
	myList.push(10);
	s1.push(myList);
	fFtStack<<s1.top().top()<<std::endl;
	s1.pop(); // Pop
	fFtStack<<s1.top().top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		myList.push(i);
		s1.push(myList);
	}
	fFtStack<<s1.top().top()<<std::endl;
	fFtStack<<s1.size()<<std::endl;
	fFtStack<<s1.empty()<<std::endl;
	ft::stack<ft::stack<int> > s1_copy(s1);
	fFtStack<<s1.top().top()<<std::endl;
	fFtStack<<s1_copy.size()<<std::endl;
	fFtStack<<s1_copy.empty()<<std::endl;
	ft::stack<ft::stack<int> > s1_copy2;
	s1_copy2 = s1;
	fFtStack<<s1.top().top()<<std::endl;
	fFtStack<<s1_copy2.size()<<std::endl;
	fFtStack<<s1_copy2.empty()<<std::endl;
	fFtStack<<(int)(s1_copy2.top().top() == s1_copy2.top().top())<<std::endl;
	boolTest(s1, s1_copy, fFtStack);
}

void stackTestRelationalOperatorsFt(){
	fFtStack<<"---Vector-Test-RelationalOperators-(namespace:std)---"<<std::endl;
	std::stack<int> std1;
	std::stack<int> std2;
	std::stack<int> std11;
	std::stack<int> std12;
	boolTest(std1, std2, fFtStack);
	std1.push(1);
	std2.push(2);
	std11.push(1);
	std11.push(1);
	std12.push(1);
	std12.push(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11, fFtStack);
	boolTest(std11, std12, fFtStack);
	boolTest(std1, std11, fFtStack);
	boolTest(std12, std11, fFtStack);
	boolTest(std11, std1, fFtStack);
	boolTest(std11, std2, fFtStack);
}