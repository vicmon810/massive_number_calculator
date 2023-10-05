cmake_minimum_required(VERSION 2.8)

project(RationalThinking)

add_executable(RationalThinking
main.cpp
Integer.h
Integer.cpp
Rational.h
Rational.cpp
)

add_executable(RationalThinking_test
testMain.cpp
Integer.h
Integer.cpp
Rational.h
Rational.cpp
)
