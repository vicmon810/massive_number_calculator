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
	// Integer Test constructor
	// Integer zero = Integer();
	// Integer one = Integer("1");
	// Integer one_copy = Integer(one);
	// Integer longNum = Integer("54646111123132131313213211231231234455456878764645689623132123484589751694312348645645456");
	// cout << zero << " " << one << " " << one_copy << " " << longNum << endl;
	// Unary operator testing
	// +one;
	// cout << one << endl;
	// -one;
	// cout << one << endl; //-1
	// -one;
	// cout << one << endl; // 1 again
	// assign method
	// Integer copy;
	// copy = one;
	// cout << copy << endl; // 1

	// Arithmetic assignment operators
	// Integer x = Integer("64");
	// Integer y = Integer("46");
	// x += y;//110
	// x -= y;//18
	// x *= y;//2944
	// x / y;//1 NEED FIXED
	Integer x = Integer("+64");
	Integer y = Integer("46");
	// x += y; // 110
	x -= y; // 18
	// x *= y;//2944
	// x / y;//1 NEED FIXED
	cout << x << endl;

	return 0;
}
