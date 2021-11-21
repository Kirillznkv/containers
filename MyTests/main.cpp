#include <iostream>

#define BLOCK_COLOR "\033[38;2;0;0;0;48;2;255;255;0m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

void stackTestInt();
void stackTestString();
void stackTestList();

void vectorTestBase();
void vectorTestDouble();
void vectorTestList();
void vectorTestIterator();
void vectorTestReverseIterator();
void vectorTestModifiers();

void	stackTest(){
	std::cout<<BLOCK_COLOR"----------STACK-TEST----------"RESET_COLOR<<std::endl;
	stackTestInt();
	stackTestString();
	stackTestList();
}

void	vectorTest(){
	std::cout<<BLOCK_COLOR"----------VECTOR-TEST----------"RESET_COLOR<<std::endl;
	vectorTestBase();
	vectorTestDouble();
	vectorTestList();
	vectorTestIterator();
	vectorTestReverseIterator();
	vectorTestModifiers();
}

int		main() {
	stackTest();
	vectorTest();
	return (0);
}
