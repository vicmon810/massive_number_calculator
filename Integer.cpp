#include "Integer.h"
#include <iostream>
#include <string>
#include <cstring>
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
	// non so sure what is method for
	Integer &Integer::operator=(const Integer &i)
	{
		return *this;
	}
	// equal to j--;
	Integer Integer::operator-() const
	{

		value_int--;
		return Integer(*this);
	}
	// equal to j++;
	Integer Integer::operator+() const
	{
		value_int++;
		return Integer(*this);
	}
	/*accumulate local value by input i*/
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

	/*substruc local value by input i*/
	Integer &Integer::operator-=(const Integer &i)
	{
		std::string input = i.value;
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		bool negative = false;
		if (firstInput.compare("-") == 0 && firstLocal.compare("+") == 0)
		{ //+x - -y == x + y
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("-") == 0)
		{ //-x - +y =  - (x+y)
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = "-" + x.getValue();
		}
		else if (firstInput.compare("+") == 0 && firstLocal.compare("+") == 0)
		{ // +x - +y = x - y;
			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x -= y;
			value = x.getValue();
		}
		else if (firstInput.compare("-") == 0 && firstLocal.compare("-") == 0)
		{ // -x - -y = y - x

			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			y -= x;
			value = x.getValue();
		}
		else if (firstInput.compare("-") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x - -y = x + y
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			std::cout << x << "x" << std::endl;
			std::cout << y << "y" << std::endl;
			x += y;
			std::cout << x << " " << y << std::endl;
			value = x.getValue();
		}
		else if (firstInput.compare("+") == 0 && (firstLocal.compare("-") != 0 && firstLocal.compare("+") != 0))
		{ // x - +y = x - y
			Integer x = Integer(value);
			Integer y = Integer(input.substr(1));
			x += y;
			value = x.getValue();
		}
		else if ((firstInput.compare("-") != 0 && firstInput.compare("+") != 0) && firstLocal.compare("-") == 0)
		{ //-x - y = y - x
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
			reverse(result.begin(), result.end());
			value = result;
			if (value[0] == '0')
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
		std::string firstInput = input.substr(0, 1);
		std::string firstLocal = value.substr(0, 1);
		std::cout << firstInput << " " << firstLocal << std::endl;
		if (firstInput == "-")
		{
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
			for (int i = max; i >= 0; i--)
			{
				for (int j = min; j >= 0; j--)
				{
					int n = (value[i] - '0') * (input[j] - '0') + holder[i + j + 1];
					holder[i + j + 1] = n % 10;
					holder[i + j] += n / 10;
				}
			}

			for (int i = 0; i < holder.size(); i++)
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

	/*divide local value by input i*/
	Integer &Integer::operator/=(const Integer &i)
	{
		Integer i = Integer(value);
		Integer c = Integer(i.value);
		if (c > i)
		{
			value = 0;
		}
		std::string result = "";
		int i = 0;

		return *this;
	}
	/*remain local value by input i */
	Integer &Integer::operator%=(const Integer &i)
	{
		value_int %= i.value_int;
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
		result += rhs;
		return result;
	}

	Integer operator*(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	std::ostream &operator<<(std::ostream &os, const Integer &i)
	{
		os << i.getValue();
		return os;
	}

	std::istream &operator>>(std::istream &is, Integer &i)
	{
		return is;
	}

	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		std::string str1 = lhs.getValue();
		std::string str2 = rhs.getValue();
		int n1 = str1.size(),
			n2 = str2.size();
		if (n1 < n2)
		{
			return true;
		}
		if (n1 > n2)
		{
			return false;
		}
		for (int i = 0; i < n1; i++)
		{
			if (str1[i] < str2[i])
			{
				return true;
			}
			else if (str1[i] > str2[i])
			{
				return false;
			}
		}
		return false;
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		std::string str1 = lhs.getValue();
		std::string str2 = rhs.getValue();
		int n1 = str1.size(),
			n2 = str2.size();
		if (n1 < n2)
		{
			return false;
		}
		if (n1 > n2)
		{
			return true;
		}
		for (int i = 0; i < n1; i++)
		{
			if (str1[i] < str2[i])
			{
				return false;
			}
			else if (str1[i] > str2[i])
			{
				return true;
			}
		}
		return false;
	}

	bool operator<=(const Integer &lhs, const Integer &rhs)
	{
		return true;
	}

	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		return true;
	}

	bool operator==(const Integer &lhs, const Integer &rhs)
	{
		return true;
	}

	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		return true;
	}

	Integer gcd(const Integer &a, const Integer &b)
	{
		return a;
	}
}
