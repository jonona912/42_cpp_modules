/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:53:23 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/04 21:55:25 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <stdexcept>
#include <cstdlib>

PmergeMe::PmergeMe(const PmergeMe& other)
	: _myVector(other._myVector), _myDeque(other._myDeque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_myVector = other._myVector;
		this->_myDeque = other._myDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isAllDigits(const char* str) {
    if (!str || *str == '\0') {
        return false;
    }
    
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

PmergeMe::PmergeMe(int ac, char* av[]) {
    for (int i = 1; i < ac; ++i) {
        if (!isAllDigits(av[i])) {
            throw OperationInterrupt();
        }
        
        int value = std::atoi(av[i]);
        if (value <= 0) {
            throw OperationInterrupt();
        }
        
        this->_myVector.push_back(value);
        this->_myDeque.push_back(value);
    }
}
void PmergeMe::sortAndMeasure() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _myVector.size(); ++i) {
		std::cout << _myVector.at(i) << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	mergeInsertSort(_myVector);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	mergeInsertSort(_myDeque);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	// for (int x : _myVector) std::cout << x << " ";
	for (size_t i = 0; i < this->_myVector.size(); i++) {
		std::cout << this->_myVector.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _myVector.size() << " elements with std::vector: " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _myDeque.size() << " elements with std::deque: " << dequeTime << " us" << std::endl;
}

// Other methods (destructor, copy constructor, assignment operator) as before