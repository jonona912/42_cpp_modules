#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &src);// copy constructor
	ScavTrap& operator=(const ScavTrap &rhs);// assignment constructor
	void guardGate();
};

#endif