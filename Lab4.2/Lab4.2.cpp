#include <iostream>
#include <string>

using std::string;
bool IsPalindrome(const char[], int);

int main(void)
{
    std::cout << "Test 2 Palidromo" << std::endl;
    std::cout << "anna: " << IsPalindrome(new char[] {'a', 'n', 'n', 'a'}) << std::endl;
    std::cout << "beppe: " << IsPalindrome("beppe") << std::endl;

    return 0;
}

bool IsPalindrome(const char str[], int length) {

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - (i + 1)])
            return false;
    }

    return true;
}
