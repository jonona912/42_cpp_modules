#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::~Cure() {}

Cure::Cure(const Cure &src) : AMateria(src._type) {}

Cure& Cure::operator=(const Cure &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
