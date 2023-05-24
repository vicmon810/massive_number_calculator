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
	Integer i = Integer("154654312");
	Integer c = Integer("22");
	// Integer d = Integer("4");
	// Integer a = Integer("-54543434345");
	// Integer b = Integer(i);
	// Arithmetic operators
	// i += c;
	// i -= d;

	i -= c;
	// a /= d;
	// i %= i;
	cout << i << std ::endl;
	return 0;
}