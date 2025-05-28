#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice was constructed" << std::endl;
}

Ice::~Ice() {}

Ice::Ice(const Ice &src) : AMateria(src._type) {
	// std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &rhs) {
	this->_type = rhs._type;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}
