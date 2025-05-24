#include "HumanB.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {
}


void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() const {
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
	else
	std::cout << this->_name << " attacks with their bare hands because they don't have a weapon" << std::endl;
}
