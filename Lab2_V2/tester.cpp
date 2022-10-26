#include <iostream>
#include "rational.h"

using std::cout;
using std::endl;
using namespace lab2;

int main(void) {
	try {
		Rational r1{};
		Rational r2{ 3 };
		Rational r3{ 4, -5 };
		Rational r4{ 7, 2 };

		cout << "Valori RAZIONALI:" << endl;
		cout << "R1:" << r1 << endl;
		cout << "R2:" << r2 << endl;
		cout << "R3:" << r3 << endl;
		cout << "R4:" << r4 << endl;
		cout << "-------------------------" << endl;

		cout << "SOMME:" << endl;
		Rational r5 = r3 + r4;
		cout << "R3 + R4: " << r5 << endl;
		cout << "R3 + 5: " << r3 + 5 << endl;
		cout << "-------------------------" << endl;

		cout << "DIFFERENZE:" << endl;
		cout << "R3 - R4: " << r3 - r4 << endl;
		cout << "-------------------------" << endl;

		cout << "MOLTIPLICAZIONE:" << endl;
		cout << "R3 x R4: " << r3 * r4 << endl;
		cout << "-------------------------" << endl;

		cout << "DIVISIONE:" << endl;
		cout << "R3 / R4: " << r3 / r4 << endl;
		cout << "-------------------------" << endl;

		cout << "CONFRONTI:" << endl;
		cout << "R3 == R4: " << (r3 == r4) << endl;
		cout << "R3 > R4: " << (r3 > r4) << endl;
		cout << "R3 < R4: " << (r3 < r4) << endl;
		cout << "-------------------------" << endl;

		cout << "DOUBLE CONVERSION:" << endl;
		cout << "R3: " << r3.to_double() << endl;
		cout << "-------------------------" << endl;

	}
	catch (Rational::Invalid) {
		std::cout << "Errore!";
	}
}