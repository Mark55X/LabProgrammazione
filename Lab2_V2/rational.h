
namespace stefani_number {
	class Rational {
	private:
		int numerator_;
		int denominator_;

		static constexpr int kDefaultDenominator = 1;

	public:
		class Invalid {};

		Rational();
		Rational(int);
		Rational(int, int);

		Rational& operator= (const Rational&);
				
		int GetNumerator() const { return numerator_; }
		int GetDenominator() const { return denominator_; }
		double to_double() const;
	};

	Rational operator+ (const Rational&, const Rational&);
	Rational operator+ (int, const Rational&);

	Rational operator- (const Rational&, const Rational&);
	Rational operator* (const Rational&, const Rational&);
	Rational operator/ (const Rational&, const Rational&);

	bool operator== (const Rational&, const Rational&);
	bool operator> (const Rational&, const Rational&);
	bool operator< (const Rational&, const Rational&);

	std::ostream& operator<< (std::ostream&, const Rational&);

}
