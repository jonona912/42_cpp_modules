#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
    ClapTrap("default_clap_name"),
    FragTrap("default_frag_name"),
    ScavTrap("default_scav_name"),
    _name("default_diamond_name") {
    std::cout << "Diamond Trap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	_name(name) {
	std::cout << "Diamond Trap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond Trap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl; // scope resolution operator.
}

void DiamondTrap::attack(const std::string& target) {
	FragTrap::attack(target);
}
