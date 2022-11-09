#include <iostream>
#include <string>

using std::string;
bool IsPalindrome(const string&);
bool IsPalindrome(const char[], int);
bool IsPalindrome(const char*, const char*);

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

    std::cout << "Test 3 Palidromo" << std::endl;
    string str1 = "anna";
    string str2 = "aeiea";
    string str3 = "beppe";

    std::cout << "anna: " << IsPalindrome(&str1[0], &str1[str1.length() - 1]) << std::endl;
    std::cout << "aeiea: " << IsPalindrome(&str2[0], &str2[str2.length() - 1]) << std::endl;
    std::cout << "beppe: " << IsPalindrome(&str3[0], &str3[str3.length() - 1]) << std::endl;

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

bool IsPalindrome(const char* first, const char* last) {
    if(first == nullptr || last == nullptr){ //RICORDA: gestire sempre i valori possibili a null all'inizio delle funzioni: 
        return false;                        //Metodologia di sviluppo by Marco
    }


    
    return false;
}


