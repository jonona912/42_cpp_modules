/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:33:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 11:55:12 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

void subjectDemo() {
	// Test with MutantStack
	std::cout << "=== Testing with MutantStack ===" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Elements:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void listDemo() {
	// Test with std::list
	std::cout << "\n=== Testing with std::list ===" << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Top: " << lst.back() << std::endl;
	
	lst.pop_back();
	std::cout << "Size after pop: " << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	
	++it;
	--it;
	*it = 42; // Modify the first element
	
	std::cout << "Elements:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}


int main(void) {
	std::cout << "\033[33mSubject Test\033[0m" << std::endl;
	subjectDemo();
	std::cout << "\033[33mList Test\033[0m" << std::endl;
	listDemo();
	// MutantStack<int> s;
	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(3);
	// s.push(2);
	// s.printTop(); // Outputs: Top element: 2
	// s.pop();
	// s.printTop(); // Outputs: Top element: 3
	// s.pop();
	// s.printTop(); // Outputs: Top element: 3
	// s.pop();
	// s.printTop(); // Outputs: Top element: 2
	// MutantStack<int>::iterator it = s.begin();
	return 0;
}
