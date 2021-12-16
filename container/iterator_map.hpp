#ifndef ITERATOR_MAP_HPP
#define ITERATOR_MAP_HPP

# include <iostream>

namespace ft{

template<class T>
struct node{
	T			*value;
	node		*parent;
	node		*left;
	node		*right;

	node() : value(NULL), parent(NULL), left(NULL), right(NULL){}
	node(T *v, node *p, node *l, node *r) : value(v), parent(p), left(l), right(r){}
	node(const node& copy) { this->operator=(copy); }
	~node(){}
	node& operator=(const node& op){
		value = op.value;
		parent = op.parent;
		left = op.left;
		right = op.right;
		return (*this);
	}
};

template <class T, class Category = std::forward_iterator_tag, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
class myIteratorMap{
public:
    typedef ft::node<T>		value_type;
    typedef Distance		difference_type;
    typedef Pointer			pointer;
    typedef Reference		reference;
    typedef Category		iterator_category;
protected:
	bool isNotNil(value_type *val) { return ((val && val->right) ? false : true); }
protected:
	value_type *pVal;
public:
    typedef ft::node<T>		value_type;
    typedef Distance		difference_type;
    typedef Pointer			pointer;
    typedef Reference		reference;
    typedef Category		iterator_category;
	myIteratorMap() : pVal(NULL){}
	myIteratorMap(value_type *val){
		pVal = val;
	}
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
		value_type *res = pVal;
		if (isNotNil(res->right)){
			res = res->right;
			while (isNotNil(res->left))
				res = res->left;
		}
		else{
			while (res->parent && (res->parent->right == res))
				res = res->parent;
			if (!(res->parent))
				res = pVal->right;
			else
				res = res->parent;
		}
		pVal = res;
		return (*this);
	}
	myIteratorMap operator ++ (int){
		myIteratorMap it(pVal);
		value_type *res = pVal;
		if (isNotNil(res->right)){
			res = res->right;
			while (isNotNil(res->left))
				res = res->left;
		}
		else{
			while (res->parent && (res->parent->right == res))
				res = res->parent;
			if (!(res->parent))
				res = pVal->right;
			else
				res = res->parent;
		}
		pVal = res;
		return (it);
	}
	myIteratorMap &operator -- (void){
		--pVal;
		return (*this);
	}
	// myIteratorMap operator -- (int){
	// 	myIteratorMap it(pVal--);
	// 	return (it);
	// }
	virtual value_type&	operator* (){
		return (*pVal);
	}
};

}

#endif