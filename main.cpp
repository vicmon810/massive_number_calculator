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
	Integer y = Integer("-17");
	+y;
	cout << y << endl; // 12
	-x;
	cout << x << endl; // 17
	Integer copy = Integer(x);
	i += copy;
	cout << i << endl; // 12
	cout << y << endl;
	Integer o = y / x;
	cout << o << endl;
	y %= x;
	cout << y << endl;
	return 0;
}
