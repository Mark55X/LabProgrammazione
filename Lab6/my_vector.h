#ifndef MyVector_h
#define MyVector_h
#include <initializer_list>

using std::initializer_list;

template<typename T>
class MyVector{

public:
	explicit MyVector<T>(int size = kDefaultSize);
	MyVector<T>(initializer_list<T> lst);
	~MyVector<T>();

	MyVector<T>(T& vector);
	operator=(T& vector);

	MyVector<T>(T&& vector);
	operator=(T&& vector);

	int size() const;

private:
	T* buffer_;
	int buffer_size_;
	int current_size_;

	int static const kDefaultSize = 10;

};

#include "my_vector.hpp"



#endif // MyVector_h

