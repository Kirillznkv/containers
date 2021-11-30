#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft{

template <class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
class myIterator{
protected:
	T *pVal;
public:
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
	myIterator() : pVal(NULL){}
	myIterator(T *val){
		pVal = val;
	}
	myIterator(const myIterator& copy){
		this->operator=(copy);
	}
	virtual ~myIterator(){};
	/*virtual */myIterator &operator=(const myIterator& op){
		if (this == &op)
			return (*this);
		pVal = op.pVal;
		return (*this);
	}
	/*virtual */myIterator &operator ++ (void){
		++pVal;
		return (*this);
	}
	/*virtual */myIterator operator ++ (int){
		myIterator it(pVal++);
		return (it);
	}
	/*virtual */myIterator &operator -- (void){
		--pVal;
		return (*this);
	}
	/*virtual */myIterator operator -- (int){
		myIterator it(pVal--);
		return (it);
	}
	/*virtual */myIterator &operator -= (int rVal){
		pVal -= rVal;
		return (*this);
	}
	/*virtual */myIterator &operator += (int rVal){
		pVal += rVal;
		return (*this);
	}
	/*virtual */int	 operator - (const myIterator& rVal) const{
		return (pVal - rVal.pVal);
	}
	/*virtual */myIterator operator - (int rVal){
		return (myIterator(pVal - rVal));
	}
	/*virtual */myIterator operator + (int rVal){
		return (myIterator(pVal + rVal));
	}
	/*virtual */bool operator == (const myIterator& rVal) const{
		return (pVal == rVal.pVal);
	}
	/*virtual */bool operator != (const myIterator& rVal) const{
		return (pVal != rVal.pVal);
	}
	/*virtual */bool operator <= (const myIterator& rVal) const{
		return (pVal <= rVal.pVal);
	}
	/*virtual */bool operator >= (const myIterator& rVal) const{
		return (pVal >= rVal.pVal);
	}
	/*virtual */bool operator < (const myIterator& rVal) const{
		return (pVal < rVal.pVal);
	}
	/*virtual */bool operator > (const myIterator& rVal) const{
		return (pVal > rVal.pVal);
	}
	virtual T&	operator* (){
		return (*pVal);
	}
};

}

#endif