#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft{

template<typename T>
class myItertor{
protected:
	T *pVal;
public:
	myItertor() : pVal(NULL){}
	myItertor(T *val){
		pVal = val;
	}
	myItertor(const myItertor& copy){
		this->operator=(copy);
	}
	virtual ~myItertor(){};
	virtual myItertor &operator=(const myItertor& op){
		if (this == &op)
			return (*this);
		pVal = op.pVal;
		return (*this);
	}
	virtual myItertor &operator ++ (void){
		++pVal;
		return (*this);
	}
	virtual myItertor operator ++ (int){
		myItertor it(pVal++);
		return (it);
	}
	virtual myItertor &operator -- (void){
		--pVal;
		return (*this);
	}
	virtual myItertor operator -- (int){
		myItertor it(pVal--);
		return (it);
	}
	virtual myItertor &operator -= (int rVal){
		pVal -= rVal;
		return (*this);
	}
	virtual myItertor &operator += (int rVal){
		pVal += rVal;
		return (*this);
	}
	virtual int	 operator - (const myItertor& rVal) const{
		return (pVal - rVal.pVal);
	}
	virtual myItertor operator - (int rVal){
		return (myItertor(pVal - rVal));
	}
	virtual myItertor operator + (int rVal){
		return (myItertor(pVal + rVal));
	}
	virtual bool operator == (const myItertor& rVal) const{
		return (pVal == rVal.pVal);
	}
	virtual bool operator != (const myItertor& rVal) const{
		return (pVal != rVal.pVal);
	}
	virtual bool operator <= (const myItertor& rVal) const{
		return (pVal <= rVal.pVal);
	}
	virtual bool operator >= (const myItertor& rVal) const{
		return (pVal >= rVal.pVal);
	}
	virtual bool operator < (const myItertor& rVal) const{
		return (pVal < rVal.pVal);
	}
	virtual bool operator > (const myItertor& rVal) const{
		return (pVal > rVal.pVal);
	}
	virtual T&	operator* (){
		return (*pVal);
	}
};

}

#endif