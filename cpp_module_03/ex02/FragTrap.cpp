#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap Copy assignment constructor called" << std::endl; 
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << _name << " searching for people to give high five to" << std::endl;
}
