/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:46:20 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 18:12:12 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


Base * generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}

void classFuncTests() {
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	a->aaa();
	a->bbb();
	b->aaa();
	b->bbb();
	c->aaa();
	c->bbb();

	std::cout << "Identifying classes by pointer:" << std::endl;
	std::cout << "a: ";
	identify(a);
	std::cout << "b: ";
	identify(b);
	std::cout << "c: ";
	identify(c);
	std::cout << "Identifying classes by reference:" << std::endl;
	std::cout << "a: ";
	identify(*a);
	std::cout << "b: ";
	identify(*b);
	std::cout << "c: ";
	identify(*c);
	delete a;
	delete b;
	delete c;
}

int main() {
	srand(time(NULL));
	classFuncTests();

	std::cout << "Generating a random Base instance:" << std::endl;
	Base* instance = generate();
	std::cout << "Identifying the generated instance using pointer:" << std::endl;
	identify(instance);
	std::cout << "Identifying the generated instance using reference:" << std::endl;
	identify(*instance);
	delete instance;
	return 0;
}