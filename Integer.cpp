#include "Integer.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
namespace cosc326
{
	/*default Constructor*/
	Integer::Integer()
	{
		// cout << "here" << endl;
		value = "0";
	}
	/*passing int convert to String*/
	Integer::Integer(const Integer &i)
	{
		value = i.value;
	}
	/*1st class citizen */
	Integer::Integer(const std::string &s)
	{
		value = s;
		// std::cout << value << std::endl;
	}

	Integer::~Integer()
	{
	}
	// getter method
	std::string Integer ::getValue() const
	{
		return value;
	}
	// setter method
	void Integer ::setValue(std::string &s)
	{
		value = s;
	}
	/*
	 *@desc: return absolute value of input
	 *@param a: value needs to be return its abs
	 */
	/* Return absolute value of input */
	Integer abs(const Integer &a)
	{
		std::string str = a.getValue();
		if (str[0] == '-' || str[0] == '+')
		{
			str = str.substr(1);
		}
		return Integer(str);
	}

	/*@Desc: overwrite local value by incoming value Integer i
	 *@param i : incoming Integer
	 *@return : local Integer value
	 */
	Integer &Integer::operator=(const Integer &i)
	{
		value = i.getValue();
		return *this;
	}
	/*@Desc: assign negative sign in the number if the number is negative already make it positive
	 */
	Integer Integer::operator-()
	{
		if (value[0] == '-')
			value.erase(0, 1);
		else if (value[0] == '+')
			value[0] = '-';
		else
			value.insert(0, 1, '-');

		// Return modified Integer object
		return *this;
	}

