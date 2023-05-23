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
			int inputLen = input.length() - 1;
			int localLen = value.length() - 1;
			int min = std::min(inputLen, localLen);
			int max = std::max(inputLen, localLen);

			if (inputLen > localLen)
			{
				std::string temp = value;
				value = input;
				input = temp; // swap input and local
			}

			for (int i = max; i >= max - min; i--)
			{
				std::cout << value << " Test " << i << std::endl;

				int carrier = 0;
				char ch1 = value[i];
				char ch2 = input[i - (max - min)];
				int num1 = ch1 - '0';
				int num2 = ch2 - '0';
				carrier = num1 + num2;
				int test = max - min;
				if (carrier < 10)
				{
					value[i] = '0' + carrier;
					std::cout << "HH: " << value << std::endl;
				}
				else if (carrier >= 10 && test == 0)
				{
					value[i] = '0' + (carrier % 10);
					std::string newIndex = std::to_string(carrier);
					char c = newIndex[0];
					std::cout << c << " " << carrier << std::endl;
					value.insert(value.begin(), c);
					std::cout << "FD: " << value << std::endl;
				}
				else
				{
					value[i] = '0' + (carrier % 10);
					carrier /= 10;
					int j = i - 1;
					std::cout << "MM: " << value << std::endl;
					while (carrier > 0 && j >= 0)
					{
						carrier += value[j] - '0';
						value[j] = '0' + (carrier % 10);
						carrier /= 10;
						j--;
						std::cout << "CC: " << value << std::endl;
						if (j < 0 && carrier > 0)
						{
							std::string newIndex = std::to_string(carrier);
							char c = newIndex[0];
							value.insert(value.begin(), c);
							std::cout << "DD: " << value << std::endl;
						}
					}
				}
			}
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

			int inputLen = input.length() - 1;
			int localLen = value.length() - 1;
			int min = std::min(inputLen, localLen);
			int max = std::max(inputLen, localLen);
			if (inputLen > localLen)
			{ // eg:  1 - 12 / 34 - 153
				std::string temp = input;
				input = value;
				value = temp;
				negative = true;
			}
			for (int i = max; i >= max - min; i--)
			{

				int remain = 0;
				char ch1 = value[i];
				char ch2 = input[i - (max - min)];
				int num1 = ch1 - '0';
				int num2 = ch2 - '0';
				remain = num1 - num2;
				if (remain >= 0)
				{
					value[i] = '0' + remain;
				}
				else if (remain < 0 && i == max - min)
				{ // last digit
					remain = num2 - num1;
					value[i] = '0' + remain;

					negative = true;
				}
				else
				{
					int num = 10 - num2 + num1;
					value[i] = '0' + num;
					int j = i - 1;
					char ch = value[j];
					int holder = ch - '0';
					holder -= 1;
					value[j] = '0' + holder;
				}

				if (value[0] == '0')
				{
					value = value.substr(1);
				}
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
		value_int *= i.value_int;
		return *this;
	}
	/*divide local value by input i*/
	Integer &Integer::operator/=(const Integer &i)
	{
		value_int /= i.value_int;

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
		return true;
	}

	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		return true;
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
