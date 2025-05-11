#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {
	this->_type = weapon;
}

Weapon::~Weapon() {
}

std::string const Weapon::getType() const {
	return (this->_type);
}

void Weapon::setType(std::string weapon) {
	this->_type = weapon;
}



