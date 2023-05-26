/*
	Test main for Rational and Integer
*/

#include "Rational.h"
#include <iostream>
using namespace std;

#include "Integer.h"
#include "Rational.h"

using namespace cosc326;

int main()
{
	cout << "Kia ora World" << std::endl;
	Integer i = Integer("1915515");
	Integer c = Integer("951");
	// Integer d = Integer("4");
	// Integer a = Integer("-54543434345");
	// Integer b = Integer(i);
	// Arithmetic operators
	// i += c;
	// i -= d;

	// i /= c;
	// a /= d;
	// i %= i;
	// true print out 1;
	// false print out 0;
	Integer d;
	std::cout << "Enter an integer value: ";
	std::cin >> d;

	bool f = i != c;
	std::cout
		<< f << std::endl;
	Integer g = Integer(gcd(i, c));
	std::cout << g << std::endl;
	std::cout << d << std::endl;
	return 0;
}