#ifndef MyVector_hpp
#define MyVector_hpp

#include "my_vector.h"
#include <initializer_list>

using std::initializer_list;

template <typename T>
MyVector<T>::MyVector(int size) 
	: buffer_size_{ size },
	current_size_ :{ 0 },
	buffer_{ new T[size] } {}

template<typename T>
MyVector<T>::MyVector(initializer_list<T> lst)
	: current_size_{ lst.size() },
	buffer_size_{ lst.size() },
	buffer_{ new T[lst.size()] }
{
	std::copy(lst.begin(), lst.end(), buffer_);
}

template <typename T>
MyVector<T>::~MyVector(){
	delete[] buffer_;
	buffer_size_ = 0;
	current_size_ = 0;
}

template <typename T>
int MyVector<T>::size() const{
	return current_size_;
}
	



#endif // MyVector_hpp