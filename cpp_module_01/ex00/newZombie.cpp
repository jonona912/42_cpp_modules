#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name ) {
	Zombie *ret = new Zombie( name );
	return (ret);
}

