#include "Rational.h"
#include "Integer.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

namespace cosc326
{
	/*
	 * @brief Default constructor for the Rational class.
	 *        Initializes the object with a numerator of "0", a denominator of "1", and a value of "0/1".
	 */
	Rational::Rational()
		: denominators("1"), numerator("0"), value("0/1")
	{
	}
	/*
	 * @brief Constructor for the Rational class that takes a string as input.
	 *        Initializes the object with a denominator of "1" and sets the value based on the input string.
	 *        If the input string contains a '/', it is treated as a fraction and the numerator and denominator are parsed accordingly.
	 *        If the input string does not contain a '/', it is treated as a whole number and assigned to the numerator.
	 * @param str The input string representing the rational number.
	 */
	Rational::Rational(const string &str)
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
	/*
	 * @brief Copy constructor for the Rational class.
	 *        Initializes the object with the same values as the input Rational object.
	 * @param r The Rational object to be copied.
	 */
	Rational::Rational(const Rational &r)
		: denominators(r.denominators), numerator(r.numerator), value(r.value)
	{
	}
	/*
	 * @brief Constructor for the Rational class that takes an Integer object.
	 *        Initializes the Rational object with the numerator set to the value of the Integer object
	 *        and the denominator set to 1.
	 * @param a The Integer object used as the numerator.
	 */
	Rational::Rational(const Integer &a)
		: denominators("1"), numerator(a), value(a.getValue() + "/1")
	{
	}
	/*
	 * @brief Constructor for the Rational class that takes two Integer objects.
	 *        Initializes the Rational object with the numerator set to the value of the first Integer object (a)
	 *        and the denominator set to the value of the second Integer object (b).
	 * @param a The Integer object used as the numerator.
	 * @param b The Integer object used as the denominator.
	 */
	Rational::Rational(const Integer &a, const Integer &b)
		: denominators(b), numerator(a), value(a.getValue() + "/" + b.getValue())
	{
	}
	/*
	 * @brief Constructor for the Rational class that takes three Integer objects.
	 *        Initializes the Rational object with the numerator set to the result of (a * c) + b
	 *        and the denominator set to the value of the third Integer object (c).
	 * @param a The first Integer object used in the computation.
	 * @param b The second Integer object used in the computation.
	 * @param c The third Integer object used as the denominator.
	 */
	Rational::Rational(const Integer &a, const Integer &b, const Integer &c)
		: denominators(c), numerator((a * c) + b), value(((a * c) + b).getValue() + "/" + c.getValue())
	{
	}
	/*
	 *De-constructor
	 */
	Rational::~Rational()
	{
	}
	/* Returns the rational representation of the Rational number.
	 * @return The rational representation of the Rational number.
	 */
	string Rational::getDecValue() const
	{
		return value;
	}
	/* Sets the rational value of the Rational number.
	 * @param str The tational value to set.
	 */
	void Rational::setDecValue(const string &str)
	{
		value = str;
	}

