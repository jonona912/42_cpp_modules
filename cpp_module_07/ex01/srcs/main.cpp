/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:01:47 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 14:22:13 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"




void addOne(int &num) {
	num++;
}

void deductOne(int const &num) {
	const_cast<int &>(num)--;
}


void toUpperCase(std::string &str) {
	for (size_t i = 0; i < str.size(); ++i) {
		char &c = str[i];
		if (c >= 'a' && c <= 'z') {
			c -= 32; // Convert to uppercase
		}
	}
}

int main(void) {
	int arr[3] = {1, 2, 3};
	std::string strArr[] = {"1abcd", "2efgh", "#ijkl"};
	std::cout << arr[0] << "  " << arr[1] << std::endl;
	iter(arr, 3, addOne);
	std::cout << arr[0] << "  " << arr[1] << std::endl;

	iter(arr, 3, deductOne);
	iter(arr, 3, deductOne);
	std::cout << arr[0] << "  " << arr[1] << std::endl;
	std::cout << strArr[0] << "  " << strArr[1] << std::endl;
	iter(strArr, 3, toUpperCase);
	std::cout << strArr[0] << "  " << strArr[1] << std::endl;
}
