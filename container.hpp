#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace ft{

template<typename T>
class Container{
public:
	typedef T			value_type;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef size_t		size_type;
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
	Container(void) : _size(0), _data(NULL){}
	~Container(void){
		containerData *freeData;
		while (_data){
			freeData = _data;
			_data = _data->next;
			delete freeData;
		}
		_data = NULL;
	}
	Container(const Container& copy){
		this->operator=(copy);
	}
	Container &operator=(const Container& op){
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
	void push_front(const value_type& newValue){
		containerData *oldBegin = _data;
		_data = newElem(newValue);
		_data->next = oldBegin;
		_size++;
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
	void pop_front(void){
		if (!_data)
			return ;
		if (!(_data->next)){
			delete _data;
			_data = NULL;
			return ;
		}
		containerData *newBegin = _data->next;
		delete _data;
		_data = newBegin;
		_size--;
	}
	reference begin(void) const{
		return (_data->value);
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