	/* Overwrites the values of the current Rational object with the values from the right-hand side Rational object.
	 * If the right-hand side is the same as the current object, no action is taken.
	 * @param r The right-hand side Rational object.
	 * @return A reference to the updated Rational object.
	 */
	Rational &Rational::operator=(const Rational &r)
	{
		if (this == &r)
		{
			return *this;
		}

		denominators = r.denominators;
		numerator = r.numerator;
		value = r.value;

		return *this;
	}
	/* Negates the Rational object and returns a new Rational object with the negated value.
	 * @return A new Rational object with the negated value.
	 */
	Rational Rational::operator-() const
	{
		Rational result(*this);
		result.numerator = -result.numerator;
		return result;
	}
	/* Returns a new Rational object with the positive value.
	 * @return A new Rational object with the positive value.
	 */
	Rational Rational::operator+() const
	{
		return *this;
	}
	/* Simplifies the fraction represented by the Rational object.
	 * @param r The Rational object to be simplified.
	 * @return A new Rational object representing the simplified fraction.
	 */
	Rational Rational::simplify(const Rational &r)
	{
		Integer gcdValue = gcd(r.numerator, r.denominators);

		Integer simplifiedNumerator = r.numerator / gcdValue;
		Integer simplifiedDenominator = r.denominators / gcdValue;

		Rational simplifiedRational(simplifiedNumerator, simplifiedDenominator);
		return simplifiedRational;
	}
	/* Adds the value of the right-hand side (rhs) Rational object to the local Rational object.
	 * @param rhs The Rational object to be added.
	 * @return A reference to the modified local Rational object.
	 */
	Rational &Rational::operator+=(const Rational &rhs)
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
	/* Subtracts the value of the right-hand side (r) Rational object from the local Rational object.
	 * @param r The Rational object to be subtracted.
	 * @return A reference to the modified local Rational object.
	 */
	Rational &Rational::operator-=(const Rational &r)
	{
		Integer commonDenominator = lcm(denominators, r.denominators);
		Integer scaledNum1 = numerator * (commonDenominator / denominators);
		Integer scaledNum2 = r.numerator * (commonDenominator / r.denominators);
		numerator = scaledNum1 - scaledNum2;
		denominators = commonDenominator;
		value = numerator.getValue() + "/" + denominators.getValue();
		return *this;
	}
	/* Multiplies the local Rational object by the right-hand side (r) Rational object.
	 * @param r The Rational object to be multiplied.
	 * @return A reference to the modified local Rational object.
	 */
	Rational &Rational::operator*=(const Rational &r)
	{
		numerator *= r.numerator;
		denominators *= r.denominators;
		value = numerator.getValue() + "/" + denominators.getValue();
		return *this;
	}
	/* Divides the local Rational object by the right-hand side (r) Rational object.
	 * @param r The Rational object to divide by.
	 * @return A reference to the modified local Rational object.
	 */
	Rational &Rational::operator/=(const Rational &r)
	{
		numerator *= r.denominators;
		denominators *= r.numerator;
		*this = simplify(*this); // Simplify the result
		return *this;
	}
	/* Adds the left-hand side (lhs) Rational object to the right-hand side (rhs) Rational object and returns the sum.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return The sum of lhs and rhs as a new Rational object.
	 */
	Rational operator+(const Rational &lhs, const Rational &rhs)
	{

		Rational result(lhs); // Create a copy of lhs
		result += rhs;		  // Use the += operator to add rhs to result
		return result;
	}
	/* Subtracts the right-hand side (rhs) Rational object from the left-hand side (lhs) Rational object and returns the difference.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return The difference between lhs and rhs as a new Rational object.
	 */
	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		Rational result(lhs);
		result -= rhs;
		return result;
	}
	/* Multiplies the left-hand side (lhs) Rational object by the right-hand side (rhs) Rational object and returns the product.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return The product of lhs and rhs as a new Rational object.
	 */
	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		// std::cout << "lhs: " << lhs << std::endl;
		// std::cout << "rhs: " << rhs << std::endl;
		Rational result(lhs);
		result *= rhs;
		return result;
	}
	/* Divides the left-hand side (lhs) Rational object by the right-hand side (rhs) Rational object and returns the quotient.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return The quotient of lhs divided by rhs as a new Rational object.
	 */
	Rational operator/(const Rational &lhs, const Rational &rhs)
	{
		Rational result(lhs);
		result /= rhs;
		return result;
	}
	/* Overloads the << operator to output a rational number as a string.
	 * The rational number is represented as either a whole number, a proper fraction,
	 * or a mixed number, depending on its value.
	 * @param os The output stream.
	 * @param rational The Rational object to be output.
	 * @return The modified output stream.
	 */
	std::ostream &operator<<(std::ostream &os, const Rational &rational)
	{
		Integer absNumerator = abs(rational.getNumerator());
		Integer absDenominator = abs(rational.getDenominator());
		Integer wholePart;
		bool isValid = absNumerator.getValue().find('.') == std::string::npos;
		if (!isValid)
		{
			wholePart = absNumerator.getValue().substr(0, absNumerator.getValue().find("."));
			absNumerator = absNumerator.getValue().substr(absNumerator.getValue().find(".") + 1);
		}
		wholePart += absNumerator / absDenominator;
		Integer remainingNumerator = absNumerator % absDenominator;

		if (rational.getNumerator() < Integer("0"))
			os << "-";

		if (wholePart != Integer("0"))
			os << wholePart;

		if (remainingNumerator != Integer("0"))
		{
			if (wholePart != Integer("0"))
				os << ".";
			if (gcd(remainingNumerator, absDenominator) != Integer("1"))
			{
				Integer gcdValue = gcd(remainingNumerator, absDenominator);
				remainingNumerator = remainingNumerator / gcdValue;
				absDenominator = absDenominator / gcdValue;
			}

			os << remainingNumerator << "/" << absDenominator;
		}
		else if (wholePart == Integer("0"))
		{
			// Display zero if the fraction is 0/1
			os << "0";
		}

		return os;
	}

	/* Overloads the >> operator to assign an input string to a Rational object.
	 * The input string represents the rational number in decimal format.
	 * @param is The input stream.
	 * @param r The Rational object to be assigned.
	 * @return The modified input stream.
	 */
	std::istream &operator>>(std::istream &is, Rational &r)
	{
		std::string input;
		is >> input;
		r.setDecValue(input);
		return is;
	}
	/* Overloads the < operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is less than the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is less than rhs, false otherwise.
	 */
	bool operator<(const Rational &lhs, const Rational &rhs)
	{
		// Comparison logic goes here
		return lhs.numerator * rhs.denominators < rhs.numerator * lhs.denominators;
	}
	/* Overloads the > operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is greater than the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is greater than rhs, false otherwise.
	 */
	bool operator>(const Rational &lhs, const Rational &rhs)
	{
		return rhs < lhs;
	}
	/* Overloads the <= operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is less than or equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is less than or equal to rhs, false otherwise.
	 */
	bool operator<=(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs > rhs);
	}
	/* Overloads the >= operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is greater than or equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is greater than or equal to rhs, false otherwise.
	 */
	bool operator>=(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs < rhs);
	}
	/* Overloads the == operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is equal to rhs, false otherwise.
	 */
	bool operator==(const Rational &lhs, const Rational &rhs)
	{
		// Comparison logic goes here
		return lhs.numerator == rhs.numerator && lhs.denominators == rhs.denominators;
	}
	/* Overloads the != operator to compare two Rational objects.
	 * Returns true if the left-hand side (lhs) is not equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Rational object.
	 * @param rhs The right-hand side Rational object.
	 * @return True if lhs is not equal to rhs, false otherwise.
	 */
	bool operator!=(const Rational &lhs, const Rational &rhs)
	{
		return !(lhs == rhs);
	}

}
