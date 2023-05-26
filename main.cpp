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
	Integer i = Integer("19");
	Integer c = Integer("19");
	// Integer d = Integer("4");
	// Integer a = Integer("-54543434345");
	// Integer b = Integer(i);
	// Arithmetic operators
	// i += c;
	// i -= d;

	// i /= c;
	// a /= d;
	// i %= i;
	bool test = i != c;
	cout
		<< test << std ::endl;
	return 0;
}