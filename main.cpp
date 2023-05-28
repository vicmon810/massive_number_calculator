/*
	Test main for Rational and Integer
	// 1 = true
	// 0 = false
*/

#include "Rational.h"
#include <iostream>
using namespace std;

#include "Integer.h"
#include "Rational.h"

using namespace cosc326;

int main()
{
	Integer i = Integer();
	Integer x = Integer("12");
	Integer y = Integer("17");
	+y;
	cout << y << endl; // 16
	-x;
	cout << x << endl; // 11
	Integer copy = Integer(x);
	return 0;
}
