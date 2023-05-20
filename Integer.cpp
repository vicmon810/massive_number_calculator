#include "Integer.h"
#include <iostream>
#include <string>
namespace cosc326
{
	/*default Constructor*/
	Integer::Integer()
	{
		value_int = 0;
	}
	/*passing int convert to String*/
	Integer::Integer(const Integer &i)
	{
		value_int = i.value_int;
	}
	/*1st class citizen */
	Integer::Integer(const std::string &s)
	{
		value_int = std::stoi(s);
	}

	Integer::~Integer()
	{
	}

	int Integer ::getValue() const
	{
		return value_int;
	}

	Integer &Integer::operator=(const Integer &i)
	{
		return *this;
	}

	Integer Integer::operator-() const
	{
		return Integer(*this);
	}

	Integer Integer::operator+() const
	{
		return Integer(*this);
	}

	Integer &Integer::operator+=(const Integer &i)
	{
		value_int += i.value_int;
		// std::cout << value_int << std::endl;
		return *this;
	}

	Integer &Integer::operator-=(const Integer &i)
	{
		value_int -= i.value_int;
		// std::cout << value_int << std::endl;
		return *this;
	}

	Integer &Integer::operator*=(const Integer &i)
	{
		value_int *= i.value_int;
		// std::cout << value_int << std ::endl;
		return *this;
	}

	Integer &Integer::operator/=(const Integer &i)
	{
		value_int /= i.value_int;
		// std::cout << value_int << std::endl;
		return *this;
	}

	Integer &Integer::operator%=(const Integer &i)
	{
		value_int %= i.value_int;
		// std::cout << value_int << std::endl;
		return *this;
	}

	Integer operator+(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
	}

	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		return lhs;
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
