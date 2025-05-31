#include "Base.hpp"
#include <iostream>

Base::~Base() {}

void Base::aaa() {
	std::cout << "Base aaa called" << std::endl;
}

void Base::bbb() {
	std::cout << "Base bbb called" << std::endl;
}
