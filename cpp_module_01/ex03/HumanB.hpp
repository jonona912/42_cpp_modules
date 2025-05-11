#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP


#include "Weapon.hpp"
#include <string>

class HumanB {
public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon &weapon);
	void	attack() const;
private:
	std::string	_name;
	Weapon		*_weapon;
};


#endif