#ifndef DEQUE_HPP
#define DEQUE_HPP

namespace ft{

template<typename T, class Allocator = std::allocator<T> >
class deque{
public:
	typedef T			value_type;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef size_t		size_type;

	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
private:
	struct containerData{
		value_type value;
		containerData *next;
	};
	containerData *_data;
	size_type _size;
	containerData *newElem(const value_type& newValue){
		containerData *elem = new containerData;
		elem->value = newValue;
		elem->next = NULL;
		return (elem);
	}
public:
	deque(void) : _data(NULL), _size(0){}
	~deque(void){
		containerData *freeData;
		while (_data){
			freeData = _data;
			_data = _data->next;
			delete freeData;
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
			this->push_back(elem->value);
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
			delete _data;
			_data = NULL;
			return ;
		}
		containerData *i = _data;
		while (i->next->next)
			i = i->next;
		delete i->next;
		i->next = NULL;
		_size--;
	}
	reference end(void) const{
		containerData *i = _data;
		while (i->next)
			i = i->next;
		return (i->value);
	}
	bool isEmpty(void) const{
		return (_data?false:true);
	}
	size_type size(void) const{
		return (_size);
	}
};

}//end namespace ft

#endif