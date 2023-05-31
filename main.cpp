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
	// Integer x = Integer("64");
	// Integer y = Integer("46");
	// x += y; // 110
	// x -= y; // 18
	// x *= y;//2944
	// x / y;//1 NEED FIXED
	// cout << x << endl;
	// Integer z = Integer("29");
	// Integer c = Integer("21");
	// Integer sum;
	// sum = z + c;
	// sum = z - c;
	// sum = z * c;
	// cout
	// 	<< (z > c) << endl;
	// sum = z % c;
	// cout << sum << " " << z << " " << c << endl;
	// Integer bigger = Integer("100");
	// Integer smaller = Integer("101");
	// Integer addOne = Integer("1");
	// Integer sum = smaller + addOne;
	// bool equal = bigger == addOne;
	// bool GE = bigger >= smaller;
	// bool Bigger = bigger > smaller;	  // true
	// bool Smaller = bigger < smaller;  // false
	// bool unEqual = bigger != smaller; // true
	// cout << Bigger << " " << Smaller << " " << unEqual << " " << GE << endl;
	// Integer n1 = Integer("18446744073709551654");
	// Integer("1844674407370955165");
	// Integer n2 = Integer("645546454645464");
	// Integer("66564444412134454645645645456456456456454564545454564545454545456456456456546456456456456456456456454564564564545454564564564564545645645645645645645645645645645645645645645645645645645645645456456456");
	// n1 %= n2;

	// cout << n1 << endl;
	// Integer Gcd = gcd(n1, n2);
	// cout << "gdc of " << n1 << " and " << n2 << ": " << Gcd << endl;

	// Rational
	Integer a = Integer("12");
	Integer b = Integer("12");
	Integer c = Integer("33");

	Rational ab = Rational(a, b);
	Rational abc = Rational(a, b, c);
	Rational ac = Rational(a, c);
	Rational copy = abc;

	// cout << ab << " " << abc << " " << copy << endl;
	ab += ac;
	cout << ab << endl;
	return 0;
}
