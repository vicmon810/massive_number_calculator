#include "Integer.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
namespace cosc326
{
	/*
	 * @brief Constructs an Integer object with a default value of 0.
	 */
	Integer::Integer()
	{
		// cout << "here" << endl;
		value = "0";
	}
	/*
	 * @brief Constructs an Integer object from another Integer object.
	 * @param i The Integer object to be copied.
	 */
	Integer::Integer(const Integer &i)
	{
		value = i.value;
	}
	/*
	 * @brief Constructs an Integer object from a string representation of a number.
	 * @param s The string representing the number.
	 */
	Integer::Integer(const std::string &s)
	{
		value = s;
	}
	/*
	 * @brief Destructor for the Integer class.
	 *        (No specific clean-up is performed in this implementation.)
	 */
	Integer::~Integer()
	{
	}
	/*
	 * @brief Getter method to retrieve the value of the Integer object.
	 * @return The value of the Integer as a string.
	 */
	std::string Integer ::getValue() const
	{
		return value;
	}
	/*
	 * @brief Setter method to set the value of the Integer object.
	 * @param s The new value to set, provided as a string.
	 */
	void Integer ::setValue(std::string &s)
	{
		value = s;
	}
	/*
	 * @brief Returns the absolute value of the input.
	 * @param a The value for which the absolute value needs to be returned.
	 * @return The absolute value of the input.
	 */
	Integer abs(const Integer &a)
	{
		std::string str = a.getValue();
		if (str[0] == '-' || str[0] == '+')
		{
			str = str.substr(1);
		}
		return Integer(str);
	}

