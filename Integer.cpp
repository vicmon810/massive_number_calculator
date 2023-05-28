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
	Integer abs(const Integer &a)
	{
		std::string str = a.getValue();
		char ch = str[0];
		if (ch == '-' || ch == '+')
		{
			str = str.substr(1);
		}
		Integer result = Integer(str);
		return result;
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
	/*@Desc: decrease local value by 1
	 *@return: local value -1;
	 */
	Integer Integer::operator-() const
	{
		Integer p = Integer("1");
		Integer c = Integer(value);
		c -= p;
		std::string result = c.getValue();
		return Integer(result);
	}

	/*@Desc: increase local value by 1
	 *@return: local value +1;
	 */
	Integer Integer::operator+() const
	{
		Integer p = Integer("1");
		Integer c = Integer(value);
		c += p;
		std::string result = c.getValue();
		return Integer(result);
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
			Integer x = Integer(value.substr(1));
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

			x -= y;
			value = x.getValue();
		}
		else if (firstInput == "-" && firstLocal == "-")
		{ // -x - -y = y - x
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			y -= x;
			value = y.getValue();
		}
		else
		{
			Integer i = Integer(value);
			Integer c = Integer(input);

			if (c > i)
			{ // ensure local value is alway bigger than input during calculation
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

			if (value[0] == '0' || value[0] == ' ')
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
		Integer p = Integer(value);
		Integer l = Integer(i.value);
		if (l > p)
		{
			value = "0";
		}
		if (i.value == "0")
		{
			value = "0";
		}
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
			std::string result;
			int divider = std::stoll(i.value);
			std::string::size_type index = 0;
			int dividend = value[index] - '0';
			while (dividend >= divider)
			{
				dividend = dividend * 10 + (value[++index] - '0');
			}
			while (index < value.size())
			{
				result += (dividend / divider) + '0';
				dividend = (dividend % divider) * 10 + value[++index] - '0';
			}
			if (result.empty())
			{
				result = "0";
			}
			while (!result.empty() && result[0] == '0')
			{
				result = result.substr(1);
			}
			value = result;
		}
		return *this;
	}

	/*remain local value by input i */
	Integer &Integer::operator%=(const Integer &i)
	{
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
			Integer A = Integer(value);
			if (i > A)
			{
				return *this;
			}
			if (i.value == "0")
			{
				value = "0";
			}
			// A/i = q R r
			// q * i  + r = A
			// r =  A - (i* q)
			Integer q = A / i;
			Integer r = A - (i * q);
			std::string result;
			result = r.getValue();
			while (result[0] == '0')
			{
				result = result.substr(1);
			}
			value = result;
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

	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
		{
			return false;
		}

		std::string str1 = lhs.getValue();
		std::string str2 = rhs.getValue();
		int n1 = str1.size();
		int n2 = str2.size();
		char str1Sign = str1[0];
		char str2Sign = str2[0];
		if (str1Sign == str2Sign && (str1Sign == '-' || str1Sign == '+'))
		{ // if the sign is same
			Integer x = Integer(str1.substr(1));
			Integer y = Integer(str2.substr(1));
			if (str1Sign == '+')
			{
				return (x < y);
			}
			else
			{
				return (x > y);
			}
		}
		else if (str1Sign == '+' && (str2Sign != '-' && str2Sign != '+'))
		{
			Integer x = Integer(str1.substr(1));
			return (x < rhs);
		}
		else if (str1Sign == '-' && (str2Sign != '-' && str2Sign != '+'))
		{ // lhs = negative  rhs = positive
			return true;
		}
		else if ((str1Sign != '-' && str1Sign != '+') && str2Sign == '+')
		{
			Integer y = Integer(str2.substr(1));
			return (lhs < y);
		}
		else if ((str1Sign != '-' && str1Sign != '+') && str2Sign == '-')
		{
			return false;
		}
		else if (str1Sign == '+' && str2Sign == '-')
		{
			return false;
		}
		else if (str1Sign == '-' && str2Sign == '+')
		{
			return true;
		}

		if (n1 > n2)
		{
			return false;
		}
		else if (n2 > n1)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < n2; i++)
			{
				int num1 = str1[i] - '0';
				int num2 = str2[i] - '0';
				if (num1 > num2)
				{
					return false;
				}
			}
		}
		return false;
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
		{
			return false;
		}

		std::string str1 = lhs.getValue();
		std::string str2 = rhs.getValue();
		int n1 = str1.size();
		int n2 = str2.size();
		char str1Sign = str1[0];
		char str2Sign = str2[0];
		if (str1Sign == str2Sign && (str1Sign == '-' || str1Sign == '+'))
		{ // if the sign is same
			Integer x = Integer(str1.substr(1));
			Integer y = Integer(str2.substr(1));
			if (str1Sign == '+')
			{
				return (x > y);
			}
			else
			{
				return (x < y);
			}
		}
		else if (str1Sign == '+' && (str2Sign != '-' && str2Sign != '+'))
		{
			Integer x = Integer(str1.substr(1));
			return (x > rhs);
		}
		else if (str1Sign == '-' && (str2Sign != '-' && str2Sign != '+'))
		{ // lhs = negative  rhs = positive
			return false;
		}
		else if ((str1Sign != '-' && str1Sign != '+') && str2Sign == '+')
		{
			Integer y = Integer(str2.substr(1));
			return (lhs > y);
		}
		else if ((str1Sign != '-' && str1Sign != '+') && str2Sign == '-')
		{
			return true;
		}
		else if (str1Sign == '+' && str2Sign == '-')
		{
			return true;
		}
		else if (str1Sign == '-' && str2Sign == '+')
		{
			return false;
		}
		else
		{
			if (n1 > n2)
			{

				return true;
			}
			else if (n2 > n1)
			{

				return false;
			}
			else
			{
				for (int i = 0; i < n2; i++)
				{
					int num1 = str1[i] - '0';
					int num2 = str2[i] - '0';
					if (num1 > num2)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	bool operator<=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
			return true;
		else
			return (lhs > rhs);
	}

	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
			return true;
		else
			return (lhs > rhs);
	}

	bool operator==(const Integer &lhs, const Integer &rhs)
	{
		std::string str1 = lhs.getValue();
		std::string str2 = rhs.getValue();
		int n1 = str1.size(),
			n2 = str2.size(), sum1 = 0, sum2 = 0;
		if ((str1[0] == '+' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '+'))
		{
			if (str1[0] == '+')
			{
				Integer x = Integer(str1.substr(1));
				return (x == rhs);
			}
			if (str2[0] == '+')
			{
				Integer y = Integer(str2.substr(1));
				return (lhs == y);
			}
		}
		if (str1[0] != str2[0])
		{
			return false;
		}
		else
		{
			if (n1 != n2)
			{
				return false;
			}
			else
			{
				int index = 0;
				while (str1[index] == str2[index])
				{
					index++;
					if (index == n1)
						return true;
				}
			}
		}
		return false;
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

		while (n1 != n2)
		{
			if (n1 > n2)
			{

				n1 -= n2;
			}
			else
			{

				n2 -= n1;
			}
			// break;
		}
		return n1;
	}
}
