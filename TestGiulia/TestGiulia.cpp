#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::vector;
using std::string;

void print(string, vector<int>);

int main(void)
{
    string s = "Vettore";
    vector<int> vect{ 1, 2, 3, 4, 5 };

    print(s, vect);

    return 0;
}

void print(string name, vector<int> v)
{
    cout << name + ": {";

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];

        if (i != v.size() - 1)
            cout << ", ";
    }

    cout << "}\n";

}