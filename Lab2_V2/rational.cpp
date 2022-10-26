#include <iostream>
#include <string>
#include <math.h>
#include "rational.h"	

using std::cout;
using std::endl;

using namespace lab2;

Rational::Rational()
	: numerator_{ 0 }, denominator_{ kDefaultDenominator } {}

Rational::Rational(int numerator)
	: numerator_{ numerator }, denominator_{ kDefaultDenominator } {}

Rational::Rational(int numerator, int denominator)
	: numerator_{ numerator }, denominator_{ denominator } {

	if (denominator == 0) throw Invalid{};

}

Rational& Rational::operator= (const Rational& rational) {
	this->numerator_ = rational.numerator_;
	this->denominator_ = rational.denominator_;
	return *this;
}

Rational& Rational::operator+ (const Rational& rational) {

	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);

	int numerator_sum = (common_denominator / rational.denominator_) * rational.numerator_
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

	int numerator_difference = (common_denominator / this->denominator_) * this->numerator_
		- (common_denominator / rational.denominator_) * rational.numerator_;

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
		> (common_denominator / rational.denominator_) * rational.numerator_;
}

bool Rational::operator< (const Rational& rational) {
	int common_denominator = GetCommonDenominator(this->denominator_, rational.denominator_);
	return (common_denominator / this->denominator_) * this->numerator_
		< (common_denominator / rational.denominator_)* rational.numerator_;
}

double Rational::to_double() const {
	return this->numerator_ / static_cast<double>(this->denominator_);
}

std::ostream& lab2::operator<< (std::ostream& os, const Rational& rational) {
	int numerator = rational.GetNumerator();
	int denominator = rational.GetDenominator();

	if (numerator < 0 && denominator < 0) {
		numerator = std::abs(numerator);
		denominator = std::abs(denominator);
	}
	return os << numerator << "/" << denominator;
}


// Trova il denominatore comune più stringente
int Rational::GetCommonDenominator(int first_denominator, int second_denominator) const {
	if (first_denominator > second_denominator) {
		if (first_denominator % second_denominator == 0) {
			return first_denominator;
		}
	}
	else if (second_denominator % first_denominator == 0) {
		return second_denominator;
	}

	return std::abs(first_denominator * second_denominator);
}



/*
* Domande che mi sono venute in mente:
* 1 - 'Corretta' sintassi delle variabili e membri (https://google.github.io/styleguide/cppguide.html#Naming)
*	In particolare su "underscore" delle variabili e le costanti con K
*
* 2 - this ecessivo o piu corretto per la lettura??
* 3 - Nell interfaccia della classe si mettono le variabili i nomi dei paramewtri?
* 5 - Codice in REGIONI! #pragma region MyRegion
* 6  - rendere operator<< FRIEND FUNCTION?
* 7 - Int + rational IMPOSSIBILE ??
* 8 - Member function vs helper function? IO ho fatto con tutte member function
*/