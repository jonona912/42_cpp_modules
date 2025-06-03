/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:40:47 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 20:48:41 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>

void listFindDemo() {
	std::list<int> strArr;
	strArr.push_back(1);
	strArr.push_back(2);
	strArr.push_back(3);
	strArr.push_back(4);
	strArr.push_back(5);
	easyfind(strArr, 5);
	try {
		easyfind(strArr, 6);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void easyfindDemo() {
	std::vector<int> intArr;
	intArr.push_back(1);
	intArr.push_back(2);
	intArr.push_back(3);
	intArr.push_back(4);
	intArr.push_back(5);
	try {
		easyfind(intArr, 3);
		easyfind(intArr, 6); // This will throw an exception
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void setFindDemo() {
	std::set<int> intSet;
	intSet.insert(1);
	intSet.insert(2);
	intSet.insert(3);
	intSet.insert(4);
	intSet.insert(5);
	try {
		easyfind(intSet, 3);
		easyfind(intSet, 6); // This will throw an exception
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
