#include <iostream>
#include <string>
#include <math.h>
#include "rational.h"	

using std::cout;
using std::endl;

//Metodo non accessibile esternamente perchè non definito in Rational.h, usato solo internamente
int GetCommonDenominator(int, int);

namespace stefani_number {

	Rational::Rational()
		: numerator_{ 0 }, denominator_{ kDefaultDenominator } {}

	Rational::Rational(int numerator)
		: numerator_{ numerator }, denominator_{ kDefaultDenominator } {}

	Rational::Rational(int numerator, int denominator)
		: numerator_{ numerator }, denominator_{ denominator } {

		if (denominator == 0) throw Invalid{};

	}

	double Rational::to_double() const {
		return this->numerator_ / static_cast<double>(this->denominator_);
	}

	Rational& Rational::operator= (const Rational& rational) {
		this->numerator_ = rational.numerator_;
		this->denominator_ = rational.denominator_;
		return *this;
	}

	Rational operator+ (const Rational& first_rational, const Rational& second_rational) {

		int first_denominator = first_rational.GetDenominator();
		int second_denominator = second_rational.GetDenominator();
		int common_denominator = GetCommonDenominator(first_denominator, second_denominator);

		int numerator_sum = (common_denominator / second_denominator) * second_rational.GetNumerator()
							+ (common_denominator / first_denominator) * first_rational.GetNumerator();

		return Rational{ numerator_sum, common_denominator };
	}

	Rational operator+ (int value, const Rational& rational) {
		int common_denominator = rational.GetDenominator();
		int numerator_sum = rational.GetNumerator() + common_denominator * value;
		return *new Rational{ numerator_sum, common_denominator };
	}

	Rational operator- (const Rational& first_rational, const Rational& second_rational) {
		int first_denominator = first_rational.GetDenominator();
		int second_denominator = second_rational.GetDenominator();
		int common_denominator = GetCommonDenominator(first_denominator, second_denominator);

		int numerator_difference = (common_denominator / first_denominator) * first_rational.GetNumerator()
			- (common_denominator / second_denominator) * second_rational.GetNumerator();

		return Rational{ numerator_difference, common_denominator };
	}

	Rational operator* (const Rational& first_rational, const Rational& second_rational) {

		return Rational{ first_rational.GetNumerator() * second_rational.GetNumerator(),
								first_rational.GetDenominator() * second_rational.GetDenominator() };
	}

	Rational operator/ (const Rational& first_rational, const Rational& second_rational) {

		return Rational{ first_rational.GetNumerator() * second_rational.GetDenominator(),
								first_rational.GetDenominator() * second_rational.GetNumerator()};
	}

	bool operator== (const Rational& first_rational, const Rational& second_rational) {
		return first_rational.GetNumerator() == second_rational.GetNumerator() &&
			   first_rational.GetDenominator() == second_rational.GetDenominator();
	}

	bool operator> (const Rational& first_rational, const Rational& second_rational) {
		int first_denominator = first_rational.GetDenominator();
		int second_denominator = second_rational.GetDenominator();
		int common_denominator = GetCommonDenominator(first_denominator, second_denominator);

		return (common_denominator / first_rational.GetDenominator()) * first_rational.GetNumerator()
				> (common_denominator / second_rational.GetDenominator()) * second_rational.GetNumerator();
	}

	bool operator< (const Rational& first_rational, const Rational& second_rational) {
		int first_denominator = first_rational.GetDenominator();
		int second_denominator = second_rational.GetDenominator();
		int common_denominator = GetCommonDenominator(first_denominator, second_denominator);

		return (common_denominator / first_rational.GetDenominator()) * first_rational.GetNumerator()
			< (common_denominator / second_rational.GetDenominator()) * second_rational.GetNumerator();
	}


	std::ostream& operator<< (std::ostream& os, const Rational& rational) {
		int numerator = rational.GetNumerator();
		int denominator = rational.GetDenominator();

		if (numerator < 0 && denominator < 0) {
			numerator = std::abs(numerator);
			denominator = std::abs(denominator);
		}
		return os << numerator << "/" << denominator;
	}
}


int GetCommonDenominator(int first_denominator, int second_denominator) {
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
*  THIS il prof non lo vuole
*  Gli operator vanno in member 
* 
*  REFERENCE NON OBBLIGATORIA  L'oggetto e' piccolo
*  Importante restituire un Rational  (o reference di Rational) per
*  a = b = c
*	 
*  Rendere operator<< FRIEND FUNCTION? Anche no, ma potevo farlo
* 
*  Usare helper function per gli operator: in questo modo funziona int + rational 
*  (non era possibile prima perche con i member il primo addendo è per forza rational)
* 
*/