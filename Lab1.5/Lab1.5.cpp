#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;

void print(string, const vector<int>&);
int getMaxFibonacciValue(void);

int main(void)
{
	cout << "Numero piu' grande (Approssimato fibonacci): " << getMaxFibonacciValue() << "\n";
	return 0;
}

void print(string etiquetteStr, const vector<int>& array)
{
	cout << etiquetteStr << " {";
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i < array.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}\n";
}

int getMaxFibonacciValue()
{
	int a = 1;
	int b = 2;
	a = a + b;
	while (a > 0) {
		int temp = a;
		a = a + b;
		b = temp;
	}

	return b;
}
