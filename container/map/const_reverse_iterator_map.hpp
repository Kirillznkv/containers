#ifndef CONST_REVERSE_ITERATOR_MAP_HPP
#define CONST_REVERSE_ITERATOR_MAP_HPP

# include "const_iterator_map.hpp"

namespace ft{

template	<class T = ft::pair<class Key, class Value>,
			class Category = std::forward_iterator_tag,
			class Distance = ptrdiff_t,
			class Pointer = const T*,
			class Reference = const T&>
class myConstReverseIteratorMap : public myConstIteratorMap<T, Category, Distance, Pointer, Reference>{
protected:
	typedef ft::myNode<T> node;
public:
	myConstReverseIteratorMap(node *val = NULL) : myConstIteratorMap<T, Category, Distance, Pointer, Reference>(val){}
	myConstReverseIteratorMap(const myConstReverseIteratorMap& copy){
		this->operator=(copy);
	}
	virtual ~myConstReverseIteratorMap(){};
	myConstReverseIteratorMap &operator=(const myConstReverseIteratorMap& op){
		if (this == &op)
			return (*this);
		this->pVal = op.pVal;
		return (*this);
	}
	myConstReverseIteratorMap &operator ++ (void){
		node *nil = this->pVal->left;
		if ((this->pVal->isNil()))
			this->pVal = this->pVal->parent;
		else if (!(this->pVal->left->isNil())){
			this->pVal = this->pVal->left;
			while (!(this->pVal->right->isNil()))
				this->pVal = this->pVal->right;
		}
		else{
			while (this->pVal->parent && this->pVal->parent->left == this->pVal)
				this->pVal = this->pVal->parent;
			if (!(this->pVal->parent))
				this->pVal = nil;
			else
				this->pVal = this->pVal->parent;
		}
		return (*this);
	}
	myConstReverseIteratorMap operator ++ (int){
		myConstReverseIteratorMap it(this->pVal);
		this->operator++();
		return (it);
	}
	myConstReverseIteratorMap &operator -- (void){
		node *nil = this->pVal->right;
		if ((this->pVal->isNil()))
			return(*this);
		else if (!(this->pVal->right->isNil())){
			this->pVal = this->pVal->right;
			while (!(this->pVal->left->isNil()))
				this->pVal = this->pVal->left;
		}
		else{
			while (this->pVal->parent && this->pVal->parent->right == this->pVal)
				this->pVal = this->pVal->parent;
			if (!(this->pVal->parent))
				this->pVal = nil;
			else
				this->pVal = this->pVal->parent;
		}
		return (*this);
	}
	myConstReverseIteratorMap operator -- (int){
		myConstReverseIteratorMap it(this->pVal);
		this->operator--();
		return (it);
	}
	myConstReverseIteratorMap &operator+=(int col){
		for (int i = 0; i < col; ++i)
			this->operator++();
		return (*this);
	}
	myConstReverseIteratorMap &operator-=(int col){
		for (int i = 0; i < col; ++i)
			this->operator--();
		return (*this);
	}
	myConstReverseIteratorMap operator+(int col){
		myConstReverseIteratorMap it(*this);
		for (int i = 0; i < col; ++i)
			it.operator++();
		return (it);
	}
	myConstReverseIteratorMap operator-(int col){
		myConstReverseIteratorMap it(*this);
		for (int i = 0; i < col; ++i)
			it.operator--();
		return (it);
	}
	const T&	operator* (){
		myConstReverseIteratorMap it((*this) + 1);
		return ((it.pVal)->value);
	}
	const T	*operator->() {
		myConstReverseIteratorMap it((*this) + 1);
		return (&(it.pVal->value));
	}
	bool operator==(const myConstReverseIteratorMap& op){
		return (this->pVal == op.pVal);
	}
	bool operator!=(const myConstReverseIteratorMap& op){
		return (this->pVal != op.pVal);
	}
	const T &operator[](unsigned int __n) const {return *(*this + __n);}
	myConstIteratorMap<T, Category, Distance, Pointer, Reference> base() {
		return (myConstIteratorMap<T, Category, Distance, Pointer, Reference>(this->pVal));
	}
};

}

#endif