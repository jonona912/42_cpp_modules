/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:21:05 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 14:21:08 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <cassert>

void testMin() {
	int a = 3, b = 7;
	std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << std::endl;

	float x = 2.2f, y = 2.2f;
	std::cout << "min(" << x << ", " << y << ") = " << min(x, y) << std::endl;

	char c1 = 'z', c2 = 'a';
	std::cout << "min('" << c1 << "', '" << c2 << "') = '" << min(c1, c2) << "'" << std::endl;
}

void testMax() {
	int a = 3, b = 7;
	std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << std::endl;

	float x = 2.2f, y = 2.2f;
	std::cout << "max(" << x << ", " << y << ") = " << max(x, y) << std::endl;

	char c1 = 'z', c2 = 'a';
	std::cout << "max('" << c1 << "', '" << c2 << "') = '" << max(c1, c2) << "'" << std::endl;
	int firstArg = 5;
	int secondArg = 5;
	int &minValue = min(firstArg, secondArg);
	std::cout << "minValue before change: " << minValue << std::endl;
	minValue = 10;
	std::cout << "secondArg after change: " << secondArg << std::endl;
}

void testSwap() {
	float a = 5.5f;
	float b = 10.1f;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap : a = " << a << ", b = " << b << std::endl;

	int x = 42;
	int y = 84;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap : x = " << x << ", y = " << y << std::endl;

	char c1 = 'A';
	char c2 = 'B';
	std::cout << "Before swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	swap(c1, c2);
	std::cout << "After swap : c1 = " << c1 << ", c2 = " << c2 << std::endl;
	
}

void subjectTest() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main(void) {
	// testSwap();
	// testMin();
	testMax();
	subjectTest();
	return 0;
}