#include <iostream>
#include <deque>//??
#include <map>
#include <stack>
#include <list>
#include <vector>

#define BLOCK_COLOR "\033[38;2;0;0;0;48;2;255;255;0m"
#define TYPE_COLOR "\033[38;2;0;255;255m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

#include "container.hpp"
#include "stack.hpp"

template <typename T>
void out(const T& v1,const T& v2){
	std::cout<<v1<<"\t\t\t"<<v2<<std::endl;
}

void stackTestInt(void){
	std::cout<<TYPE_COLOR"(INT)"RESET_COLOR<<std::endl;
	std::stack<int> s1;
	ft::stack<int> s2;
	out(s1.empty(), s2.empty());
	s1.push(4);
	s2.push(4);
	out(s1.top(), s2.top());
	s1.push(40);
	s2.push(40);
	out(s1.top(), s2.top());
	s1.pop();
	s2.pop();
	out(s1.top(), s2.top());
	for (int i = 0; i < 100; ++i){
		s1.push(i);
		s2.push(i);
	}
	out(s1.top(), s2.top());
	out(s1.size(), s2.size());
	out(s1.empty(), s2.empty());
	std::stack<int> s1_copy(s1);
	ft::stack<int> s2_copy(s2);
	out(s1_copy.top(), s2_copy.top());
	out(s1_copy.size(), s2_copy.size());
	out(s1_copy.empty(), s2_copy.empty());
	std::stack<int> s1_copy2;
	ft::stack<int> s2_copy2;
	s1_copy2 = s1;
	s2_copy2 = s2;
	out(s1_copy2.top(), s2_copy2.top());
	out(s1_copy2.size(), s2_copy2.size());
	out(s1_copy2.empty(), s2_copy2.empty());
}



void stackTest(void){
	std::cout<<BLOCK_COLOR"----------STACK-TEST----------"RESET_COLOR<<std::endl;
	stackTestInt();
}

int	main() {
	stackTest();
	return (0);
}
