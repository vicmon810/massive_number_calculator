/*
	Test main for Rational and Integer
	// 1 = true
	// 0 = false
*/

#include <iostream>
using namespace std;

#include "Integer.h"
#include "Rational.h"

using namespace cosc326;

int main()
{
	// Integer class
	//  Integer i = Integer();
	Integer x = Integer("11001");
	Integer y = Integer("29");
	x *= y;

	cout << x << endl;
	//  Integer copy = Integer(x);
	//  i += copy;
	//  cout << i << endl; // 12
	//  cout << y << endl;
	//  Integer o = y / x;
	//  cout << o << endl;
	//  y %= x;
	//  cout << y << endl;
	//  Integer a = gcd(y, i);
	//  cout << a << endl;
	Rational c = Rational("-1.1001");

	Rational d = Rational("2.9");
	c += d;
	// cout << c << endl;
	Rational f;
	// f = c + d;
	// cout << f << " " << (c + d) << endl;
	// cout << (c > d) << endl;
	return 0;
}
