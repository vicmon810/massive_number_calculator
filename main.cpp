#include <iostream>
#include "Rational.h"

int main()
{
    using namespace std;
    using namespace cosc326;

    // Create Rational objects using different constructors
    Rational r1;                            // Default constructor
    Rational r2("3/7");                     // Constructor from string
    Rational r3(Integer("5"));                         // Constructor from string
	Rational r4(Integer("2"), Integer("3"));       // Constructor from fraction
	Rational r5(Integer("1"), Integer("2"), Integer("3")); // Constructor from mixed number
    Rational r6(r2);                        // Copy constructor

    // Display the created Rational objects
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r3: " << r3 << endl;
    cout << "r4: " << r4 << endl;
    cout << "r5: " << r5 << endl;
    cout << "r6: " << r6 << endl;

    // Perform arithmetic operations on Rational objects
    Rational sum = r5 + r2;
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

