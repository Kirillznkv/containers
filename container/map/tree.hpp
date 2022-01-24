#ifndef TREE_HPP
#define TREE_HPP

# include "../utils.hpp"
# include <cmath>
# include "iterator_map.hpp"
# include "reverse_iterator_map.hpp"

namespace ft{

template <class Key, class T, class Compare = ft::less<Key>,
          class Allocator = std::allocator< pair< const Key, T > > >
class tree{
public:
	typedef Key										    key_type;
	typedef T										    mapped_type;
	typedef ft::pair<const key_type, mapped_type>		value_type;
    typedef Compare                                     key_compare;
    typedef ft::less<T>                                 value_compare;
    typedef Allocator                                   allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    typedef myIteratorMap<value_type>                   iterator;
    // typedef implementation-defined                   const_iterator;
    typedef myReverseIteratorMap<value_type>			reverse_iterator; // проблема с конструктором
    // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator; // проблема с конструктором
private:
	typedef ft::myNode<value_type> node;
private:
	node					*_parent;
	size_type				_size;
	std::allocator<node>	_alloc;
	allocator_type			_allocVal;
	key_compare				_cmp;
	value_compare			_valueCmp;
private:
	void removeOneNode(node *tmp){
		_alloc.destroy(tmp);
		_alloc.deallocate(tmp, 1);
	}
	void removeTree(node *tmp){
		if (tmp && !(tmp->left->isNil()))
			removeTree(tmp->left);
		else if (tmp)
			removeOneNode(tmp->left);
		if (tmp && !(tmp->right->isNil()))
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
	void addNode(node **dest, const key_type& k, mapped_type t = mapped_type()){
		*dest = _alloc.allocate(1);
		node *tmp = *dest;
		// node a(ft::make_pair( k, t ), NULL);
		_alloc.construct(tmp, node(ft::make_pair( k, t ), NULL));
	}
	void addNil(node **dest){
		*dest = _alloc.allocate(1);
		node *tmp = *dest;
		_alloc.construct(tmp, node(tmp, true));
	}
public:
	////////////////////////
	/*-----Constructs-----*/
	////////////////////////
	tree(const Compare &comp = Compare(), const allocator_type &alloc = allocator_type()) : _parent(NULL), _size(0), _cmp(comp), _alloc(alloc){}
	tree(const tree & copy) : _size(0){
		this->operator=(copy);
	}
	~tree(){
		removeTree(_parent);
		_parent = NULL;
		_size = 0;
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
	mapped_type& operator[] (const key_type& k){
		mapped_type *res;
		if (_size == 0){
			addNode(&_parent, k);
			addNil(&(_parent->left));
			addNil(&(_parent->right));
			_parent->right->parent = _parent;
			_parent->left->parent = _parent;
			_size++;
			res = &(_parent->value.second);
		}
		else{
			node *tmp = _parent;
			while (!(tmp->isNil())){
				if (_cmp(tmp->value.first, k))
					tmp = tmp->right;
				else if (tmp->value.first == k)
					break ;
				else
					tmp = tmp->left;
			}
			if (!(tmp->isNil()))
				res = &(tmp->value.second);
			else{
				node *p = tmp->parent;
				node **newTmp;
				if (p->right == tmp)
					newTmp = &(p->right);
				else
					newTmp = &(p->left);
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, 1);
				addNode(newTmp, k);
				tmp = *newTmp;
				addNil(&(tmp->left));
				addNil(&(tmp->right));
				tmp->left->parent = tmp;
				tmp->right->parent = tmp;
				tmp->parent = p;
				_size++;
				res = &(tmp->value.second);
			}
		}
		return (*res);
	}
	///////////////////////
	/*-----Iterators-----*/
	///////////////////////
	iterator begin(){
		iterator it;
		node *tmp = _parent;
		if (_parent){
			while (!(tmp->left->isNil()))
				tmp = tmp->left;
			it = iterator(tmp);
		}
		return (it);
	}
	iterator end(){
		iterator it;
		node *tmp = _parent;
		if (_parent){
			while (!(tmp->right->isNil())){
				tmp = tmp->right;
			}
			 tmp = tmp->right;
			it = iterator(tmp);
		}
		return (it);
	}
	reverse_iterator rbegin(){
		reverse_iterator it;
		node *tmp = _parent;
		if (_parent){
			while (!(tmp->right->isNil())){
				tmp = tmp->right;
			}
			 tmp = tmp->right;
			it = reverse_iterator(tmp);
		}
		return (it);
	}
	reverse_iterator rend(){
		reverse_iterator it;
		node *tmp = _parent;
		if (_parent){
			while (!(tmp->left->isNil()))
				tmp = tmp->left;
			it = reverse_iterator(tmp);
		}
		return (it);
	}
	///////////////////////
	/*-----Observers-----*/
	///////////////////////
	key_compare key_comp() const {
		return (_cmp);
	}
	value_compare value_comp() const{
		return (_valueCmp);
	}
	///////////////////////
	/*-----Observers-----*/
	///////////////////////
	iterator find (const key_type& k) {
		iterator it(_parent);
		if (_parent == NULL)
			return (it);
		while (it != end()) {
			if (_cmp(it->first, k))
				++it;
			else if (it->first == k)
				break ;
			else
				--it;
		}
		return (it);
	}
	size_type count (const key_type& k) const {
		if (_size){
			node *tmp = _parent;
			while (tmp && !(tmp->isNil())){
				if (_cmp(tmp->value.first, k))
					tmp = tmp->right;
				else if (tmp->value.first == k)
					break ;
				else
					tmp = tmp->left;
			}
			if (tmp && !(tmp->isNil()))
				return 1;
		}
		return 0;
	}
	iterator lower_bound (const key_type& k) {
		iterator it = begin();
		while (it != end() && _cmp(it->first, k))
			++it;
		return (it);
	}
	iterator upper_bound (const key_type& k) {
		iterator it = begin();
		while (it != end() && _cmp(it->first, k))
			++it;
		if (it != end() && it->first == k)
			++it;
		return (it);
	}
	ft::pair<iterator,iterator> equal_range (const key_type& k) {
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}
	///////////////////////
	/*-----Modifiers-----*/
	///////////////////////
	void clear() {
		removeTree(_parent);
		_parent = NULL;
		_size = 0;
	}
	void swap (tree &x) {
		node *tmp = _parent;
		_parent = x._parent;
		x._parent = tmp;
		size_type copySize = _size;
		_size = x._size;
		x._size = copySize;
	}
	size_type erase (const key_type& k) {
		node *tmp = _parent;
		while (tmp && !(tmp->isNil())){
			if (_cmp(tmp->value.first, k))
				tmp = tmp->right;
			else if (tmp->value.first == k)
				break ;
			else
				tmp = tmp->left;
		}
		if (tmp && tmp->isNil())
			return (0);
		if (tmp && tmp->right->isNil() && tmp->left->isNil()) {
			node *p = tmp->parent;
			if (p == NULL) {
				removeTree(tmp);
				_parent = NULL;
				_size  = 0;
			}
			else {
				node **newTmp;
				if (p->left == tmp)
					newTmp = &(p->left);
				else
					newTmp = &(p->right);
				removeTree(tmp);
				addNil(newTmp);
				--_size;
			}
		}
		else if (tmp && (tmp->right->isNil() || tmp->left->isNil())) {
			node *nilNode = tmp->right->isNil() ? tmp->right : tmp->left;
			node *notNilNode = tmp->right->isNil() ? tmp->left : tmp->right;
			node *p = tmp->parent;
			if (p == NULL) {
				removeOneNode(nilNode);
				removeOneNode(tmp);
				notNilNode->parent = NULL;
				_parent = notNilNode;
			}
			else {
				node **newTmp;
				if (p->left == tmp)
					newTmp = &(p->left);
				else
					newTmp = &(p->right);
				removeOneNode(nilNode);
				removeOneNode(tmp);
				notNilNode->parent = p;
				*newTmp = notNilNode;
			}
			--_size;
		}
		else if (tmp){
			node *replacement = tmp->left;
			while (!(replacement->right->isNil()))
				replacement = replacement->right;
			if (replacement->left->isNil()) {
				node *p = tmp->parent;
				node **newTmp;
				if (p)
					newTmp = (p->right == tmp) ? (&(p->right)) : (&(p->left));
				removeOneNode(replacement->left);
				removeOneNode(replacement->right);
				node **newNil = (replacement->parent->left == replacement) ? (&(replacement->parent->left)) : (&(replacement->parent->right));
				addNil(newNil);
				node *left = tmp->left;
				node *right = tmp->right;
				removeOneNode(tmp);
				if (p)
					*newTmp = replacement;
				else {
					replacement->parent = NULL;
					_parent = replacement;
				}
				replacement->parent = p;
				replacement->left = left;
				replacement->right = right;
				replacement->left->parent = replacement;
				replacement->right->parent = replacement;
				--_size;
			}
			else {
				node *p = tmp->parent;
				node **newTmp;
				if (p)
					newTmp = (p->right == tmp) ? (&(p->right)) : (&(p->left));
				removeOneNode(replacement->right);
				node **newNil = (replacement->parent->left == replacement) ? (&(replacement->parent->left)) : (&(replacement->parent->right));
				*newNil = replacement->left;
				replacement->left->parent = replacement->parent;
				node *left = tmp->left;
				node *right = tmp->right;
				removeOneNode(tmp);
				if (p)
					*newTmp = replacement;
				else {
					replacement->parent = NULL;
					_parent = replacement;
				}
				replacement->left = left;
				replacement->right = right;
				replacement->left->parent = replacement;
				replacement->right->parent = replacement;
				--_size;
			}
		}
		return (1);
	}
	void erase (iterator position) {
		if (position != end())
			erase(position->first);
	}
	void erase (iterator first, iterator last) {
		for (iterator it = first++, it2 = first; it != last; it = it2, ++it2)
			erase(it);
	}
	ft::pair<iterator,bool> insert (const value_type& val) {
		node *tmp = _parent;
		while (tmp && !(tmp->isNil())){
			if (_cmp(tmp->value.first, val.first))
				tmp = tmp->right;
			else if (tmp->value.first == val.first)
				break ;
			else
				tmp = tmp->left;
		}
		if (tmp && !(tmp->isNil()))
			return (ft::pair<iterator,bool>(iterator(tmp), false));
		this->operator[](val.first) = val.second;
		tmp = _parent;
		while (tmp && !(tmp->isNil())){
			if (_cmp(tmp->value.first, val.first))
				tmp = tmp->right;
			else if (tmp->value.first == val.first)
				break ;
			else
				tmp = tmp->left;
		}
		return (ft::pair<iterator,bool>(iterator(tmp), true));
	}
	iterator insert (iterator position, const value_type& val) {
		node *tmp = _parent;
		while (tmp && !(tmp->isNil())){
			if (_cmp(tmp->value.first, val.first))
				tmp = tmp->right;
			else if (tmp->value.first == val.first)
				break ;
			else
				tmp = tmp->left;
		}
		if (tmp && tmp->isNil()) {
			this->operator[](val.first) = val.second;
			tmp = _parent;
			while (tmp && !(tmp->isNil())){
				if (_cmp(tmp->value.first, val.first))
					tmp = tmp->right;
				else if (tmp->value.first == val.first)
					break ;
				else
					tmp = tmp->left;
			}
		}
		return (iterator(tmp));
	}
	template <class InputIterator> void insert (InputIterator first, InputIterator last) {
		for (InputIterator it = first; it != last; ++it)
			insert(ft::make_pair(it->first, it->second));
	}
};

}

#endif