/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:53:23 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/16 18:46:28 by zkhojazo         ###   ########.fr       */
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
long unsigned int PmergeMe::binaryInsertJacobtaalNums(C &main, long unsigned int groupHalf, long unsigned int pendValue, long unsigned int mainStartIdx) {
	long unsigned int left = 0;
	long unsigned int mid;
	int changedSign = static_cast<int>(pendValue);
	while (left <= mainStartIdx) {
		mid = left + (mainStartIdx - left) / 2;
		if (main.at(mid * groupHalf + groupHalf - 1) == changedSign) {
			return mid + 1;
		}
		else if (main.at(mid * groupHalf + groupHalf - 1) < changedSign) {
			left = mid + 1;
		}
		else if (mid > 0) {
			mainStartIdx = mid - 1;
		}
		else {
			return 0;
		}
	}
	return left;
}


// idx: 1 // b2 b3  b1 a1 a2 => s:2        s + 2 = s: 4   
// idx: 3 // sorted: b2 b1 a1 a2 b3 a3 a4 //      to sort: b4 b5 ()               s: 6  + 2 s: 8
//                    0  1  2  3  4  5  6  7  8  9 10 11 12 13  14             0  1  2  3  4  5  6  7   8  9 
// idx: 10 // sorted: b2 b1 a1 b4 b5 a2 b3 a3 a4 a5 a6 a7 a8 a9 a10  to sort: b2 b3 b4 b5 b6 b7 b8 b9 b10 b11    s: 15
// 
// if mainStartIdx = 0; 
// mainStartIdx += jacobDiff; = 				2 | 6 | 14
// mainStartIdx += numOfPendElementsInserted; + 4 | 8 |
// 
template <typename C> // should handle the entire pend array
void PmergeMe::jacobsthallInsertionHelper(C &pend, C &main, long unsigned int groupHalf) {
	long unsigned int jNum;
	long unsigned int jPrevNum;
	long unsigned int jIdx = 3;
	long unsigned int pendNumIdxs = pend.size() / groupHalf;
	long unsigned int mainStartIdx = 0;   
	while (pendNumIdxs > 0) { // no (pendNumIdxs)
		jNum = jacobsthaalNum(jIdx);
		jPrevNum = jacobsthaalNum(jIdx - 1);
		long unsigned int jacobDiff = jNum - jPrevNum;
		if ((jNum - 1) > pend.size() / groupHalf) {
			jNum = pend.size() / groupHalf + 1; // Solve: // under ideal circumstances, pendIdx is 2 below jNum or at jNum - 2
			jacobDiff = jNum - jPrevNum;
		}
		mainStartIdx += jacobDiff; // main startIdx stays the same for each set of pend insertions or jNum calculation
		// but you have to get done with sets of jNums
		while (jacobDiff > 0) {
			// binary search returns pos
			// then you insert the pend
			// you deduct from jacobDiff for each insertion but send idx starting from jNum - 2 index
			// the trickiest part ====> but send idx starting from jNum - 2 index
			// under ideal circumstances, pendIdx is 2 below jNum or at jNum - 2
			long unsigned int pendValueToCompare = pend.at((jNum - 1) * groupHalf - 1); // jNum - 1 => to get to the 
			// std::cout << "pendValueToCompare " << pendValueToCompare << std::endl;
			long unsigned int mainIdxToInsert = binaryInsertJacobtaalNums(main, groupHalf, pendValueToCompare, mainStartIdx);
			main.insert(main.begin() + mainIdxToInsert * groupHalf, pend.begin() + (jNum - 2) * groupHalf, pend.begin() + (jNum - 1) * groupHalf);
			jacobDiff--;
			pendNumIdxs--;
			jNum--;
			mainStartIdx++;
		}
		jIdx++;
	}
}

template <typename C>
void PmergeMe::jacobsthallInsertion(C &arr, long unsigned int groupHalf) {
	C main;
	C pend;
	C nonParticipating;
	if (groupHalf == 0)
		return ;
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
	jacobsthallInsertionHelper(pend, main, groupHalf);
	for (long unsigned int i = 0; i < nonParticipating.size(); i++) {
		main.push_back(nonParticipating.at(i));
	}
	for (long unsigned int i = 0; i < main.size(); i++) {
		arr.at(i) = main.at(i);
	}
}

template <typename C>
void PmergeMe::fordJohnsonSort(C &arr, long unsigned int groupSize) {
	long unsigned int groupHalf = groupSize / 2;
	if (groupSize > arr.size())
		return;
	long unsigned int	num_of_comparisons = arr.size() / groupSize;
	long unsigned int i = 0;
	for (long unsigned int n = 0; n < num_of_comparisons; n++) {
		if (arr.at(i + groupSize / 2 - 1) > arr.at(i + groupSize - 1)) // 
			std::swap_ranges(arr.begin() + i, arr.begin() + i + groupHalf, arr.begin() + i + groupHalf);
		i += groupSize;
	}
	fordJohnsonSort(arr, groupSize * 2);
	jacobsthallInsertion(arr, groupHalf);
}

template <typename C>
void PmergeMe::printArray(C &arr, std::string str) {
	std::cout << str;
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortAndMeasure() {
	printArray(_myVector, "Before: ");
	// printArray(_myDeque, "Before (deque) : ");
	clock_t start = clock();
	fordJohnsonSort(_myVector, 2);
	
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnsonSort(_myDeque, 2);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	printArray(_myVector, "After: ");
	// printArray(_myDeque, "After (deque) : ");
	std::cout << "Time to process a range of " << _myVector.size() << " elements with std::vector: " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _myDeque.size() << " elements with std::deque: " << dequeTime << " us" << std::endl;
}
