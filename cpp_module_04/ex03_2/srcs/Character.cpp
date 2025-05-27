#include "Character.hpp"

#include <iostream>

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	// std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	// std::cout << "Character Constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
	// std::cout << "Character Destructor called" << std::endl;
}

Character::Character(Character const &src) : _name(src._name) {
    // Initialize inventory to NULL first
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    
    // Deep copy using clone
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i] != NULL) {
            _inventory[i] = src._inventory[i]->clone();
        }
    }
    // std::cout << "Character Copy Constructor called" << std::endl;
}

Character& Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        
        // Clean up existing inventory
        for (int i = 0; i < 4; i++) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
        
        // Deep copy using clone
        for (int i = 0; i < 4; i++) {
            if (rhs._inventory[i] != NULL) {
                _inventory[i] = rhs._inventory[i]->clone();
            }
        }
    }
    // std::cout << "Character Assignment Operator called" << std::endl;
    return *this;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "No mataria given" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			// std::cout << "Equiped materia " << m->getType() << " at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory full" << std::endl;
}


void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (this->_inventory[idx]) {
		// std::cout << "Uniquiped inventory: " << this->_inventory[idx]->getType() << std::endl;
		this->_inventory[idx] = NULL;
		return;
	}
	std::cout << "Nothing to unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Inventory index out of range" << std::endl;
		return;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Weapon to use" << std::endl;
	// this->_inventory[idx].use(target);
}
