#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() {
	// this->_name = name; // _name (name) -> member initializer list
	std::cout << "zombie object created" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " object destroyed " << std::endl;
}

void Zombie::anounce ( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
