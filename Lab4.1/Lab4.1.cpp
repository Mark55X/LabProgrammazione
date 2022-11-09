#include <iostream>
#include <string>

using std::string;
bool IsPalindrome(const string&);
bool IsPalindrome(const char[], int);

int main(void)
{
    std::cout << "Test 1 Palidromo" << std::endl;
    std::cout << "anna: " << IsPalindrome("anna") << std::endl;
    std::cout << "aeiea: " << IsPalindrome("aeiea") << std::endl;
    std::cout << "beppe: " << IsPalindrome("beppe") << std::endl;

    std::cout << "Test 2 Palidromo" << std::endl;
    std::cout << "anna: " << IsPalindrome(new char[] {'a','n','n','a'}, 4) << std::endl;
    std::cout << "aeiea: " << IsPalindrome(new char[] {'a', 'e', 'i', 'e', 'a'}, 5) << std::endl;
    std::cout << "beppe: " << IsPalindrome(new char[] {'b', 'e', 'p', 'p', 'e'}, 5) << std::endl;


    return 0;
}

bool IsPalindrome(const string& str) { //Algoritmo di scrittura semplice, comprensibile MA non performante: O(n) , n lunghezza stringa

    string compare_str = "";
    for (char character : str) { //Ciclo FOR EACH 
        compare_str = character + compare_str;
    }

    return compare_str == str; //Overloading di "==" in string
}

bool IsPalindrome(const char str[], int length)  {
    // Ci sono più modalità di implementazione di questo algoritmo:
    // 1. Dall'array di char mi costruisco un oggetto string e poi lo passo a IsPalindrome(const string& str) 
    //    MA visto che queste funzioni dovrebbero stare in progetti diversi, staccati tra loro, non viene utilizzata
    //    tale procedura
    // 2. Quella che viene rappresentata qua (simile a come poteva essere rappresentato il precedente, più performante)
    // 3. Enjoy 

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - (i+1)])
            return false;
    }

    return true;
}



