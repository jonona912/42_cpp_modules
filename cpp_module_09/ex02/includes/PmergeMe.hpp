/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:40:36 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/05 06:59:34 by zkhojazo         ###   ########.fr       */
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
	template <typename Container>
	void binaryInsert(Container& sorted, int value) {
		int	left = 0;
		int	right = sorted.size();
		int	mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (sorted[mid] <= value)
				left = mid + 1;
			else
				right = mid;
		}
		sorted.insert(sorted.begin() + left, value);
	}
	template <typename Container>
	void mergeInsertSort(Container& arr) {
		if (arr.size() <= 1) return;
		Container winners, losers;
		for (size_t i = 0; i + 1 < arr.size(); i += 2) {
			if (arr[i] > arr[i + 1]) {
				winners.push_back(arr[i]);
				losers.push_back(arr[i + 1]);
			} else {
				winners.push_back(arr[i + 1]);
				losers.push_back(arr[i]);
			}
		}
		if (arr.size() % 2) losers.push_back(arr.back());
		mergeInsertSort(winners);
		Container result = winners;
		for (typename Container::iterator it = losers.begin(); it != losers.end(); ++it) {
			binaryInsert(result, *it);
		}
		arr = result;
	}
};
