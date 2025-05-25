#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	~DiamondTrap();
	void whoAmI();
	void attack(const std::string& target);
private:
	std::string _name;
};



#endif