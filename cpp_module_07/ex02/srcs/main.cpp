/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:03:24 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/07 21:30:00 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

void printStringArr(Array<std::string> arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << i << ": " << arr[i] << std::endl;
	}
}

void createStringArr() {
	Array<std::string> strArr(3);
	printStringArr(strArr);
	strArr[0] = "Yakum";
	strArr[1] = "Duyum";
	strArr[2] = "Seyum";
	printStringArr(strArr);
	Array<std::string> strCopyConstructor(strArr);
	std::cout << "Copy constructor" << std::endl;
	printStringArr(strCopyConstructor);
	std::cout << "Changed first element: " << strCopyConstructor[0] << std::endl;
	strCopyConstructor[0] = "Changed";
	std::cout << "Changed array: " << strCopyConstructor[0] << std::endl;
	std::cout << "Original array: " << strArr[0] << std::endl;
	std::cout << "Assignment operator" << std::endl;
	Array<std::string> strAssignOperator(20);

	strAssignOperator = strCopyConstructor;
	printStringArr(strAssignOperator);
}

void outOfBoundsExceptions() {
	Array<std::string> arr;
	std::cout << "Index 0: " << arr[0] << std::endl;
	try {
		arr[1];
	}
	catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}
	Array<int> intArr(10);
	std::cout << "Last index: " << intArr[9] << std::endl;
	std::cout << "After last index" << std::endl;
	try {
		intArr[-1];
	}
	catch (std::exception &e) {
		std::cout << "Expected exception_last: " << e.what() << std::endl;
	}
}

void constSubsriptOperator() {
	Array<std::string> strArr(3);
	printStringArr(strArr);
	strArr[0] = "Yakum";
	strArr[1] = "Duyum";
	strArr[2] = "Seyum";
	std::string &yakum = strArr[0];
	yakum = "chahorum";
	std::cout << "changed: " << strArr[0] << std::endl;
	const std::string duyum = strArr[1];
	// duyum = "panjum";
}

void printFirstElement(const Array<int>& arr) {
	// Without the const version of operator[], this wouldn't compile
	std::cout << "First element: " << arr[0] << std::endl;
}

int main(void) {
	Array<int> numbers(3);
	numbers[0] = 42;
	// This calls the function with a const reference
	printFirstElement(numbers);
	numbers[0] = 100;
	printFirstElement(numbers);
	const Array<int> constNumbers(3);
	std::cout << "Const array first element: " << constNumbers[0] << std::endl;
	// constNumbers[0] = 200;
	// createStringArr();
	outOfBoundsExceptions();
	// constSubsriptOperator();
	return 0;
}
