#include <iostream>

namespace lab2 {
	class Rational {
	private:
		int numerator_;
		int denominator_;

		static constexpr int kDefaultDenominator = 1;

		int GetCommonDenominator(int, int) const;

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

		int GetNumerator() const { return numerator_; }
		int GetDenominator() const { return denominator_; }
		double to_double() const;
	};

	std::ostream& operator<< (std::ostream&, const Rational&);
}
