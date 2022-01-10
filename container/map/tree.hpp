#ifndef TREE_HPP
#define TREE_HPP

# include "../utils.hpp"
# include "iterator_map.hpp"

namespace ft{

template <class Key, class T, class Compare = ft::less<Key>,
          class Allocator = std::allocator< pair< /*const */Key, T > > >
class tree{
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
private:
	node			*_parent;
	size_type		_size;
	allocator_type	_alloc;
	Compare			_cmp;
private:
	bool isNil(const value_type &val) const{
		return (val._isNil);
	}
	void removeOneNode(node *tmp){
		_alloc.destroy(tmp);
		_alloc.deallocate(tmp, 1);
	}
	void removeTree(node *tmp){
		if (tmp && !isNil(tmp->left))
			removeTree(tmp->left);
		else if (tmp)
			removeOneNode(tmp->left);
		if (tmp && !isNil(tmp->right))
			removeTree(tmp->right);
		else if (tmp)
			removeOneNode(tmp->right);
		if (tmp)
			removeOneNode(tmp);
	}
	node *cloneNode(node *tmp, node *parent){
		node *newNode;
		newNode = _alloc.allocate(1);
		_alloc.construct(newNode, node(tmp->value, parent));
		return (newNode);
	}
	void copyTree(node **dest, node *srcs){
		if (isNil(srcs)){
			*dest = _alloc.allocate(1);
			_alloc.construct(*dest, node((*dest)->parent), true);
		}
		else{
			*dest = cloneNode(srcs, *dest ? (*dest)->parent : NULL);
			if (!isNil(srcs->left))
				copyTree(&((*dest)->left));
			if (!isNil(srcs->right))
				copyTree(&((*dest)->right));

		}
	}
public:
	////////////////////////
	/*-----Constructs-----*/
	////////////////////////
	tree(const Compare &comp = Compare(), const allocator_type &alloc = allocator_type()) : _size(0), _cmp(comp), _alloc(alloc){}
	tree(const tree & copy) : _size(0){
		this->operator=(copy);
	}
	~tree(){
		removeTree(_parent);
	}
	///////////////////////
	/*-----Operators-----*/
	///////////////////////
	tree &operator=(const tree& op){
		if (this == &op)
			return (*this);
		if (_size)
			removeTree(_parent);
		copyTree(&_parent, op._parent);
		_size = op._size;
		return (*this);
	}
	//////////////////////
	/*-----Capacity-----*/
	//////////////////////
	bool empty() const{
		return (_size == 0);
	}
	size_type size() const{
		return (_size);
	}
	size_type max_size() const{
		size_type val = (pow(2, 64) / sizeof(value_type));
		val--;
		return (val);
	}
	///////////////////////
	/*-----Allocator-----*/
	///////////////////////
	allocator_type get_allocator() const{
		return (_alloc);
	}
	////////////////////////////
	/*-----Element-access-----*/
	////////////////////////////
	mapped_type& operator[] (/*const */key_type& k){
		if (_size == 0){
			_parent = _alloc.allocate(1);
			_alloc.construct(_parent, node(ft::make_pair( k, mapped_type() ), NULL))
		}
	}
};

}

#endif