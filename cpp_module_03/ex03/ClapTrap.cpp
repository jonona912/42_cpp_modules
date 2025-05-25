/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:37:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/25 18:58:25 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define HIT_POINTS 100
#define ENERGY_POINTS 50
#define ATTACK_DAMAGE 30

ClapTrap::ClapTrap() :
	_name("Default"),
	_hitPts(HIT_POINTS),
	_energyPts(ENERGY_POINTS),
	_attackDmg(ATTACK_DAMAGE)
{
	std::cout << "Default ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) :
	_name(name),
	_hitPts(HIT_POINTS),
	_energyPts(ENERGY_POINTS),
	_attackDmg(ATTACK_DAMAGE)
{
	std::cout << "ClapTrap Constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : 
    _name(src._name),
    _hitPts(src._hitPts),
    _energyPts(src._energyPts),
    _attackDmg(src._attackDmg) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPts > 0 && this->_energyPts > 0) {
		std::cout << this->_name << " attacks " << target
		<< ", causing " << this->_attackDmg << " points of damage!"
		<< std::endl;
		this->_energyPts--;
	}
	else
		std::cout << "No energy points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPts > 0) {
		std::cout << _name << " repaired by " << amount << std::endl;
		this->_hitPts+= amount;
		this->_energyPts--;
	}
	else
		std::cout << "No energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_energyPts > 0) {
		std::cout << this->_name << " took " << amount << " damage" << std::endl;
		if (this->_energyPts >= amount)
			this->_energyPts -= amount;
		else
			this->_energyPts = 0;
	}
	else
		std::cout << "No energy point left to absorb damage" << std::endl;
}
