#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie( std::string name ) {
	this->_name = name;
	std::cout << this->_name << " object created" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " object destroyed " << std::endl;
}

void Zombie::anounce ( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
