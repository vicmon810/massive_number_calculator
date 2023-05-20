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
	Integer i = Integer("6");
	Integer c = Integer("24");
	Integer d = Integer("6");
	Integer a = Integer("2");
	// Arithmetic operators
	i += c;
	// i -= d;
	// a *= i;
	// a /= i;
	// i %= i;

	cout << i << std ::endl;
	return 0;
}
