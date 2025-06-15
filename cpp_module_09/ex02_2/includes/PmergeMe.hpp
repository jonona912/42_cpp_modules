/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:40:36 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/15 21:41:16 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
	PmergeMe(int ac, char* av[]);
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	void sortAndMeasure();

	class OperationInterrupt : public std::exception {
	public:
		const char* what() const throw() { return "Error"; }
	};

private:
	std::vector<int> _myVector;
	std::deque<int> _myDeque;
	bool isAllDigits(const char* str);
	// template <typename Container>
	
	// template <typename Container>

	// recursion to
	long unsigned int jacobsthaalNum(long unsigned int idx);
	template <typename C>
	long unsigned int binaryInsertJacobtaalNums(C &main, long unsigned int groupHalf, long unsigned int pendValue, long unsigned int jNum);
	template <typename C>
	void jacobsthallInsertionHelper(C &pend, C &main, C &arr, long unsigned int groupHalf);
	template <typename C>
	void fordJohnsonSort(C &arr, long unsigned int groupSize);
	template <typename C>
	void jacobsthallInsertion(C &arr, long unsigned int groupHalf);
};
