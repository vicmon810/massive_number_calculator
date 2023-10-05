#include <iostream>
#include "Rational.h"
#include "Integer.h"
#include <iostream>
#include <cassert>
using namespace std;
using namespace cosc326;
void plusTest()
{
    Integer i1;
    Integer i2("123");
    Integer i3("-123");
    Integer i4("+12");
    Integer i5(i2);
    Integer i6(gcd(i4, i2));
    Integer isum = i4 + i2;
    assert(isum == Integer("135"));
    assert(isum != Integer("35"));
    assert(isum >= Integer("35"));
    assert(isum <= Integer("185"));
}
void substractest()
{
    Integer i1;
    Integer i2("123");
    Integer i3("-123");
    Integer i4("+12");
    Integer i5(i2);
    Integer i6(gcd(i4, i2));
    Integer idifference = i3 - i4;
    assert(idifference == (i3 - i4));
    assert(idifference != i5);
    assert(idifference < i4);
}
int main()
{
    cout << "Start Test:" << endl;
    plusTest();
    substractest();
    cout << "End Test. All Passed!" << endl;
}