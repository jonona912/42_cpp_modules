#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type) {
	// std::cout << "Amateria constructor called for " << _type << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMAteria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src) : _type(src._type) {
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const &rhs) {
	this->_type = rhs._type;
	// std::cout << "AMateria assignment constructor called" << std::endl;
	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Default materia used on " << target.getName() << std::endl;
}
