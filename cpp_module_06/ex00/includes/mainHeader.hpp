#pragma once

#include "ScalarConverter.hpp"

#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <limits>

// ScalarConverterUtils.hpp
str_type getType(std::string const &str);
void printCharConversions(char c);
void printIntConversions(int i);
void printFloatConversions(float f);
void printDoubleConversions(double d);
void printInvalidType();