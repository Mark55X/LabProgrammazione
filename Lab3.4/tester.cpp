#include <iostream>
#include "my_vector.h"

using namespace stefani_containers;

int main()
{
	try {
		MyVector my_vector(10);
		my_vector[0] = 5;
		std::cout << "Primo elemento: " << my_vector[0] << std::endl;
		my_vector[5] = 6;
		std::cout << "Sesto elemento: " << my_vector[5] << std::endl;

		std::cout << "Sesto elemento: " << my_vector.safe_get(5) << std::endl;
		my_vector.safe_set(5, 7);
		std::cout << "Sesto elemento: " << my_vector.safe_get(5) << std::endl;

	}
	catch (MyVector::Invalid exception) {
		std::cout << exception.GetMessage();
	}
	


}

