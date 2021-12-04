#ifndef VECTORTESTS_HPP
#define VECTORTESTS_HPP

# include <iostream>
# include <fstream>

template <typename T>
void outSizes(const T& v1, std::ofstream & out){
	out<<"size:\t\t"<<v1.size()<<std::endl;
	out<<"capacity:\t"<<v1.capacity()<<std::endl;
	out<<"max_size:\t"<<v1.max_size()<<std::endl;
}
template <typename T>
void boolTest(T v1, T v2, std::ofstream & out){
	out			<<(int)(v1 == v2)<<" " \
				<<(int)(v1 != v2)<<" " \
				<<(int)(v1 <= v2)<<" " \
				<<(int)(v1 >= v2)<<" " \
				<<(int)(v1 < v2)<<" " \
				<<(int)(v1 > v2)<<std::endl;
}

static std::ofstream fStdStack("allResult/stdStack.txt");
static std::ofstream fStdVector("allResult/stdVector.txt");

#endif