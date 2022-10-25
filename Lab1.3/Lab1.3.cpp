#include <iostream>
#include <vector>

using std::vector;
using std::string;

void print(string, const vector<int>&);

int main(void) {
	vector<int> array{ 1,5,2,7,9 };
	print("Array : ", array);
	return 0;
}

void print(string etiquette, const vector<int>& array) {
	std::cout << etiquette;
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i];
		if (i < array.size() - 1) {
			std::cout << ", ";
		}
	}
}

