#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Rational {
private:
	int numerator_;
	int denominator_;

	static constexpr int kDefaultDenominator = 1;

	int GetCommonDenominator(int, int);

public:
	class Invalid {};

	Rational();
	Rational(int);
	Rational(int, int);

	Rational& operator= (const Rational&);
	Rational& operator+ (const Rational&);
	Rational& operator+ (int);

	Rational& operator- (const Rational&);
	Rational& operator* (const Rational&);
	Rational& operator/ (const Rational&);
	bool operator== (const Rational&);
	bool operator> (const Rational&);
	bool operator< (const Rational&);

	int GetNumerator() const   { return numerator_; } 
	int GetDenominator() const { return denominator_; }
	double to_double() const;
};

Rational::Rational() 
	: numerator_{ 0 }, denominator_{ kDefaultDenominator } {}

Rational::Rational(int numerator)
	: numerator_{ numerator }, denominator_{ kDefaultDenominator } {}

Rational::Rational(int numerator, int denominator)
	: numerator_{ numerator }, denominator_{ denominator } {

	if (denominator == 0) throw Invalid{};
}

Rational& Rational::operator= (const Rational &rational) {
	this->numerator_ = rational.numerator_;
	this->denominator_ = rational.denominator_;
	return *this;
}

Rational& Rational::operator+ (const Rational& rational) {

	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);
	
	int numerator_sum =   (common_denominator / rational.denominator_) * rational.numerator_
						+ (common_denominator / this->denominator_) * this->numerator_;

	return *new Rational{ numerator_sum, common_denominator };
}

Rational& Rational::operator+ (int value) {
	int common_denominator = this->denominator_;
	int numerator_sum = this->numerator_ + common_denominator * value;
	return *new Rational{ numerator_sum, common_denominator };
}

Rational& Rational::operator- (const Rational& rational) {
	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);

	int numerator_difference = (common_denominator / rational.denominator_) * rational.numerator_
		- (common_denominator / this->denominator_) * this->numerator_;

	return *new Rational{ numerator_difference, common_denominator };
}

Rational& Rational::operator* (const Rational& rational) {

	return *new Rational{ this->numerator_ * rational.numerator_, 
						  this->denominator_ * rational.denominator_ };
}

Rational& Rational::operator/ (const Rational& rational) {

	return *new Rational{ this->numerator_ * rational.denominator_,
						  this->denominator_ * rational.numerator_ };
}

bool Rational::operator== (const Rational& rational) {
	return this->numerator_ == rational.numerator_ && this->denominator_ == rational.denominator_;
}

bool Rational::operator> (const Rational& rational) {
	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);
	return (common_denominator / this->denominator_) * this->numerator_ 
		   >  (common_denominator / rational.denominator_) * rational.numerator_;
}

bool Rational::operator< (const Rational& rational) {
	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);
	return (common_denominator / this->denominator_) * this->numerator_
			< (common_denominator / rational.denominator_) * rational.numerator_;
}

double Rational::to_double() const {
	return this->numerator_ / static_cast<double>(this->denominator_);
}

std::ostream& operator<< (std::ostream& os, const Rational& rational) {
	return os << rational.GetNumerator() << "/" << rational.GetDenominator();
}


// Trova il denominatore comune più stringente
int Rational::GetCommonDenominator(int first_denominator, int second_denominator) {
	if (first_denominator > second_denominator) {
		if (first_denominator % second_denominator == 0) {
			return first_denominator;
		}
	}
	else if (second_denominator % first_denominator == 0) {
		return second_denominator;
	}

	return first_denominator * second_denominator;
}


int main(void) {
	try {
		Rational r1{}; 
		Rational r2{3};
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

/*
* Domande che mi sono venute in mente:
* 1 - 'Corretta' sintassi delle variabili e membri (https://en.cppreference.com/w/cpp/language/operators)
*	In particolare su "underscore" delle variabili e le costanti con K
* 
* 2 - this ecessivo o piu corretto per la lettura??
* 3- Nell interfaccia della classe si mettono le variabili i nomi dei paramewtri?
* 4 - GetCommonDenominator devo mettere const come funzione?? Tanto i valori vengono copiati non devo verranno modificati
* 5- Codice in REGIONI!
* 6- rendere operator<< FRIEND FUNCTION?
* 7- Int + rational IMPOSSIBILE ?? 
* 8- Member function vs helper function? IO ho fatto con tutte member function
*/