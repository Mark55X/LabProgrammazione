#include "my_vector.h"
#include <string>

using std::string;
namespace stefani_containers {
	MyVector::MyVector(int size)
		: size_{ size }
	{
		if (size < 0) throw Invalid("Size must be positive");
		elements_ = new double[size] {};
	}

	MyVector::~MyVector()
	{
		delete[] elements_;
		elements_ = nullptr;
	}

	MyVector::Invalid::Invalid(string message)
		: message_{ message } {}

	string MyVector::Invalid::GetMessage(void) {
		return message_;
	}

	double& MyVector::operator[](int index)
	{
		check_elements();
		return elements_[index];
	}

	double MyVector::operator[](int index) const
	{
		check_elements();
		return elements_[index];
	}

	void MyVector::safe_set(int index, double element)
	{
		check_elements();
		if (index < 0 || index >= size_) {
			throw Invalid("Index Out of Bounds");
		}
		elements_[index] = element;
	}

	double MyVector::safe_get(int index) const
	{
		check_elements();
		if (index < 0 || index >= size_) {
			throw Invalid("Index Out of Bounds");
		}

		return elements_[index];
	}

	void MyVector::check_elements() const {
		if (elements_ == nullptr) {
			throw Invalid("MyVector è stato già eliminato, impossibile accere a un suo elemento");
		}
	}
}

