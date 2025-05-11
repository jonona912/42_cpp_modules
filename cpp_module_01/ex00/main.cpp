#include "main.hpp"

#include <iostream>

int main( void ) {
	randomChump("Tasoduf");
	Zombie *testZombie = newZombie( "Besar");
	testZombie->anounce();
	delete testZombie;
	return (0);
}
