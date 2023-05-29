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
		value = "0.0";
	}

	Rational::Rational(const std::string &str)
	{
		value = str;
	}

	Rational::Rational(const Rational &r)
	{
		value = r.getDecValue();
	}

	Rational::Rational(const Integer &a)
	{
		value = a.getValue();
	}

	Rational::Rational(const Integer &a, const Integer &b)
	{
	}

	Rational::Rational(const Integer &a, const Integer &b, const Integer &c)
	{
	}

	Rational::~Rational()
	{
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
		value = r.getDecValue();
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
		cout << r.value << " " << value << endl;
		std::string input = r.value;
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		if (firstInput.compare("-") == 0 && firstLocal.compare("+") == 0)
		{ //+x + -y == x - y
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x -= y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("-") == 0)
		{ //-x + +y =  y - x
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			y -= x;
			value = y.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("+") == 0)
		{ // +x + +y = x + y;
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x += y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("-") == 0 && firstLocal.compare("-") == 0)
		{ // -x + -y = -(x + y)
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x += y;
			value = "-" + x.getDecValue();
		}
		else if (firstInput.compare("-") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x + -y = x - y
			Rational x = Rational(value);
			Rational y = Rational(input.substr(1));
			x -= y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x + +y = x + y
			Rational x = Rational(value);
			Rational y = Rational(input.substr(1));
			x += y;
			value = x.getDecValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("-") == 0)
		{ //-x + y = y - x
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input);
			y -= x;
			value = y.getDecValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("+") == 0)
		{ // + x + y = x + y
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input);
			x += y;
			value = x.getDecValue();
		}
		else
		{
			string input = r.value;
			string local = value;
			string dot = ".";
			Integer Decimal_X;
			Integer Decimal_Y;
			size_t localIndex = local.find(dot);
			size_t inputIndex = input.find(dot);
			cout << localIndex << inputIndex << endl;
			string localWholeNum = local.substr(0, localIndex);
			string inputWholeNum = input.substr(0, inputIndex);
			string localDecimal = local.substr(localIndex + 1);
			string inputDecimal = input.substr(inputIndex + 1);
			Integer localWhole = Integer(localWholeNum);
			Integer inputWhole = Integer(inputWholeNum);
			localWhole += inputWhole;
			int inputDecLen = input.size() - inputIndex;
			int localDecLen = local.size() - localIndex;
			if (inputDecLen > localDecLen)
			{ // inputDecimal > localDecimal fill 0 with localDecimal
				int diff = inputDecLen - localDecLen;
				localDecimal.append(diff, '0');
				Decimal_X = Integer(localDecimal);
				Decimal_Y = Integer(inputDecimal);
				Decimal_X += Decimal_Y;
			}
			else if (inputDecLen < localDecLen)
			{
				int diff = localDecLen - inputDecLen;
				inputDecimal.append(diff, '0');
				Decimal_X = Integer(localDecimal);
				Decimal_Y = Integer(inputDecimal);
				Decimal_X += Decimal_Y;
			}
			else
			{
				Decimal_X = Integer(localDecimal);
				Decimal_Y = Integer(inputDecimal);
				Decimal_X += Decimal_Y;
			}
			string decHolder = Decimal_X.getValue();
			if (decHolder.size() > inputDecLen || decHolder.size() > localDecLen)
			{
				Integer addOne = Integer("1");
				localWhole += addOne;
				decHolder = decHolder.substr(1);
			}
			string result = "";
			string wholeHoler = localWhole.getValue();
			if (decHolder.size() > 0)
				result = wholeHoler + "." + decHolder;
			else
				result = wholeHoler + ".0";

			value = result;
		}
		return *this;
	}

	Rational &Rational::operator-=(const Rational &r)
	{
		std::string input = r.value;
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		if (firstInput.compare("-") == 0 && firstLocal.compare("+") == 0)
		{ //+x - -y == x + y
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x += y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("-") == 0)
		{ //-x - +y =  -(x +y)
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x += y;
			value = "+" + x.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("+") == 0)
		{ // +x - +y = x - y;
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x -= y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("-") == 0 && firstLocal.compare("-") == 0)
		{ // -x - -y = -(x + y)
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input.substr(1));
			x += y;
			-x;
			value = x.getDecValue();
		}
		else if (firstInput.compare("-") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x - -y = x + y
			Rational x = Rational(value);
			Rational y = Rational(input.substr(1));
			x += y;
			value = x.getDecValue();
		}
		else if (firstInput.compare("+") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x - +y = x + y
			Rational x = Rational(value);
			Rational y = Rational(input.substr(1));
			x -= y;
			value = x.getDecValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("-") == 0)
		{ //-x + y = y - x
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input);
			y -= x;
			value = y.getDecValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("+") == 0)
		{ // + x + y = x + y
			Rational x = Rational(value.substr(1));
			Rational y = Rational(input);
			x += y;
			value = x.getDecValue();
		}
		else
		{
			string local = value;
			string input = r.getDecValue();
			string dot = ".";
			string localWhole = local.substr(0, local.find(dot));
			string inputWhole = input.substr(0, input.find(dot));
			string localDec = local.substr(local.find(dot) + 1);
			string inputDec = input.substr(input.find(dot) + 1);
			if (localDec.size() < inputDec.size())
			{
				int diff = localDec.size() - inputDec.size();
				inputDec.append(diff, '0');
			}
			if (localDec.size() > inputDec.size())
			{
				int diff = localDec.size() - inputDec.size();
				inputDec.append(diff, '0');
			}
			Integer Dec1 = Integer(localDec);
			Integer Dec2 = Integer(inputDec);
			Dec1 -= Dec2; // Decimal number subtractions
			+Dec1;		  // force the number still be the positive number.
			Integer whole1 = Integer(localWhole);
			Integer whole2 = Integer(inputWhole);
			whole1 -= whole2;

			value = whole1.getValue() + "." + Dec1.getValue();
		}
		return *this;
	}

	Rational &Rational::operator*=(const Rational &r)
	{
		std::string input = r.value;
		char inputSign = input[0];
		char localSign = value[0];
		if (localSign == '-' && (inputSign != '+' && inputSign != '-'))
		{

			std::string x = value.substr(1);
			Rational X = Rational(x);
			X *= r;
			value = "-" + X.getDecValue();
		}
		else if (inputSign == '-' && (localSign != '-' && localSign != '+'))
		{

			std::string y = input.substr(1);
			Rational X = Rational(value);
			Rational Y = Rational(y);
			X *= Y;
			value = "-" + X.getDecValue();
		}
		else if (inputSign == '-' && localSign == '-')
		{

			std::string x = value.substr(1);
			std::string y = input.substr(1);
			Rational X = Rational(x);
			Rational Y = Rational(y);
			X *= Y;
			value = X.getDecValue();
		}
		else if ((inputSign == '-' || inputSign == '+') && (localSign == '-' || localSign == '+'))
		{

			if (inputSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Rational X = Rational(x);
				Rational Y = Rational(y);
				X *= Y;
				value = "-" + X.getDecValue();
			}
			else if (localSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Rational X = Rational(x);
				Rational Y = Rational(y);
				X *= Y;
				value = "-" + X.getDecValue();
			}
		}
		else
		{
			string local = value;
			string input = r.getDecValue();
			string dot = ".";
			size_t localDecLen = local.find(dot);
			size_t inputDecLen = input.find(dot);
			int decLen1 = local.size() - localDecLen - 1;
			int decLen2 = input.size() - inputDecLen - 1;

			int totalDecLen = decLen1 + decLen2;
			local.erase(localDecLen, localDecLen);
			input.erase(inputDecLen, inputDecLen);

			Integer num1 = Integer(local);
			Integer num2 = Integer(input);
			num1 *= num2;
			string holder = num1.getValue();
			int dotSign = holder.size() - totalDecLen;
			holder.insert(dotSign, ".");
			value = holder;
		}
		return *this;
	}

	Rational &Rational::operator/=(const Rational &r)
	{
		return *this;
	}

	Rational operator+(const Rational &lhs, const Rational &rhs)
	{
		Rational result = lhs; // Make a copy of lhs
		cout << result << endl;
		result += rhs; // Add rhs to the copy
		return result; // Return the result
	}

	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		return lhs;
	}

	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		return lhs;
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
