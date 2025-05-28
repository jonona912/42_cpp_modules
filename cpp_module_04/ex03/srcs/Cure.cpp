#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure was constructed" << std::endl;
}

Cure::~Cure() {}

Cure::Cure(const Cure &src) : AMateria(src._type) {
	// std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &rhs) {
	this->_type = rhs._type;
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
