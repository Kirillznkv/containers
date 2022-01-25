#include "TestsUtils.hpp"

/////////////////////////////
/*----------Stack----------*/
/////////////////////////////
void stackTestIntFt();
void stackTestStringFt();
void stackTestListFt();
void stackTestRelationalOperatorsFt();
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
///////////////////////////
/*----------Map----------*/
///////////////////////////
void mapTestBaseFt();
void mapTestIteratorFt();
void mapTestObserversFt();
void mapTestOperationsFt();
void mapTestModifiersFt();

/////////////////////////////
/*----------Tests----------*/
/////////////////////////////
void	stackTestFt() {
	stackTestIntFt();
	stackTestStringFt();
	stackTestListFt();
	stackTestRelationalOperatorsFt();
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
void	mapTestFt() {
	mapTestBaseFt();
	mapTestIteratorFt();
	mapTestObserversFt();
	mapTestOperationsFt();
	mapTestModifiersFt();
	fFtMap.close();
}

int		main() {
	stackTestFt();
	vectorTestFt();
	mapTestFt();
	return (0);
}
