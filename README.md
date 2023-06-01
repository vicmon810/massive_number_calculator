# Rational Thinking:
In this project, we will be developing a wheel that was conceptualized by several individuals nearly 30 years ago. The program consists of two main components: Integer and Rational. The Integer component is designed for performing calculations with whole numbers, which can have an infinite length similar to Java's BigInteger class. On the other hand, the Rational component handles calculations involving decimal numbers, allowing for potentially infinite precision, much like Java's BigDecimal class.

Our objective is to reimplement and refine the original concept, taking advantage of modern technologies and advancements in the field. By doing so, we aim to create a robust and efficient solution that meets the needs of various applications requiring extensive numerical calculations.

The Integer part of the program will offer comprehensive functionality for performing operations on large whole numbers. This will allow us to handle computations involving numbers that exceed the limits of standard data types, ensuring accurate and reliable results. With this component, we can tackle complex mathematical problems that require precision and a wide range of integer values.

The Rational component, on the other hand, will be responsible for handling decimal numbers with arbitrary precision. By utilizing sophisticated algorithms and techniques, we can perform calculations on decimal values that may have infinite lengths after the decimal point. This capability will be particularly valuable in scenarios where high precision is vital, such as financial calculations or scientific research.

To ensure the efficiency and reliability of our solution, we will carefully optimize the algorithms and data structures used in both components. By leveraging the power of modern computing systems, we can achieve optimal performance, even when dealing with extremely large or highly precise numbers. Additionally, we will prioritize code maintainability and readability, allowing for easy integration into existing projects or further enhancements in the future.

By revisiting and revitalizing this project, we aim to contribute to the computational landscape and provide developers with powerful tools for numerical analysis. Our endeavor is rooted in the desire to build upon the knowledge and efforts of those who paved the way, while incorporating the advancements of the past three decades.



### Usage :
In order to run this Integer calculation please compile Integer class first with command : `g++ -Wall -c Integer.cpp -o Integer.o` then compile main class with command `g++ -Wall main.cpp Integer.o -o main` finally enter command `./main` to run it.
In order to run the Rational Calculation please compile Integer class first with command :`g++ -Wall -c Integer.cpp -o Integer.o`, then compile Rational class with command `g++ -Wall -c Rational.cpp -o Rational.o`, lastly compile main class using command `g++ -Wall main.cpp  Integer.o Rational.o -o main`. After compile all class without any error message when using command `./main` to run this program. 


### Test Case :

|Test Case| Test method|Test process | Result|
|:--------|:------------|:-----------|:-------|
|#1.1|Operator += | no sign addition| OK|
|#1.2|Operator +=| one positive sign and one has no sign number addition| OK|
|#1.3|Operator +=|one negative sign and one no sign number addition| OK|
|#1.4|Operator +=|two positive sign number addition| OK|
|#1.5|Operator +=|one positive sign and one negative sign number addition|OK|
|#1.6|Operator +=|two negative sign addition| OK|
|#1.7|Operator +=|one short number and one long number addition|OK|
|#1.8|Operator +=|two long number addition | OK|
|#2.1|Operator -=|no sign subtraction| OK|
|#2.2|Operator -=|A-=B where B > A| OK|
|#2.3|Operator -=|+A -= B|OK|
|#2.4|Operator -=|+A -= +B|OK|
|#2.5|Operator -=|-A -=B|OK|
|#2.6|Operator -=|-A -= -B|OK|
|#2.7|Operator -=|+A -= -B|OK|
|#2.8|Operator -=|-A -= +B|OK|
|#2.8|operator -=|both A and B are long number| OK|
|#3.1|Operator *=|no sign multiple |OK|
|#3.2|Operator *=|-A *= B |OK|
|#3.3|Operator *=|A *= -B| OK|
|#3.4|Operator *=|-A *= -B|OK|
|#3.5|Operator *=|-A *= -B|OK|
|#3.6|Operator *=|-A *= +B|OK|
|#3.7|Operator *=|+A *= -B|OK|
|#3.8|Operator *=|Both A and B are large number|OK|
|#3.9|Operator *=|+A *= +B|OK|
|#4.1|Operator /=|no sign division|OK|
|#4.2|Operator /=|-A /= B |OK|
|#4.3|Operator /=|A /= -B |OK|
|#4.4|Operator /=|A /= -B |OK|
|#4.5|Operator /=|-A /= -B |OK|
|#4.6|Operator /=|+A /= -B|OK|
|#4.7|Operator /=|-A /= -B|OK|
|#4.8|Operator /=|Both A and B are Long number|OK|
|#5.1|Operator %=|no sign remainder| OK|
|#5.2|Operator %=|-A %= B|OK|
|#5.3|Operator %=|A %= -B|OK|
|#5.4|Operator %=|-A %= -B|OK|
|#5.5|Operator %=|+A %= -B|OK|
|#5.6|Operator %=|+A %= +B|OK|
|#5.7|Operator %=|-A %= +B|OK|
|#5.8|Operator %=|+A %= -B|OK|
|#5.9|Operator %=|both A and B are long number|OK|
|#6.1|Operator < | A < B (A is smaller)| OK|
|#6.2|Operator < | A < B (A is bigger)| OK|
|#6.3|Operator > | A > B (A is smaller)| OK|
|#6.4|Operator > | A > B (A is bigger)| OK|
|#6.5| Operator >=| A >= B( A is smaller)| OK|
|#6.6|Operator >=| A >=B(A is bigger)| OK|
|#6.7|Operator >=| A >= B (A == B)| OK|
|#6.8|Operator <=| A <= B (A is smaller)|OK|
|#6.9|Operator <=| A <= B(A is bigger)|OK|
|#6.10|Operator <= | A <= B (A == B)|OK|
|#6.11| Operator ==| A == B (A !=B)| OK|
|#6.12|Operator == | A == B (A == B)|OK|
|#6.13| Operator !=| A != B (A ==B)|OK|
|#6.14| Operator !=| A != B (A!=B)|OK|
|#7.1| Operator +|  +A| OK|
|#7.2|Operator -| -A |OK|
|#8.1| Operator +(Binary operators)| A + B|OK|
|#8.2| Operator - (Binary operators)| A -B|OK|
|#8.3| Operator * (Binary operators)| A * B|OK|
|#8.4|Operator / (Binary operators)| A /B |OK|
|#8.5| Operator % (Binary operators)| A % B|OK|
|#9.1| gcd | gcd (A,B)|OK| 