#include <iostream>

void f(void);
void f_illegal(void);

int main(void) {
	f();
	std::cout << "Finito f()!" << std::endl;
	f_illegal();
	std::cout << "Finito f_illegal()!" << std::endl;
	return 0;
}

void f(void) {
	int constexpr old_array_length = 10;
	int old_array[old_array_length];

	int index = rand() % (old_array_length - 1) + 1;
	int* p = &old_array[index];

	for (int i = 0; i >= -index; i--) {
		p[i] = 5;
	}

	for (int i = 1; i < old_array_length - index; i++) {
		p[i] = 5;
	}
}

void f_illegal(void) {
	int constexpr old_array_length = 10;
	int old_array[old_array_length];

	//Riga che da errore! (Con visual studio non fa compilare)
	//old_array[old_array_length + 7] = 6;
}