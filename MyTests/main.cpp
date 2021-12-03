#include <iostream>

#define BLOCK_COLOR "\033[38;2;0;0;0;48;2;255;255;0m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

void stackTestInt();
void stackTestString();
void stackTestList();

//////////////////////////////
/*----------Vector----------*/
//////////////////////////////
void vectorTestBaseStd();
void vectorTestBaseFt();
void vectorTestDoubleStd();
void vectorTestDoubleFt();
void vectorTestListStd();
void vectorTestListFt();
void vectorTestIteratorStd();
void vectorTestIteratorFt();
void vectorTestReverseIteratorStd();
void vectorTestReverseIteratorFt();
void vectorTestModifiersStd();
void vectorTestModifiersFt();
void vectorTestExeptStd();
void vectorTestExeptFt();
void vectorTestRelationalOperatorsStd();
void vectorTestRelationalOperatorsFt();
/*------------------------*/
void vectorTestBase(){
	vectorTestBaseStd();
	vectorTestBaseFt();
}
void vectorTestDouble(){
	vectorTestDoubleStd();
	vectorTestDoubleFt();
}
void vectorTestList(){
	vectorTestListStd();
	vectorTestListFt();
}
void vectorTestIterator(){
	vectorTestIteratorStd();
	vectorTestIteratorFt();
}
void vectorTestReverseIterator(){
	vectorTestReverseIteratorStd();
	vectorTestReverseIteratorFt();
}
void vectorTestModifiers(){
	vectorTestModifiersStd();
	vectorTestModifiersFt();
}
void vectorTestExept(){
	vectorTestExeptStd();
	vectorTestExeptFt();
}
void vectorTestRelationalOperators(){
	vectorTestRelationalOperatorsStd();
	vectorTestRelationalOperatorsFt();
}/*------------------------*/
/*------------------------*/

/////////////////////////////
/*----------Tests----------*/
/////////////////////////////
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
	vectorTestExept();
	vectorTestRelationalOperators();
}

int		main() {
	stackTest();
	vectorTest();
	return (0);
}
