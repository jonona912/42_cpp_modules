#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::~Ice() {}

Ice::Ice(const Ice &src) : AMateria(src._type) {}

Ice& Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
