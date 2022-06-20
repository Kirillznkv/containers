# containers

https://en.cppreference.com/w/cpp/container

# Task
Implement the following containers and turn in the necessary <container>.hpp files:
- vector
  
    You don’t have to do the vector<bool> specialization.
- map
- stack
  
    It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.

You also have to implement:
- iterators_traits
- reverse_iterator
- enable_if
  
    Yes, it is C++11 but you will be able to implement it in a C++98 manner.
  
    This is asked so you can discover SFINAE.
- is_integral
- equal and/or lexicographical_compare
- std::pair
- std::make_pair
  
# Installation
  for unit test
  ```
  brew install googletest
  ```
