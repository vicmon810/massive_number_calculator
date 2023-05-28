
// Most compilers understand the once pragma, but just in case...
#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>

namespace cosc326
{

	class Integer
	{

	public:
		Integer();					   // Integer i;
		Integer(const Integer &i);	   // Integer j(i);
		Integer(const std::string &s); // Integer k("123");

		~Integer();
		std::string getValue() const;
		void setValue(std::string &s);		  // setter value
		Integer &operator=(const Integer &i); // j = i;
		friend Integer abs(const Integer &i); // return absolute value
		// Unary operators
		Integer operator-() const; // -j;
		Integer operator+() const; // +j;

		// Arithmetic assignment operators
		Integer &operator+=(const Integer &i); // j += i;
		Integer &operator-=(const Integer &i); // j -= i;
		Integer &operator*=(const Integer &i); // j *= i;
		Integer &operator/=(const Integer &i); // j /= i;
		Integer &operator%=(const Integer &i); // j %= i;

		// lhs < rhs -- a 'friend' means operator isn't a member, but can access the private parts of the class.
		// You may need to make some other functions friends, but do so sparingly.
		friend bool operator<(const Integer &lhs, const Integer &rhs);

	private:
		// Can add internal storage or methods here
		std::string value;
	};

	// Binary operators
	Integer operator+(const Integer &lhs, const Integer &rhs); // lhs + rhs;
	Integer operator-(const Integer &lhs, const Integer &rhs); // lhs - rhs;
	Integer operator*(const Integer &lhs, const Integer &rhs); // lhs * rhs;
	Integer operator/(const Integer &lhs, const Integer &rhs); // lhs / rhs;
	Integer operator%(const Integer &lhs, const Integer &rhs); // lhs % rhs;
	// Sysout ?
	std::ostream &operator<<(std::ostream &os, const Integer &i); // std::cout << i << std::endl;
	// Sysin ??
	std::istream &operator>>(std::istream &is, Integer &i); // std::cin >> i;

	bool operator>(const Integer &lhs, const Integer &rhs);	 // lhs > rhs
	bool operator<=(const Integer &lhs, const Integer &rhs); // lhs <= rhs
	bool operator>=(const Integer &lhs, const Integer &rhs); // lhs >= rhs
	bool operator==(const Integer &lhs, const Integer &rhs); // lhs == rhs
	bool operator!=(const Integer &lhs, const Integer &rhs); // lhs != rhs

	Integer gcd(const Integer &a, const Integer &b); // i = gcd(a, b);
}

#endif
