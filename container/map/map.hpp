#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>

# include "../utils.hpp"
# include "iterator_map.hpp"

namespace ft{

template <class Key, class T, class Compare = ft::less<Key>,
          class Allocator = std::allocator< pair< /*const */Key, T > > >
class map{
public:
	typedef Key										    key_type;
	typedef T										    mapped_type;
	typedef ft::pair</*const */key_type, mapped_type>	value_type;
    typedef Compare                                     key_compare;
    typedef Allocator                                   allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    typedef myIteratorMap<value_type>                   iterator;
    // typedef implementation-defined                   const_iterator;
    // typedef std::reverse_iterator<iterator>          reverse_iterator; // проблема с конструктором
    // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator; // проблема с конструктором
private:
	typedef ft::node<value_type> node;
	bool isNil(const value_type &val) const { return (val._isNil); }
private:
	node			*_parent;
	size_type		_size;
private:
	void removeOneNode(node *tmp){
		
	}
public:
	////////////////////////
	/*-----Constructs-----*/
	////////////////////////
	map() : _parent(), _size(0){}
	map(const map & copy){
		this->operator=(copy);
	}
	~map(){}//write it!!!
	///////////////////////
	/*-----Operators-----*/
	///////////////////////
	map &operator=(const map& op){
		if (this == &op)
			return (*this);
		return (*this);
	}
};

}

#endif