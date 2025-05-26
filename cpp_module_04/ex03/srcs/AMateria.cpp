#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &src) : _type(src._type) {}

AMateria& AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}