	/*
	 * @brief Overwrites the local Integer value with the incoming Integer value.
	 * @param i The incoming Integer value.
	 * @return A reference to the updated local Integer value.
	 */
	Integer &Integer::operator=(const Integer &i)
	{
		value = i.getValue();
		return *this;
	}
	/*
	 * @brief Assigns a negative sign to the number if it is positive, and makes it positive if it is negative.
	 * @return The modified Integer object with the updated sign.
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

	/*
	 * @brief Assigns a positive sign to the number.
	 * @return The Integer object with the positive sign assigned.
	 */
	Integer Integer::operator+()
	{
		if (value[0] == '-')
			value.erase(0, 1);
		return *this;
	}
	/*
	 * @brief Accumulates the local value by the input value.
	 * @param i The value by which the local value will be increased.
	 * @return A reference to the updated local value.
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
	/*
	 * @brief De-accumulates the local value by the input value.
	 * @param i The value to subtract from the local value.
	 * @return A reference to the updated local value.
	 */
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
			x -= y;
			value = x.getValue();
		}
		else if (firstInput == "-" && firstLocal == "-")
		{ // -x - -y =  - x + y

			Integer x = Integer(value.substr(1));
			Integer y = Integer(input.substr(1));
			x += y;
			value = "-" + x.getValue();
		}
		else if (firstInput == "-")
		{ // x - -y ==  x + y

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

	/*
	 * @brief Multiplies the local value by the input value.
	 * @param i The value to multiply the local value by.
	 * @return A reference to the updated local value.
	 */
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

	/*
	 * @brief Divides the local value by the input value.
	 * @param i The value to divide the local value by.
	 * @return A reference to the updated local value.
	 */
	Integer &Integer::operator/=(const Integer &i)
	{
		Integer f = Integer(value);
		if (f == i)
		{
			// cout << "here" << value << endl;
			value = "1";
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
	/*
	 * @brief Calculates the remainder of the local value divided by the input value.
	 * @param i The value to divide the local value by and calculate the remainder.
	 * @return A reference to the updated local value.
	 */
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

	/*
	 * @brief Returns the sum of the left-hand side (lhs) and right-hand side (rhs) as an Integer.
	 * @param lhs The left-hand side value (A).
	 * @param rhs The right-hand side value (B).
	 * @return The sum of A + B as an Integer.
	 */
	Integer operator+(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result += rhs;
		return result;
	}
	/*
	 * @brief Returns the difference between the left-hand side (lhs) and right-hand side (rhs) as an Integer.
	 * @param lhs The left-hand side value (A).
	 * @param rhs The right-hand side value (B).
	 * @return The difference A - B as an Integer.
	 */
	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result -= rhs;
		return result;
	}
	/*
	 * @brief Returns the product of the left-hand side (lhs) and right-hand side (rhs) as an Integer.
	 * @param lhs The left-hand side value (A).
	 * @param rhs The right-hand side value (B).
	 * @return The product A * B as an Integer.
	 */
	Integer operator*(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result *= rhs;
		return result;
	}
	/*
	 * @brief Returns the quotient of the left-hand side (lhs) divided by the right-hand side (rhs) as an Integer.
	 * @param lhs The dividend value (A).
	 * @param rhs The divisor value (B).
	 * @return The quotient A / B as an Integer.
	 */
	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		Integer result = Integer(lhs);
		result /= rhs;
		return result;
	}
	/*
	 * @brief Returns the remainder of the left-hand side (lhs) divided by the right-hand side (rhs) as an Integer.
	 * @param lhs The dividend value (A).
	 * @param rhs The divisor value (B).
	 * @return The remainder of A divided by B as an Integer.
	 */
	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		Integer Result = Integer(lhs);
		Result %= rhs;
		return Result;
	}
	/*
	 * @brief Overloads the stream insertion operator (<<) to generate an output string for the cout stream.
	 * @param os The output stream object.
	 * @param i The Integer object to be inserted into the output stream.
	 * @return The modified output stream object.
	 */
	std::ostream &operator<<(std::ostream &os, const Integer &i)
	{
		os << i.getValue();
		return os;
	}
	/*
	 * @brief Overloads the stream extraction operator (>>) to assign the input string to the Integer object.
	 * @param is The input stream object.
	 * @param i The Integer object to which the input string will be assigned.
	 * @return The modified input stream object.
	 */
	std::istream &operator>>(std::istream &is, Integer &i)
	{
		std::string input;
		is >> input;
		i.setValue(input);
		return is;
	}
	/*
	 * @brief Compares the values of two Integer objects and returns true if the left-hand side (lhs) is greater than the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is greater than rhs, false otherwise.
	 */
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
	/*
	 * @brief Compares the values of two Integer objects and returns true if the left-hand side (lhs) is less than the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is less than rhs, false otherwise.
	 */
	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		return rhs > lhs;
	}
	/*
	 * @brief Compares the values of two Integer objects and returns true if the left-hand side (lhs) is smaller than or equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is greater than or equal to rhs, false otherwise.
	 */
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
	/*
	 * @brief Compares the values of two Integer objects and returns true if the left-hand side (lhs) is greater than or equal to the right-hand side (rhs), false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is greater than or equal to rhs, false otherwise.
	 */
	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs || lhs > rhs)
			return true;
		else
			return false;
	}
	/*
	 * @brief Compares the values of two Integer objects and returns true if they are equal, false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is equal to rhs, false otherwise.
	 */
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
	/*
	 * @brief Compares the values of two Integer objects and returns true if they are not equal, false otherwise.
	 * @param lhs The left-hand side Integer object.
	 * @param rhs The right-hand side Integer object.
	 * @return True if lhs is not equal to rhs, false otherwise.
	 */
	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}
	/*
	 * @brief Calculates the greatest common divisor (GCD) of two Integer objects.
	 * @param a The first Integer object.
	 * @param b The second Integer object.
	 * @return The greatest common divisor of a and b.
	 */
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
	/*
	 * @brief Calculates the least common multiple (LCM) of two Integer objects.
	 * @param a The first Integer object.
	 * @param b The second Integer object.
	 * @return The least common multiple of a and b.
	 */
	Integer lcm(const Integer &a, const Integer &b)
	{
		Integer gcdValue = cosc326::gcd(a, b); // Use fully qualified name to access gcd function

		// Calculate the LCM using the formula: LCM(a, b) = (a * b) / gcd(a, b)
		Integer product = a * b;
		Integer lcmValue = product / gcdValue;

		return lcmValue;
	}

}
