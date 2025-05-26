#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name) {
	for (int i = 0; i < 4; ++i) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_inventory[idx]) {
		std::cout << "Invalid index or no materia to unequip at index " << idx << std::endl;
		return;
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !_inventory[idx]) {
		std::cout << "Invalid index or no materia to use at index " << idx << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
