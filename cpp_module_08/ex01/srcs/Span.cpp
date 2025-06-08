/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:40:30 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 11:42:26 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

Span::Span(unsigned int arrSize) {
	_numArr.reserve(arrSize);
}

Span::~Span() {}

void Span::addNumber(unsigned int n) {
	if (this->_numArr.size() <= this->_numArr.capacity()) {
		// std::cout << "exception should be thrown: Not enough space" << std::endl;
		this->_numArr.push_back(n);
		return ;
	}
	throw SpanException("Not enough capacity");
	// throw error
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end) {
	unsigned int distance = std::distance(begin, end);
	// std::cout << "Distance: " << distance << std::endl;
	if (this->_numArr.size() + distance <= (this->_numArr.capacity())) {
		this->_numArr.insert(this->_numArr.end(), begin, end);
	}
	else {
		throw SpanException("Not enough capacity");
	}
}

unsigned int Span::longestSpan() {
	if (this->_numArr.size() <= 1) {
		throw SpanException("Not enough data");
	}
	unsigned int max = *max_element(this->_numArr.begin(), this->_numArr.end());
	unsigned int min = *min_element(this->_numArr.begin(), this->_numArr.end());
	// std::cout << "max - min " << max - min << std::endl;
	return (max - min);
}

unsigned int Span::shortestSpan() {
	if (this->_numArr.size() <= 1) {
		throw SpanException("Not enough data");
		return -1;
	}
    std::vector<unsigned int> sorted = this->_numArr;
    std::sort(sorted.begin(), sorted.end());
    
    // Find minimum difference between adjacent elements
    unsigned int minSpan = UINT_MAX; // Start with maximum possible value
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int currentSpan = sorted[i] - sorted[i-1];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

Span::SpanException::SpanException(std::string const &message) :
	_message("Error: " + message) {}

Span::SpanException::~SpanException() throw() {}
	
const char* Span::SpanException::what() const throw() {
	return this->_message.c_str();
}
