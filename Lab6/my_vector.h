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

	MyVector<T>(const MyVector<T>& vector);
	MyVector<T>& operator=(const MyVector<T>& vector);

	MyVector<T>(const MyVector<T>&& vector);
	MyVector<T>& operator=(const MyVector<T>&& vector);

	T& operator[](int index);
	T operator[](int index) const;

	// The function automatically checks whether n is within 
	// the bounds of valid elements in the vector, 
	// throwing an out_of_range exception if it is not (i.e., if n is greater than, or 
	// equal to, its size).This is in contrast with member operator[], 
	// that does not check against bounds.
	T& At(int index);
	const T& At(int index) const;

	//Funzione push_back che aggiunge un elemento alla fine
	void push_back(const T& value);
	
	// Funzione pop_back che rimuove l’ultimo elemento (secondo std non resituisce il valore rimosso
	// servirebbe il metodo back() che ritora il valore)
	void pop_back();

	// If n is greater than the current vector capacity, the function causes the container to reallocate 
	// its storage increasing its capacity to n (or greater).
	// In all other cases, the function call does not cause a reallocationand 
	// the vector capacity is not affected.
	void reserve(int new_size);

	// Getters
	int size() const;

private:
	T* buffer_;
	int buffer_size_;
	int current_size_;

	int static const kDefaultSize = 10;

};

#include "my_vector.hpp"



#endif // MyVector_h

