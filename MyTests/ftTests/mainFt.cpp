#include "TestsUtils.hpp"

/////////////////////////////
/*----------Stack----------*/
/////////////////////////////
void stackTestIntFt();
void stackTestStringFt();
void stackTestListFt();

//////////////////////////////
/*----------Vector----------*/
//////////////////////////////
void vectorTestBaseFt();
void vectorTestDoubleFt();
void vectorTestListFt();
void vectorTestIteratorFt();
void vectorTestReverseIteratorFt();
void vectorTestModifiersFt();
void vectorTestExeptFt();
void vectorTestRelationalOperatorsFt();

/////////////////////////////
/*----------Tests----------*/
/////////////////////////////
void	stackTestFt() {
	stackTestIntFt();
	stackTestStringFt();
	stackTestListFt();
	fFtStack.close();
}
void	vectorTestFt() {
	vectorTestBaseFt();
	vectorTestDoubleFt();
	vectorTestListFt();
	vectorTestIteratorFt();
	vectorTestReverseIteratorFt();
	vectorTestModifiersFt();
	vectorTestExeptFt();
	vectorTestRelationalOperatorsFt();
	fFtVector.close();
}

int		main() {
	stackTestFt();
	vectorTestFt();
	return (0);
}
