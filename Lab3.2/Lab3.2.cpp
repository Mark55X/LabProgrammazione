#include <iostream>

using std::cout;
using std::endl;

void print_array_length(double[]);

int main(void)
{
	int constexpr kMyArrayLength = 50;
	double my_array[kMyArrayLength] {1,2,3,4,5};
	cout << "Dimensione array di double : " << sizeof(my_array)/sizeof(double) << endl;

	print_array_length(my_array);

	return 0;
}

void print_array_length(double array[]) { 
	cout << "print_array_length : Dimensione array di double : " << sizeof(array) / sizeof(double) << endl;

	//Per il Decadimento dell'array, abbiamo solo il puntatore al primo elemento
	//Perdiamo l'informazione della lunghezza, quindi non è possibile usare sizeof
	
	//si può accedere ai dati dell'array, senza però capire quando termina
	cout << "print_array_length : Accedere ai primi due elementi : " << array[0] << ", " <<  array[1] << endl;
}

