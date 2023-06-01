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
	{ // default all figure is ZERO
		denominators = Integer();
		numerator = Integer();
		wholeNum = Integer();
		value = "0";
	}

	Rational::Rational(const std::string &str)
	{ // string contain whole number denominators and numerator
		// will ignore all sign for neow
		int dot = str.find(".");
		int slash = str.find("/");
		if (dot == -1 && slash == -1)
		{
			wholeNum = Integer(str);
		}
		else if (dot == -1)
		{
			numerator = Integer(str.substr(0, slash));
			denominators = Integer(str.substr(slash + 1));
		}
		else
		{
			wholeNum = Integer(str.substr(0, dot));
			numerator = Integer(str.substr(dot + 1, slash - dot - 1));
			denominators = Integer(str.substr(slash + 1));
		}
		value = str;
	}

	Rational::Rational(const Rational &r)
	{
		wholeNum = r.wholeNum;
		denominators = r.denominators;
		numerator = r.numerator;
		value = r.value;
	}

	Rational::Rational(const Integer &a)
	{ // whole number
		wholeNum = a;
		value = a.getValue();
	}

	Rational::Rational(const Integer &a, const Integer &b) // 35/40 = 7/8 ; 4/2 = 2
	{													   // numerator == a; denominators == b
		numerator = a;
		denominators = b;
		if (a == b)
			value = "1";

		if (b == Integer("1"))
		{
			wholeNum = numerator;
			numerator = Integer();
			denominators = Integer();
			value = a.getValue();
		}

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
		if (a.denominators.getValue() == "0")
		{ // failed statement
			Rational res = Rational();
			return res;
		}
		else
		{
			Integer divider = gcd(a.numerator, a.denominators);
			Integer new__numerator = a.numerator / divider;
			Integer new__denominator = a.denominators / divider;
			Rational result = Rational(new__numerator, new__denominator);
			return result;
		}
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
		// Case : Local = A
		if (wholeNum != Integer("0") && denominators == Integer("0"))
		{
			// case : r = A
			if (r.wholeNum != Integer("0") && r.denominators == Integer("0"))
			{
				cout << "{}" << endl;
				wholeNum += r.wholeNum;
				value = wholeNum.getValue();
			}
			// Case : r = a/b
			else if (r.wholeNum == Integer("0") && r.denominators != Integer("0"))
			{
				cout << "ds" << endl;
				Rational simpled = simply(r);
				wholeNum += simpled.wholeNum;
				numerator += simpled.numerator;
				denominators += simpled.denominators;
				if (numerator > denominators)
				{
					Integer new_numer = numerator % denominators;
					Integer temp_whole = numerator / denominators;
					wholeNum += temp_whole;
					numerator = new_numer;
				}
				value = wholeNum.getValue() + "." + numerator.getValue() + "/" + denominators.getValue();
			}
			// Case :: r = A.a/b
			else if (r.wholeNum != Integer("0") && r.denominators != Integer("0"))
			{
				cout << "A.a/b" << endl;
				wholeNum += r.wholeNum;
				cout << wholeNum << endl;
				Rational simpled = simply(r);
				wholeNum += simpled.wholeNum;
				numerator += simpled.numerator;
				denominators += simpled.denominators;
				if (numerator > denominators)
				{
					Integer new_numer = numerator % denominators;
					Integer temp_whole = numerator / denominators;
					wholeNum += temp_whole;
					numerator = new_numer;
				}
				value = wholeNum.getValue() + "." + numerator.getValue() + "/" + denominators.getValue();
			}
		}
		// Case : local = a/b
		else if (wholeNum == Integer("0") && denominators != Integer("0"))
		{
			// local copy
			Rational copy = simply(Rational(numerator, denominators));
			cout << copy << endl;
			cout << "CCC " << (r.denominators == Integer("0")) << endl;
			// case : r = A
			if (r.wholeNum != Integer("0") && r.denominators == Integer("0"))
			{
				copy.wholeNum += r.wholeNum;
				if (copy.numerator > copy.denominators)
				{
					copy.wholeNum += (copy.numerator / copy.denominators);
					copy.numerator = copy.numerator % copy.denominators;
				}
				if (copy.denominators != Integer("0"))
					value = copy.wholeNum.getValue() + "." + copy.numerator.getValue() + "/" + copy.denominators.getValue();
				else
					value = copy.wholeNum.getValue();
			}
			// case : r = a/b
			else if (r.wholeNum == Integer("0") && r.denominators != Integer("0"))
			{ // a/b + c/d = ad/bd + cb/bd = ad + cb /bd
				cout << copy << "d + cb /bd " << endl;
				Rational copyR = simply(Rational(r));
				Integer newDem = copy.denominators * copyR.denominators;
				Integer newNume = copy.numerator * copyR.denominators;
				Integer newNumeR = copyR.numerator * copy.denominators;
				// cout << newNumeR << " " << newNume << endl;
				copy.numerator = newNume + newNumeR;

				Rational result = simply(Rational(copy.numerator, newDem));
				if (result.numerator > result.denominators)
				{
					result.wholeNum = result.numerator / result.denominators;
					result.numerator = result.numerator % result.denominators;
				}
				value = result.wholeNum.getValue() + "." + result.numerator.getValue() + "/" + result.denominators.getValue();
			}
			// case : r = A.a/b
			else if (r.wholeNum != Integer("0") && r.denominators != Integer("0"))
			{
				Rational result;
				result.wholeNum += wholeNum;
				result.wholeNum += r.wholeNum;
				Rational copyR = simply(r);
			}
		}
		// case : Local = A.a/b
		else if (wholeNum != Integer("0") && denominators != Integer("0"))
		{
			cout << "PPP" << endl;
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
