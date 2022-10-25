#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;

void print(string,const vector<int>&);
void fibonacci(int, int, vector<int>&, int);

int main(void)
{
	vector<int> fibArray;
	fibonacci(1, 2, fibArray, 10);
	print("Fibonacci:", fibArray);

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

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);

	for (int i = 1; i < n - 1;i++) {
		v.push_back(v[i - 1] + v[i]);
	}
}


