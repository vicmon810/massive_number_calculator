#pragma once

// Most compilers understand the once pragma, but just in case...
#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>
#include <string>
#include "Integer.h"
using namespace std;
namespace cosc326
{

	class Rational
	{

	public:
		Rational();
		Rational(const std::string &str);
		Rational(const Rational &r);
		Rational(const Integer &a);										// a
		Rational(const Integer &a, const Integer &b);					// a/b
		Rational(const Integer &a, const Integer &b, const Integer &c); // a + b/c

		~Rational();
		std::string getDecValue() const;
		void setDecValue(const std::string &str);
		Rational &operator=(const Rational &r); // q = r;

		// Unary operators
		Rational operator-() const; // -r;
		Rational operator+() const; // +r;

		Rational simplify(const Rational &a); // simplify  denominator and numerator

		// Arithmetic assignment operators
		Rational &operator+=(const Rational &r); // q += r;
		Rational &operator-=(const Rational &r); // q -= r;
		Rational &operator*=(const Rational &r); // q *= r;
		Rational &operator/=(const Rational &r); // q /= r;

		friend bool operator<(const Rational &lhs, const Rational &rhs);
		friend Rational operator+(const Rational &lhs, const Rational &rhs); // lhs + rhs

		friend bool operator>(const Rational &lhs, const Rational &rhs);  // lhs > rhs
		friend bool operator<=(const Rational &lhs, const Rational &rhs); // lhs <= rhs
		friend bool operator>=(const Rational &lhs, const Rational &rhs); // lhs >= rhs
		friend bool operator==(const Rational &lhs, const Rational &rhs); // lhs == rhs
		friend bool operator!=(const Rational &lhs, const Rational &rhs); // lhs != rhs

	private:
		Integer denominators;
		Integer numerator;
		Integer wholeNum;
		string value;
	};

	// Binary operators
	Rational operator+(const Rational &lhs, const Rational &rhs); // lhs + rhs;
	Rational operator-(const Rational &lhs, const Rational &rhs); // lhs - rhs;
	Rational operator*(const Rational &lhs, const Rational &rhs); // lhs * rhs;
	Rational operator/(const Rational &lhs, const Rational &rhs); // lhs / rhs;

	std::ostream &operator<<(std::ostream &os, const Rational &i); // std::cout << i << std::endl;
	std::istream &operator>>(std::istream &is, Rational &i);	   // std::cin >> i;

	bool operator<(const Rational &lhs, const Rational &rhs);

}

#endif
