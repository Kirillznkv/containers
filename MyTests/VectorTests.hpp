#ifndef VECTORTESTS_HPP
#define VECTORTESTS_HPP

# include <iostream>

template <typename T>
void outSizes(const T& v1){
	std::cout<<"size:\t\t"<<v1.size()<<std::endl;
	std::cout<<"capacity:\t"<<v1.capacity()<<std::endl;
	std::cout<<"max_size:\t"<<v1.max_size()<<std::endl;
}
template <typename T>
void boolTest(T v1, T v2){
	std::cout	<<(int)(v1 == v2)<<" " \
				<<(int)(v1 != v2)<<" " \
				<<(int)(v1 <= v2)<<" " \
				<<(int)(v1 >= v2)<<" " \
				<<(int)(v1 < v2)<<" " \
				<<(int)(v1 > v2)<<std::endl;
}

#endif