#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace ft{

template<typename T>
struct containerData{
	T value;
	containerData *next;
};

template<typename T>
class Container{
private:
	containerData<T> *_data;
	size_t _size;
	containerData<T> *newElem(const T &newValue){
		containerData<T> *elem = new containerData<T>;
		elem->value = newValue;
		elem->next = NULL;
		return (elem);
	}
public:
	Container(void) : _size(0), _data(NULL){}
	~Container(void){
		containerData<T> *freeData;
		while (_data){
			freeData = _data;
			_data = _data->next;
			delete freeData;
		}
	}
	Container(const Container &copy){
		this->operator=(copy);
	}
	Container &operator=(const Container &op){
		if (this == &op)
			return (*this);
		this->_size = op.size();
		containerData<T> *elem = op._data;
		for (int i = 0; i < (int)this->_size; ++i){
			this->push_back(elem->value);
			elem = elem->next;
		}
		return (*this);
	}
	void push_back(const T &newValue){
		if (!_data)
			_data = newElem(newValue);
		else{
			containerData<T> *i = _data;
			while (i->next)
				i = i->next;
			i->next = newElem(newValue);
		}
		_size++;
	}
	void push_front(const T &newValue){
		containerData<T> *oldBegin = _data;
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
		containerData<T> *i = _data;
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
		containerData<T> *newBegin = _data->next;
		delete _data;
		_data = newBegin;
		_size--;
	}
	T &begin(void) const{
		return (_data->value);
	}
	T &end(void) const{
		containerData<T> *i = _data;
		while (i->next)
			i = i->next;
		return (i->value);
	}
	bool isEmpty(void) const{
		return (_data?false:true);
	}
	size_t size(void) const{
		return (_size);
	}
};

};

#endif