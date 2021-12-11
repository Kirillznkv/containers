#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <memory>

namespace ft{

template<typename T, class Allocator = std::allocator<T> >
class deque{
public:
	typedef T			value_type;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef size_t		size_type;

	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference_alloc;
	typedef typename allocator_type::const_reference	const_reference_alloc;
	typedef typename allocator_type::size_type			size_type_alloc;
	typedef typename allocator_type::difference_type	difference_type_alloc;
	typedef typename allocator_type::pointer			pointer_alloc;
	typedef typename allocator_type::const_pointer		const_pointer_alloc;
private:
	struct containerData{
		value_type *value;
		containerData *next;
	};
	containerData *_data;
	size_type _size;
	std::allocator<containerData > _allocatorNode;
	allocator_type _allocatorData;

	containerData *newElem(const value_type& newValue){
		containerData *elem = _allocatorNode.allocate(1);
		elem->value = _allocatorData.allocate(1);
		_allocatorData.construct(elem->value, newValue);
		value_type a = newValue;
		a = (value_type)a;
		elem->next = NULL;
		return (elem);
	}
public:
	deque(void) : _data(NULL), _size(0){}
	~deque(void){
		containerData *freeNode;
		while (_data){
			freeNode = _data;
			_data = _data->next;
			_allocatorData.destroy(freeNode->value);
			_allocatorData.deallocate(freeNode->value, 1);
			_allocatorNode.deallocate(freeNode, 1);
		}
		_data = NULL;
	}
	deque(const deque& copy){
		this->operator=(copy);
	}
	deque &operator=(const deque& op){
		if (this == &op)
			return (*this);
		this->_size = 0;
		const containerData *elem = op._data;
		for (size_type i = 0; i < op.size(); ++i){
			this->push_back(*(elem->value));
			elem = elem->next;
		}
		return (*this);
	}
	void push_back(const value_type& newValue){
		if (!_data)
			_data = newElem(newValue);
		else{
			containerData *i = _data;
			while (i->next)
				i = i->next;
			i->next = newElem(newValue);
		}
		this->_size++;
	}
	void pop_back(void){
		if (!_data)
			return ;
		if (!(_data->next)){
			_allocatorData.destroy(_data->value);
			_allocatorData.deallocate(_data->value, 1);
			_allocatorNode.deallocate(_data, 1);
			_data = NULL;
			return ;
		}
		containerData *i = _data;
		while (i->next->next)
			i = i->next;
		_allocatorData.destroy(i->next->value);
		_allocatorData.deallocate(i->next->value, 1);
		_allocatorNode.deallocate(i->next, 1);
		i->next = NULL;
		_size--;
	}
	reference back(void) const{
		containerData *i = _data;
		while (i->next)
			i = i->next;
		return (*(i->value));
	}
	bool isEmpty(void) const{
		return (_data?false:true);
	}
	size_type size(void) const{
		return (_size);
	}
	/*----relational-operators----*/
	bool	operator==(const deque& rVal){
		if (this->size() != rVal.size())
			return (false);
		containerData *i = _data;
		containerData *j = rVal._data;
		while (i && j){
			if (*(i->value) != *(j->value))
				return (false);
			i = i->next;
			j = j->next;
		}
		return (true);
	}
	bool	operator!=(const deque& rVal){
		return (!operator==(rVal));
	}
	bool	operator<(const deque& rVal){
		containerData *i = _data;
		containerData *j = rVal._data;
		while (i && j && *(i->value) == *(j->value)){
			i = i->next;
			j = j->next;
		}
		if (!j)
			return (false);
		else if (!i)
			return (true);
		return (*(i->value) < *(j->value));
	}
	bool	operator>(const deque& rVal){
		containerData *i = _data;
		containerData *j = rVal._data;
		while (i && j && *(i->value) == *(j->value)){
			i = i->next;
			j = j->next;
		}
		if (!i)
			return (false);
		else if (!j)
			return (true);
		return (*(i->value) > *(j->value));
	}
	bool	operator>=(const deque& rVal){
		return (!operator<(rVal));
	}
	bool	operator<=(const deque& rVal){
		return (!operator>(rVal));
	}
};

}//end namespace ft

#endif