/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:40:47 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 11:32:55 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>

void listFindDemo() {
	std::list<int> strArr;
	std::list<int>::iterator it;
	strArr.push_back(1);
	strArr.push_back(2);
	strArr.push_back(3);
	strArr.push_back(4);
	strArr.push_back(5);
	it = easyfind(strArr, 5);
	std::cout << "Outside: " << *it << std::endl;
	try {
		easyfind(strArr, 6);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void easyfindDemo() {
	std::vector<int> intArr;
	std::vector<int>::iterator it;
	intArr.push_back(1);
	intArr.push_back(2);
	intArr.push_back(3);
	intArr.push_back(4);
	intArr.push_back(5);
	try {
		it = easyfind(intArr, 3);
		std::cout << "Outside: " << *it << std::endl;
		easyfind(intArr, 6); // This will throw an exception
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void setFindDemo() {
	std::set<int> intSet;
	std::set<int>::iterator it;
	intSet.insert(1);
	intSet.insert(2);
	intSet.insert(3);
	intSet.insert(4);
	intSet.insert(5);
	try {
		it = easyfind(intSet, 3);
		std::cout << "Outside: " << *it << std::endl;
		easyfind(intSet, 6); // This will throw an exception
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Negative" << std::endl;
	try {
		easyfind(intSet, -1);
		std::cout << "Failed " << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	std::cout << "Easyfind demo with vector:" << std::endl;
	easyfindDemo();
	std::cout << "Easyfind demo with list:" << std::endl;
	listFindDemo();
	std::cout << "Easyfind demo with set:" << std::endl;
	setFindDemo();
}
