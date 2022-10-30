#include <iostream>

void print_reference(const int&, const double&);
void print_pointer(const int*, const double*);

int main()
{
	int first_variable = 5;
	double second_variable = 1.2;

	print_reference(first_variable, second_variable);
	print_pointer(&first_variable, &second_variable);

}

void print_reference(const int& a, const double& b) {
	std::cout << "STAMPA PER REFERENCE " << std::endl;

	std::cout << "Variabile intera: " << a << std::endl;
	std::cout << "Variabile double: " << b << std::endl;
}

void print_pointer(const int* a, const double* b) {
	std::cout << "STAMPA PER POINTER " << std::endl;

	std::cout << "Variabile intera: " << *a << std::endl;
	std::cout << "Variabile double: " << *b << std::endl;
}