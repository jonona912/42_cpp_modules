#include "main.hpp"

#include <iostream>

int main( void ) {
	int		n = 12;
	Zombie *zHorde = zombieHorde(n, "BeMaghz");
	for (int i = 0; i < n; i++) {
		zHorde[i].anounce();
	}
	delete [] zHorde;
	return (0);
}