	/*@Desc: increase local value by 1
	 *@return: local value +1;
	 */
	Integer Integer::operator+()
	{
		if (value[0] == '-')
			value.erase(0, 1);
		return *this;
	}
	/*@desc: accumulate local value by input i
	 *@param:
	 */
	Integer &Integer::operator+=(const Integer &i)
	{
		std::string input = i.value;
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		if (firstInput.compare("-") == 0 && firstLocal.compare("+") == 0)
		{ //+x + -y == x - y
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x -= y;
			value = x.getValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("-") == 0)
		{ //-x + +y =  y - x
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			y -= x;
			value = y.getValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("+") == 0)
		{ // +x + +y = x + y;
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if (firstInput.compare("-") == 0 && firstLocal.compare("-") == 0)
		{ // -x + -y = -(x + y)
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = "-" + x.getValue();
		}
		else if (firstInput.compare("-") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x + -y = x - y
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x -= y;
			value = x.getValue();
		}
		else if (firstInput.compare("+") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x + +y = x + y
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("-") == 0)
		{ //-x + y = y - x
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input);
			y -= x;
			value = y.getValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("+") == 0)
		{ // + x + y = x + y
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input);
			x += y;
			value = x.getValue();
		}
		else
		{
			// Handle non-sign input
			int inputLen = input.length();
			int localLen = value.length();
			int min = std::min(inputLen, localLen);
			int max = std::max(inputLen, localLen);

			if (inputLen > localLen)
			{
				swap(input, value);
			}
			std::string sum = "";
			int digitDiff = max - min;
			int carry = 0;
			int intSum;
			for (int i = min - 1; i >= 0; i--)
			{
				intSum = (input[i] - '0') + (value[i + digitDiff] - '0') + carry;
				sum.push_back(intSum % 10 + '0');
				carry = intSum / 10;
			}
			for (int i = digitDiff - 1; i >= 0; i--)
			{
				intSum = (value[i] - '0') + carry;
				sum.push_back(intSum % 10 + '0');
				carry = intSum / 10;
			}
			if (carry)
			{
				sum.push_back(carry + '0');
			}
			reverse(sum.begin(), sum.end());
			value = sum;
		}
		return *this;
	}

	Integer &Integer::operator-=(const Integer &i)
	{
		std::string input = i.getValue();
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		bool negative = false;

		if (firstInput == "-" && firstLocal != "-")
		{ // +x - -y == x + y
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if (firstInput == "+" && firstLocal == "-")
		{ //-x - +y =  - (x+y)
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = "-" + x.getValue();
		}
		else if (firstInput == "+" && firstLocal == "+")
		{ // +x - +y = x - y;
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			cout << "cou2312t " << endl;
			x -= y;
			value = x.getValue();
		}
		else if (firstInput == "-" && firstLocal == "-")
		{ // -x - -y =  - x + y
			cout << "cout111 " << endl;
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = "-" + x.getValue();
		}
		else if (firstInput == "-")
		{ // x - -y ==  x + y
			cout << "cout " << endl;
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if (firstLocal == "-")
		{ // -x - y = -1(x + y)
			Integer x = Integer(value.substr(1));

			x += i;
			value = "-" + x.getValue();
		}
		else if (firstInput == "+")
		{
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x -= y;
			value = x.getValue();
		}
		else if (firstLocal == "+")
		{
			Integer x = Integer(value.substr(1));
			x -= i;
			value = x.getValue();
		}
		else
		{
			Integer local = Integer(value);
			Integer Input = Integer(input);
			if (value == input)
			{
				value = '0';
				return *this;
			}
			if (local < Input)
			{ // ensure local value is alway bigger than input during calculation
				// cout << local << " NONONONONO " << Input << endl;
				swap(value, input);
				negative = true;
			}
			std::string result = "";
			int inputLen = input.size(), localLen = value.size(); // lenght of input/local
			int carry = 0;
			reverse(value.begin(), value.end());
			reverse(input.begin(), input.end());

			for (int i = 0; i < inputLen; i++)
			{ // loop thro input
				int sub = ((value[i] - '0') - (input[i] - '0') - carry);
				if (sub < 0)
				{
					sub = sub + 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				result.push_back(sub + '0');
			}
			for (int i = inputLen; i < localLen; i++)
			{
				int sub = (value[i] - '0') - carry;
				if (sub < 0)
				{
					sub = sub + 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				result.push_back(sub + '0');
			}

			result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end()); // just in case there is unwanted space
			reverse(result.begin(), result.end());
			value = result;
			while (value[0] == '0' || value[0] == ' ')
			{
				value = value.substr(1);
			}

			if (negative)
			{
				value = "-" + value;
			}
		}
		return *this;
	}

	/*mutiple local value by input i*/
	Integer &Integer::operator*=(const Integer &i)
	{
		std::string input = i.value;
		char inputSign = input[0];
		char localSign = value[0];
		if (localSign == '-' && (inputSign != '+' && inputSign != '-'))
		{

			std::string x = value.substr(1);
			Integer X = Integer(x);
			X *= i;
			value = "-" + X.getValue();
		}
		else if (inputSign == '-' && (localSign != '-' && localSign != '+'))
		{

			std::string y = input.substr(1);
			Integer X = Integer(value);
			Integer Y = Integer(y);
			X *= Y;
			value = "-" + X.getValue();
		}
		else if (inputSign == '-' && localSign == '-')
		{

			std::string x = value.substr(1);
			std::string y = input.substr(1);
			Integer X = Integer(x);
			Integer Y = Integer(y);
			X *= Y;
			value = X.getValue();
		}
		else if ((inputSign == '-' || inputSign == '+') && (localSign == '-' || localSign == '+'))
		{

			if (inputSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X *= Y;
				value = "-" + X.getValue();
			}
			else if (localSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X *= Y;
				value = "-" + X.getValue();
			}
			else
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X *= Y;
				value = X.getValue();
			}
		}
		else
		{
			int inputLen = input.length() - 1;
			int localLen = value.length() - 1;
			int max = std::max(inputLen, localLen);
			int min = std::min(inputLen, localLen);
			if (inputLen > localLen)
			{
				std::string temp = value;
				value = input;
				input = temp;
			}
			std::string holder((max + 1) + (min + 1), 0);
			for (std::string::size_type i = static_cast<std::string::size_type>(max); i != static_cast<std::string::size_type>(-1); --i)
			{
				for (std::string::size_type j = static_cast<std::string::size_type>(min); j != static_cast<std::string::size_type>(-1); --j)
				{
					int n = (value[i] - '0') * (input[j] - '0') + holder[i + j + 1];
					holder[i + j + 1] = n % 10;
					holder[i + j] += n / 10;
				}
			}

			for (std::string::size_type i = 0; i < holder.size(); ++i)
			{
				holder[i] += '0';
			}
			if (holder[0] == '0')
			{
				holder = holder.substr(1);
			}
			value = holder;
		}

		return *this;
	}

	/*divide local value by input i
	 * currently it can only have the whole number part;
	 */
	Integer &Integer::operator/=(const Integer &i)
	{
		Integer f = Integer(value);
		if (f == i)
		{
			cout << "here" << value << endl;
			value = "1";
			cout << value << endl;
			return *this;
		}
		Integer p = abs(f);
		Integer l = abs(i);
		if (l > p)
		{
			value = "0";
		}
		else if (i.value == "0")
		{
			value = "0";
		}
		else
		{
			std::string input = i.value;
			char inputSign = input[0];
			char localSign = value[0];

			if (localSign == '-' && (inputSign != '+' && inputSign != '-'))
			{
				std::string x = value.substr(1);
				Integer X = Integer(x);
				X /= i;
				value = "-" + X.getValue();
			}
			else if (inputSign == '-' && (localSign != '-' && localSign != '+'))
			{
				std::string y = input.substr(1);
				Integer X = Integer(value);
				Integer Y = Integer(y);
				X /= Y;
				value = "-" + X.getValue();
			}
			else if (inputSign == '-' && localSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X /= Y;
				value = X.getValue();
			}
			else if ((inputSign == '-' || inputSign == '+') && (localSign == '-' || localSign == '+'))
			{
				if (inputSign == '-')
				{
					std::string x = value.substr(1);
					std::string y = input.substr(1);
					Integer X = Integer(x);
					Integer Y = Integer(y);
					X /= Y;
					value = "-" + X.getValue();
				}
				else if (localSign == '-')
				{
					std::string x = value.substr(1);
					std::string y = input.substr(1);
					Integer X = Integer(x);
					Integer Y = Integer(y);
					X /= Y;
					value = "-" + X.getValue();
				}
				else
				{
					std::string x = value.substr(1);
					std::string y = input.substr(1);
					Integer X = Integer(x);
					Integer Y = Integer(y);
					X /= Y;
					value = X.getValue();
				}
			}
			else
			{
				int index = 0;
				Integer zero = Integer("0");
				Integer remainder;
				Integer dividend = Integer(value);
				Integer divider = Integer(i.value);
				while (dividend >= divider)
				{
					dividend -= divider;
					index++;
				}
				// cout << dividend << endl;
				// cout << index << endl;
				value = std::to_string(index);
			}
		}
		return *this;
	}
	/*remain local value by input i */
	Integer &Integer::operator%=(const Integer &i)
	{
		Integer f = Integer(value);

		if (f == i)
		{
			value = "0";
			return *this;
		}

		std::string input = i.value;
		char inputSign = input[0];
		char localSign = value[0];

		if (localSign == '-' && (inputSign != '+' && inputSign != '-'))
		{
			std::string x = value.substr(1);
			Integer X = Integer(x);
			X %= i;
			value = "-" + X.getValue();
		}
		else if (inputSign == '-' && (localSign != '-' && localSign != '+'))
		{
			std::string y = input.substr(1);
			Integer X = Integer(value);
			Integer Y = Integer(y);
			X %= Y;
			value = "-" + X.getValue();
		}
		else if (inputSign == '-' && localSign == '-')
		{
			std::string x = value.substr(1);
			std::string y = input.substr(1);
			Integer X = Integer(x);
			Integer Y = Integer(y);
			X %= Y;
			value = "-" + X.getValue();
		}
		else if ((inputSign == '-' || inputSign == '+') && (localSign == '-' || localSign == '+'))
		{
			if (inputSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X %= Y;
				value = "-" + X.getValue();
			}
			else if (localSign == '-')
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X %= Y;
				value = "-" + X.getValue();
			}
			else
			{
				std::string x = value.substr(1);
				std::string y = input.substr(1);
				Integer X = Integer(x);
				Integer Y = Integer(y);
				X %= Y;
				value = X.getValue();
			}
		}
		else
		{
			// a/b = r
			// r *b >= a
			//  r = {0 ......a}
			// shortest way to find r will be quickest solution
			int index = 0;
			Integer zero = Integer("0");
			Integer remainder;
			Integer dividend = Integer(value);
			Integer divider = Integer(i.value);
			while (dividend >= divider)
			{
				dividend -= divider;
				index++;
			}

			value = dividend.getValue();
		}

		return *this;
	}

	/*return sum ot lhs and rhs return it as a Integer*/
	Integer operator+(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result += rhs;
		return result;
	}

	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result -= rhs;
		return result;
	}

	Integer operator*(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result *= rhs;
		return result;
	}

	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result /= rhs;
		return result;
	}

	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		Integer Result = Integer(lhs);
		Result %= rhs;
		return Result;
	}
	// system out
	std::ostream &operator<<(std::ostream &os, const Integer &i)
	{
		os << i.getValue();
		return os;
	}
	// system in, pass input to the local
	std::istream &operator>>(std::istream &is, Integer &i)
	{
		std::string input;
		is >> input;
		i.setValue(input);
		return is;
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		std::string smaller = lhs.getValue();
		std::string bigger = rhs.getValue();

		// Remove the sign symbol (+/-) for comparison
		if (smaller[0] == '+')
			smaller = smaller.substr(1);
		if (bigger[0] == '+')
			bigger = bigger.substr(1);

		// Check if either number is negative
		bool isSmallerNegative = (lhs.getValue()[0] == '-');
		bool isBiggerNegative = (rhs.getValue()[0] == '-');

		// Handle the case where one number is negative and the other is positive
		if (isSmallerNegative && !isBiggerNegative)
			return false;
		if (!isSmallerNegative && isBiggerNegative)
			return true;

		// Handle the case where both numbers are negative
		if (isSmallerNegative && isBiggerNegative)
		{
			// If the number of digits is different, the one with more digits is smaller
			if (smaller.size() < bigger.size())
				return true;
			if (smaller.size() > bigger.size())
				return false;

			// If the number of digits is the same, compare digit by digit in reverse order
			for (int i = smaller.size() - 1; i >= 1; i--)
			{
				if (smaller[i] < bigger[i])
					return true;
				if (smaller[i] > bigger[i])
					return false;
			}

			// The numbers are equal
			return false;
		}

		// Handle the case where both numbers are positive
		if (smaller.size() > bigger.size())
			return true;
		if (smaller.size() < bigger.size())
			return false;

		// If the number of digits is the same, compare digit by digit in forward order
		for (size_t i = 0; i < smaller.size(); i++)
		{
			if (smaller[i] > bigger[i])
				return true;
			if (smaller[i] < bigger[i])
				return false;
		}

		// The numbers are equal
		return false;
	}

	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		return rhs > lhs;
	}

	bool operator<=(const Integer &lhs, const Integer &rhs)
	{
		string str1 = lhs.getValue();
		string str2 = rhs.getValue();

		// Remove the sign symbol (+/-) for comparison
		if (str1[0] == '+')
			str1 = str1.substr(1);
		if (str2[0] == '+')
			str2 = str2.substr(1);

		// Check if either number is negative
		bool isStr1Negative = (lhs.getValue()[0] == '-');
		bool isStr2Negative = (rhs.getValue()[0] == '-');

		// Handle the case where one number is negative and the other is positive
		if (isStr1Negative && !isStr2Negative)
			return true;
		if (!isStr1Negative && isStr2Negative)
			return false;

		// Handle the case where both numbers are negative
		if (isStr1Negative && isStr2Negative)
		{
			// If the number of digits is different, the one with more digits is smaller
			if (str1.size() < str2.size())
				return true;
			if (str1.size() > str2.size())
				return false;

			// If the number of digits is the same, compare digit by digit in reverse order
			for (int i = str1.size() - 1; i >= 0; i--)
			{
				if (str1[i] < str2[i])
					return true;
				if (str1[i] > str2[i])
					return false;
			}

			// The numbers are equal
			return true;
		}

		// Handle the case where both numbers are positive
		if (str1.size() < str2.size())
			return true;
		if (str1.size() > str2.size())
			return false;

		// If the number of digits is the same, compare digit by digit in forward order
		for (size_t i = 0; i < str1.size(); i++)
		{
			if (str1[i] < str2[i])
				return true;
			if (str1[i] > str2[i])
				return false;
		}

		// The numbers are equal
		return true;
	}

	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs || lhs > rhs)
			return true;
		else
			return false;
	}

	bool operator==(const Integer &lhs, const Integer &rhs)
	{
		string str1 = lhs.getValue();
		string str2 = rhs.getValue();

		// Remove the sign symbol (+/-) for comparison
		if (str1[0] == '+')
			str1 = str1.substr(1);
		if (str2[0] == '+')
			str2 = str2.substr(1);

		int str1Len = str1.size();
		int str2Len = str2.size();

		if (str1Len == str2Len)
		{
			int index = 0;
			while (index < str1Len)
			{
				if (str1[index] == str2[index])
					index++;
				else
					return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}
	Integer gcd(const Integer &a, const Integer &b)
	{
		Integer n1 = abs(a);
		Integer n2 = abs(b);
		if (a.getValue() == "0")
			return n2;
		if (b.getValue() == "0")
			return n1;
		Integer zero = Integer("0");
		while (n2 != zero)
		{
			Integer temp = n2;
			n2 = n1 % n2;
			n1 = temp;
			// cout << n1 << " " << n2 << " " << temp << endl;
		}
		return n1;
	}
}
