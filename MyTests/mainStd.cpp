#include <iostream>

#define BLOCK_COLOR "\033[38;2;0;0;0;48;2;255;255;0m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

/////////////////////////////
/*----------Stack----------*/
/////////////////////////////
void stackTestIntStd();
void stackTestStringStd();
void stackTestListStd();

//////////////////////////////
/*----------Vector----------*/
//////////////////////////////
void vectorTestBaseStd();
void vectorTestDoubleStd();
void vectorTestListStd();
void vectorTestIteratorStd();
void vectorTestReverseIteratorStd();
void vectorTestModifiersStd();
void vectorTestExeptStd();
void vectorTestRelationalOperatorsStd();

/////////////////////////////
/*----------Tests----------*/
/////////////////////////////
void	stackTest(){
	std::cout<<BLOCK_COLOR"----------STACK-TEST----------"RESET_COLOR<<std::endl;
	stackTestIntStd();
	stackTestStringStd();
	stackTestListStd();
}
void	vectorTest(){
	std::cout<<BLOCK_COLOR"----------VECTOR-TEST----------"RESET_COLOR<<std::endl;
	vectorTestBaseStd();
	vectorTestDoubleStd();
	vectorTestListStd();
	vectorTestIteratorStd();
	vectorTestReverseIteratorStd();
	vectorTestModifiersStd();
	vectorTestExeptStd();
	vectorTestRelationalOperatorsStd();
}

int		main() {
	stackTest();
	vectorTest();
	return (0);
}
