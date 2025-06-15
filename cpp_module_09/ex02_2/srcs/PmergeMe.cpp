/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:53:23 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/15 21:55:13 by zkhojazo         ###   ########.fr       */
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
        if (value < 0) {
            throw OperationInterrupt();
        }
        
        this->_myVector.push_back(value);
        this->_myDeque.push_back(value);
    }
	// trackTime
	// sort
	// insert
}

long unsigned int PmergeMe::jacobsthaalNum(long unsigned int idx) {
	if (idx == 0)
		return 0;
	if (idx == 1)
		return 1;
	long unsigned int result = 1; // J(1) = 1
	for (long unsigned int i = 1; i < idx; i++) {
		result = (1 << i) - result;
	}
	return result;
}

template <typename C>
void printContainer(const C& container, const std::string& name) {
	std::cout << name << ": ";
	for (typename C::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename C>
long unsigned int PmergeMe::binaryInsertJacobtaalNums(C &main, long unsigned int groupHalf, long unsigned int pendValue, long unsigned int jNum) {
	long unsigned int left = 0;
	jNum--;
	// long unsigned int pendValue = pend.at(pendPos * groupHalf - 1); // value to search
	long unsigned int mid;
	while (left <= jNum) {
		mid = left + (jNum - left) / 2;
		if (main.at(mid * groupHalf - 1) == pendValue) {
			return mid + 1;
		}
		else if (main.at(mid * groupHalf - 1) < pendValue) {
			left = mid + 1;
		}
		else if (mid > 0) {
			jNum = mid - 1;
		}
		else {
			return 0;
		}
	}
	return left;
}

template <typename C> // should handle the entire pend array
void PmergeMe::jacobsthallInsertionHelper(C &pend, C &main, C &arr, long unsigned int groupHalf) {
	long unsigned int jNum;
	long unsigned int jPrevNum;
	long unsigned int jIdx = 3;
	long unsigned int pendNumIdxs = pend.size() / groupHalf;
	long unsigned int pendInsertMainIdx;
	while (pendNumIdxs > 0) { // no (pendNumIdxs)
		jNum = jacobsthaalNum(jIdx);
		jPrevNum = jacobsthaalNum(jIdx - 1);
		long unsigned int jacobDiff = jNum - jPrevNum;
		if (jacobDiff > pend.size() / groupHalf) {
			jNum = jPrevNum + pend.size() / groupHalf;
			jacobDiff = jNum - jPrevNum;
		}

		// but you have to get done with sets of jNums
		while (jacobDiff > 0) {
			// binary search returns pos
			// then you insert the pend
			// you deduct from jacobDiff for each insertion but send idx starting from jNum - 2 index
			// the trickiest part ====> but send idx starting from jNum - 2 index
		}
		
		
	}
	// while (pend.size() > 0) {
	// 	jNum = jacobsthaalNum(jIdx);
	// 	jPrevNum = jacobsthaalNum(jIdx - 1);
	// 	long unsigned int jacobDiff = jNum - jPrevNum;
	// 	if (jacobDiff > pend.size() / groupHalf) {
	// 		jNum = jPrevNum + pend.size() / groupHalf;
	// 	}
	// 	if ((jNum - jPrevNum) * groupHalf <= pend.size()) {
	// 		// binary insertion
	// 	}
	// }
}

template <typename C>
void PmergeMe::jacobsthallInsertion(C &arr, long unsigned int groupHalf) {
	C main;
	C pend;
	C nonParticipating;
	for (long unsigned int j = 0; j < arr.size() / groupHalf; j++) {
		if (j == 0 || j % 2 == 1) {
			main.insert(main.end(), arr.begin() + j * groupHalf, arr.begin() + j * groupHalf + groupHalf);
		}
		else {
			pend.insert(pend.end(), arr.begin() + j * groupHalf, arr.begin() + j * groupHalf + groupHalf);
		}
	}
	if ((main.size() + pend.size()) < arr.size()) {
		nonParticipating.insert(nonParticipating.end(), arr.begin() + main.size() + pend.size(), arr.end());
	}
	printContainer(pend, "pend");
	printContainer(main, "main");
	printContainer(nonParticipating, "nonP");
	// 
}

template <typename C>
void PmergeMe::fordJohnsonSort(C &arr, long unsigned int groupSize) {
	long unsigned int groupHalf = groupSize / 2;
	if (groupSize > arr.size())
		return;
	long unsigned int	num_of_comparisons = arr.size() / groupSize;
	long unsigned int i = 0;
	for (long unsigned int n = 0; n < num_of_comparisons; n++) {
		if (arr[i + groupSize / 2 - 1] > arr[i + groupSize - 1]) // 
			std::swap_ranges(arr.begin() + i, arr.begin() + i + groupHalf, arr.begin() + i + groupHalf);
		i += groupSize;
	}
	fordJohnsonSort(arr, groupSize * 2);
	// std::cout << "Printing after swaps: " << groupSize << std::endl;
	// for (long unsigned int i = 0; (arr.begin() + i) != arr.end(); i++) {
	// 	std::cout << arr.at(i) << " ";
    // }
	// std::cout << std::endl;
	jacobsthallInsertion(arr, groupHalf);
}

void PmergeMe::sortAndMeasure() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _myVector.size(); ++i) {
		std::cout << _myVector.at(i) << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	// mergeInsertSort(_myVector);
	fordJohnsonSort(_myVector, 1);
	
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	// mergeInsertSort(_myDeque);
	
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