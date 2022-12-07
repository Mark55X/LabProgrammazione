#ifndef my_vector_hpp
#define my_vector_hpp

#include "my_vector.h"
#include <initializer_list>
#include <algorithm>    
#include <stdexcept>  

using std::initializer_list;
using std::copy;

template <typename T>
MyVector<T>::MyVector(int size) 
	: buffer_size_{ size },
	current_size_ { 0 },
	buffer_{ new T[size] } {}

template<typename T>
MyVector<T>::MyVector(initializer_list<T> lst)
	: current_size_ { static_cast<int>(lst.size()) },
	buffer_size_ { static_cast<int>(lst.size()) },
	buffer_{ new T[ static_cast<int>(lst.size())] }
{
	copy(lst.begin(), lst.end(), buffer_);
}

template <typename T>
MyVector<T>::~MyVector(){
	delete[] buffer_;
	buffer_ = nullptr;
	buffer_size_ = 0;
	current_size_ = 0;
}

template <typename T>
int MyVector<T>::size() const{
	return current_size_;
}
	
template <typename T>
T& MyVector<T>::operator[](int index) {
	return buffer_[index];
}

template <typename T>
T MyVector<T>::operator[](int index) const {
	return buffer_[index];
}

template<typename T>
T& MyVector<T>::At(int index)
{
	if (index < 0 || index >= current_size_)
		throw std::out_of_range();

	return buffer_[index];
}

template<typename T>
const T& MyVector<T>::At(int index) const
{
	if (index < 0 || index >= current_size_)
		throw std::out_of_range();

	return buffer_[index];
}

template<typename T>
void MyVector<T>::push_back(const T& value)
{
	if (current_size_ == buffer_size_) {
		T*
		buffer_size_ = ;
	}
	buffer_[current_size_++] = value;



}

template<typename T>
void MyVector<T>::reserve(int new_size)
{
	if (new_size <= buffer_size_) return;

	T* new_buffer = new T[new_size];
	copy(buffer_, buffer_[current_size_], new_buffer);
	buffer_size_ = new_size;
	buffer_ = new_buffer;
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (current_size_ == 0) return;
	current_size_--;
}



#endif // my_vector_hpp