#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace ft {

class Vector;
class Stack;
class Map;

template<typename T>
class Container {
private:
	friend Vector;
	friend Stack;
	friend Map;
private:
	T *array;
	unsigned int size;
public:
	Container(void);
	~Container(void);
	Container(const Container &copy);
	Container &operator=(const Container &op);
	void push_back(T &va)
};

};

#endif