/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 08:10:15 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 11:44:24 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
// #include <vector>
#include <iostream>

void subjectDemo() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void exceptionsDemo() {
	Span sp1(3);
	sp1.addNumber(0);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp1.addNumber(2);
	std::cout << sp1.shortestSpan() << std::endl;
	sp1.addNumber(5);
	std::cout << sp1.shortestSpan() << std::endl;
	try {
		sp1.addNumber(4);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp1.longestSpan() << std::endl;
}

void testBigDataLoop() {
	Span sp2(10000);
	Span sp3(9999);
	for (unsigned int i = 0; i < 10000; ++i) {
		sp2.addNumber(i);
		try {
			sp3.addNumber(i);
		}
		catch (std::exception &e) {
			std::cout << e.what() << " at " << i << std::endl;
		}
	}
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
}


void testRangeInsertion() {
	std::vector<int> numBers;
	numBers.push_back(1);
	numBers.push_back(2);
	numBers.push_back(20);
	numBers.push_back(4);
	numBers.push_back(5);
	Span sp = Span(12);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span before 1 and 20: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span before 1 and 20: " << sp.longestSpan() << std::endl;
	sp.addNumber(numBers.begin(), numBers.end());
	std::cout << "Shortest span before 1 and 20: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span before 1 and 20: " << sp.longestSpan() << std::endl;
	std::cout << "Triggering exception on 13th" << std::endl;
	std::vector<int> numBers2;
	numBers2.push_back(100);
	numBers2.push_back(200);
	numBers2.push_back(300);
	try {
		sp.addNumber(numBers2.begin(), numBers2.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void) {
	std::cout << "\033[33mSubject demo:\033[0m" << std::endl;
	subjectDemo();
	std::cout << "\033[33mExceptions demo:\033[0m" << std::endl;
	exceptionsDemo();
	std::cout << "\033[33mBig data loop demo:\033[0m" << std::endl;
	testBigDataLoop();
	std::cout << "\033[33mRange insertion demo:\033[0m" << std::endl;
	testRangeInsertion();
	return 0;
}
