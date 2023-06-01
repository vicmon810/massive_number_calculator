#include <iostream>
#include "Rational.h"
#include "Integer.h"
int main()
{
	using namespace std;
	using namespace cosc326;
	// Create Integer objects using different constructors
	Integer i1;
	Integer i2("123");
	Integer i3("-123");
	Integer i4("+12");
	Integer i5(i2);
	Integer i6(gcd(i4, i2));

	// Display the created Integer objects
	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;
	cout << "i3: " << i3 << endl;
	cout << "i4: " << i4 << endl;
	cout << "i5: " << i5 << endl;
	cout << "i6: " << i6 << endl;
	// Perform arithmetic operations on Rational objects
	Integer isum = i4 + i2;
	Integer idifference = i3 - i4;
	Integer iproduct = i4 * i3;
	Integer iquotient = i4 / i5;

	// Display the results
	cout << "Sum: " << isum << endl;
	cout << "Difference: " << idifference << endl;
	cout << "Product: " << iproduct << endl;
	cout << "Quotient: " << iquotient << endl;
	cout << "GCD: " << i6 << endl;
	// Create Rational objects using different constructors
	Rational r1;										   // Default constructor
	Rational r2("-3/7");								   // Constructor from string
	Rational r3(Integer("5"));							   // Constructor from string
	Rational r4(Integer("2"), Integer("3"));			   // Constructor from fraction
	Rational r5(Integer("1"), Integer("2"), Integer("3")); // Constructor from mixed number
	Rational r6(r2);									   // Copy constructor

	// Display the created Rational objects
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;
	cout << "r4: " << r4 << endl;
	cout << "r5: " << r5 << endl;
	cout << "r6: " << r6 << endl;

	// Perform arithmetic operations on Rational objects
	Rational sum = r4 + r2;
	Rational difference = r3 - r4;
	Rational product = r4 * r3;
	Rational quotient = r4 / r5;

	// Display the results
	cout << "Sum: " << sum << endl;
	cout << "Difference: " << difference << endl;
	cout << "Product: " << product << endl;
	cout << "Quotient: " << quotient << endl;

	return 0;
}
