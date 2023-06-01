#include "Rational.h"
#include "Integer.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

namespace cosc326 {

	Rational::Rational()
    : denominators("1"), numerator("0"), value("0/1")
	{
	}

	Rational::Rational(const string& str)
	: denominators("1"), value(str)
	{
		// Find the position of the '/' character
		size_t slashPos = str.find('/');
		if (slashPos != string::npos)
		{
			// Extract the numerator and denominator substrings
			string numeratorStr = str.substr(0, slashPos);
			string denominatorStr = str.substr(slashPos + 1);

			// Assign the parsed values to numerator and denominators
			numerator = Integer(numeratorStr);
			denominators = Integer(denominatorStr);
		}
		else
		{
			// If no '/' character found, assume the input is a whole number
			numerator = Integer(str);
		}
	}


	Rational::Rational(const Rational& r)
		: denominators(r.denominators), numerator(r.numerator), value(r.value)
	{
	}

	Rational::Rational(const Integer& a)
		: denominators("1"), numerator(a), value(a.getValue() + "/1")
	{
	}

	Rational::Rational(const Integer& a, const Integer& b)
		: denominators(b), numerator(a), value(a.getValue() + "/" + b.getValue())
	{
	}

	Rational::Rational(const Integer& a, const Integer& b, const Integer& c)
		: denominators(c), numerator((a * c) + b), value(((a * c) + b).getValue() + "/" + c.getValue())
	{
	}

	Rational::~Rational()
	{
	}

	string Rational::getDecValue() const
	{
		return value;
	}

	void Rational::setDecValue(const string& str)
	{
		value = str;
	}

	Rational& Rational::operator=(const Rational& r)
	{
		if (this == &r) {
			return *this;
		}

		denominators = r.denominators;
		numerator = r.numerator;
		value = r.value;

		return *this;
	}

	Rational Rational::operator-() const
	{
		Rational result(*this);
		result.numerator = -result.numerator;
		return result;
	}

	Rational Rational::operator+() const
	{
		return *this;
	}

	Rational Rational::simplify(const Rational& r)
	{
		Integer gcdValue = gcd(r.numerator, r.denominators);

		Integer simplifiedNumerator = r.numerator / gcdValue;
		Integer simplifiedDenominator = r.denominators / gcdValue;

		Rational simplifiedRational(simplifiedNumerator, simplifiedDenominator);
		return simplifiedRational;
	}

	Rational& Rational::operator+=(const Rational& rhs)
	{

		if (denominators == rhs.denominators)
		{
			numerator += rhs.numerator;
		}
		else
		{
			Integer commonDenominator = lcm(denominators, rhs.denominators);
			Integer scaledNum1 = numerator * (commonDenominator / denominators);
			Integer scaledNum2 = rhs.numerator * (commonDenominator / rhs.denominators);
			numerator = scaledNum1 + scaledNum2;
			denominators = commonDenominator;
		}

		value = numerator.getValue() + "/" + denominators.getValue();
		return *this;
	}




	Rational& Rational::operator-=(const Rational& r)
	{
		Integer commonDenominator = lcm(denominators, r.denominators);
		Integer scaledNum1 = numerator * (commonDenominator / denominators);
		Integer scaledNum2 = r.numerator * (commonDenominator / r.denominators);
		numerator = scaledNum1 - scaledNum2;
		denominators = commonDenominator;
		value = numerator.getValue() + "/" + denominators.getValue();
		return *this;
	}

	Rational& Rational::operator*=(const Rational& r)
	{
		std::cout << "numerator: " << numerator << std::endl;
    	std::cout << "denominator: " << denominators << std::endl;
		std::cout << "numerator: " << r.numerator << std::endl;
    	std::cout << "denominator: " << r.denominators << std::endl;
		numerator *= r.numerator;
		denominators *= r.denominators;
		value = numerator.getValue() + "/" + denominators.getValue();
		std::cout << "numerator post: " << numerator << std::endl;
    	std::cout << "denominator post: " << denominators << std::endl;
		std::cout << "Result: " << *this << std::endl;
		return *this;
	}

	Rational& Rational::operator/=(const Rational& r)
	{
		numerator *= r.denominators;
		denominators *= r.numerator;
		*this = simplify(*this); // Simplify the result
		return *this;
	}

	bool operator<(const Rational& lhs, const Rational& rhs)
	{
		// Comparison logic goes here
		return lhs.numerator * rhs.denominators < rhs.numerator * lhs.denominators;
	}

	Rational operator+(const Rational& lhs, const Rational& rhs)
	{
		

		Rational result(lhs);  // Create a copy of lhs
		result += rhs;  // Use the += operator to add rhs to result
		return result;
	}


	Rational operator-(const Rational& lhs, const Rational& rhs)
	{
		Rational result(lhs);
		result -= rhs;
		return result;
	}

	Rational operator*(const Rational& lhs, const Rational& rhs)
	{
		std::cout << "lhs: " << lhs << std::endl;
    	std::cout << "rhs: " << rhs << std::endl;
		Rational result(lhs);
		result *= rhs;
		return result;
	}

	Rational operator/(const Rational& lhs, const Rational& rhs)
	{
		Rational result(lhs);
		result /= rhs;
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const Rational& r)
	{
		os << r.getDecValue();
		return os;
	}

	std::istream& operator>>(std::istream& is, Rational& r)
	{
		std::string input;
		is >> input;
		r.setDecValue(input);
		return is;
	}



	bool operator>(const Rational& lhs, const Rational& rhs)
	{
		return rhs < lhs;
	}

	bool operator<=(const Rational& lhs, const Rational& rhs)
	{
		return !(lhs > rhs);
	}

	bool operator>=(const Rational& lhs, const Rational& rhs)
	{
		return !(lhs < rhs);
	}

	bool operator==(const Rational& lhs, const Rational& rhs)
	{
		// Comparison logic goes here
		return lhs.numerator == rhs.numerator && lhs.denominators == rhs.denominators;
	}

	bool operator!=(const Rational& lhs, const Rational& rhs)
	{
		return !(lhs == rhs);
	}

}
