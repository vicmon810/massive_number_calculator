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

	Rational::Rational()
	{
		value = "0";
	}

	Rational::Rational(const std::string &str)
	{
		value = str;
	}

	Rational::Rational(const Rational &r)
	{
		value = r.value;
	}

	Rational::Rational(const Integer &a)
	{ // whole number
		value = a.getValue();
	}

	Rational::Rational(const Integer &a, const Integer &b) // 35/40 = 7/8 ; 4/2 = 2
	{													   // numerator == a; denominators == b
		numerator = a;
		denominators = b;
		if (a == b)
			value = "1";

		value = a.getValue() + "/" + b.getValue();
	}

	Rational::Rational(const Integer &a, const Integer &b, const Integer &c)
	{
		wholeNum = a;
		numerator = b;
		denominators = c;
		value = a.getValue() + "." + b.getValue() + "/" + c.getValue();
	}

	Rational::~Rational()
	{
	}

	Rational Rational::simply(const Rational &a)
	{

		Integer divider = gcd(a.numerator, a.denominators);
		Integer new__numerator = a.numerator / divider;
		Integer new__denominator = a.denominators / divider;
		Rational result = Rational(new__numerator, new__denominator);
		// cout << result << endl;
		return result;
	}

	// Getter method
	std::string Rational::getDecValue() const
	{
		return value;
	}
	// Setter method
	void Rational::setDecValue(const std::string &str)
	{
		value = str;
	}

	Rational &Rational::operator=(const Rational &r)
	{
		denominators = r.denominators;
		numerator = r.numerator;
		value = r.value;
		return *this;
	}

	Rational Rational::operator-() const
	{
	}

	Rational Rational::operator+() const
	{
	}
	/*
	 *@desc : using Integer operator to help me. spearer whole number and decimal number  and fill with 0 to calculate decimal number
	 */
	Rational &Rational::operator+=(const Rational &r)
	{
		if (denominators != r.denominators)
		{
			Rational simply_input = Rational(simply(r));
			cout << simply_input << endl;
			Integer new_demominators;
		}

		return *this;
	}

	Rational &Rational::operator-=(const Rational &r)
	{
	}

	Rational &Rational::operator*=(const Rational &r)
	{

		return *this;
	}

	Rational &Rational::operator/=(const Rational &r)
	{
		return *this;
	}

	Rational operator+(const Rational &lhs, const Rational &rhs)
	{
		Rational result = lhs; // Make a copy of lhs

		result += rhs; // Add rhs to the copy
		return result; // Return the result
	}

	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		Rational result = lhs;
		result -= rhs;
		return result;
	}

	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		Rational result = lhs;
		result *= rhs;
		return result;
	}

	Rational operator/(const Rational &lhs, const Rational &rhs)
	{
		return lhs;
	}

	std::ostream &operator<<(std::ostream &os, const Rational &i)
	{
		os << i.getDecValue();
		return os;
	}
	std::istream &operator>>(std::istream &is, Rational &i)
	{
		std::string input;
		is >> input;
		i.setDecValue(input);
		return is;
	}

	bool operator<(const Rational &lhs, const Rational &rhs)
	{
		if (lhs == rhs)
			return false;
		string smaller = lhs.getDecValue();
		string bigger = rhs.getDecValue();
		if (smaller[0] == '+')
			smaller = smaller.substr(1);
		if (bigger[0] == '+')
			bigger = bigger.substr(1);

		if (smaller[0] == '-' && bigger[0] != '-')
		{
			return true;
		}

		if (smaller[0] != '-' && bigger[0] == '-')
		{
			return false;
		}
		string dot = ".";
		size_t smallDot = smaller.find(dot);
		size_t bigDot = bigger.find(dot);
		if (smallDot < bigDot)
			return true;

		if (smallDot > bigDot)
			return false;

		if (smallDot == bigDot)
		{
			int smallDec = smaller.size() - smallDot;
			int bigDec = bigger.size() - bigDot;
			if (smallDec > bigDec)
				return true;
			if (smallDec < bigDec)
				return false;
			if (smallDec == bigDec)
			{
				int index = 0;
				while (index < smaller.size())
				{
					if (smaller[index] < bigger[index])
						return true;
					index++;
				}
			}
		}
		return false;
	}

	bool operator>(const Rational &lhs, const Rational &rhs)
	{ // reverse < operator

		if (lhs < rhs || lhs == rhs)
			return false;
		else
			return true;
	}

	bool operator<=(const Rational &lhs, const Rational &rhs)
	{
		if (lhs == rhs || lhs < rhs)
			return true;
		else
			return false;
	}

	bool operator>=(const Rational &lhs, const Rational &rhs)
	{
		if (lhs == rhs || lhs > rhs)
			return true;
		else
			return false;
	}

	bool operator==(const Rational &lhs, const Rational &rhs)
	{
		string str1 = lhs.getDecValue();
		string str2 = rhs.getDecValue();
		if (str1[0] == '+')
			str1 = str1.substr(1);
		if (str2[0] == '+')
			str2 = str2.substr(1);
		int str1Len = str1.size(), str2Len = str2.size();
		if (str1[0] == str2[0] && str1Len == str2Len)
		{
			int index = 0;
			while (index < str1Len)
			{
				if (str1[index] == str2[index])
					index++;
				else
					return false;
			}
			if (index == str1Len)
				return true;
		}
		else
		{
			return false;
		}
		return true;
	}

	bool operator!=(const Rational &lhs, const Rational &rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}
}
