#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

# include <iostream>
# include "../utils.hpp"

namespace ft{

template<class T>
struct node{
	node		*parent;
	node		*left;
	node		*right;
	T			value;

	node() : value(), parent(NULL), left(NULL), right(NULL), _isNil(false){}
	node(node *p, const bool  nil = false) : value(), parent(p), left(NULL), right(NULL), _isNil(nil){}
	node(T &v, node *p, node *l = NULL, node *r = NULL) : value(v), parent(p), left(l), right(r), _isNil(false){}
	node(const node& copy) { this->operator=(copy); }
	~node(){}
	node& operator=(const node& op){
		value = op.value;
		parent = op.parent;
		left = op.left;
		right = op.right;
		return (*this);
	}
private:
	static const bool _isNil;
};

template <class T = ft::pair<class Key, class Value>, class Category = std::forward_iterator_tag, class Distance = ptrdiff_t,//add const to Key
          class Pointer = T*, class Reference = T&>
class myIteratorMap{
public:
	typedef ft::node<T>		value_type;
	typedef Distance		difference_type;
	typedef Pointer			pointer;
	typedef Reference		reference;
	typedef Category		iterator_category;
protected:
	bool isNil(const value_type &val) const { return (val._isNil); }
protected:
	value_type *pVal;
public:
	myIteratorMap() : pVal(){}// need *?
	myIteratorMap(value_type &val) : pval(val.value, val.parent, val.left, val.right){}
	myIteratorMap(const myIteratorMap& copy){
		this->operator=(copy);
	}
	virtual ~myIteratorMap(){};
	myIteratorMap &operator=(const myIteratorMap& op){
		if (this == &op)
			return (*this);
		pVal = op.pVal;
		return (*this);
	}
	myIteratorMap &operator ++ (void){
		value_type *res = pVal->right;
		if (!isNil(pVal->right)){
			pVal = pVal->right;
			while (!isNil(pVal->left))
				pVal = pVal->left;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->right == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
		return (myIteratorMap(res));
	}
	myIteratorMap operator ++ (int){
		myIteratorMap it(pVal);
		value_type *res = pVal->right;
		if (!isNil(pVal->right)){
			pVal = pVal->right;
			while (!isNil(pVal->left))
				pVal = pVal->left;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->right == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
		return (it);
	}
	myIteratorMap &operator -- (void){
		value_type *res = pVal->left;
		if (!isNil(pVal->left)){
			pVal = pVal->left;
			while (!isNil(pVal->right))
				pVal = pVal->right;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->left == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
		return (myIteratorMap(res));
	}
	myIteratorMap operator -- (int){
		myIteratorMap it(pVal);
		value_type *res = pVal->left;
		if (!isNil(pVal->left)){
			pVal = pVal->left;
			while (!isNil(pVal->right))
				pVal = pVal->right;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->left == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
		return (it);
	}
	virtual value_type&	operator* (){
		return (*pVal);
	}
	value_type *operator->() const{
		return (pVal);
	}
};

}

#endif