#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_learnedMaterias[i] = NULL;
	}
	// std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete this->_learnedMaterias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	for (int i = 0; i < 4; i++) {
		this->_learnedMaterias[i] = src._learnedMaterias[i];
	}
	// std::cout << "MateriaSource Copy Constructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "Invalid materia. Cannot learn" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_learnedMaterias[i] == NULL) {
			this->_learnedMaterias[i] = m;
			// std::cout << "Materia Learned " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Memory full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_learnedMaterias[i] && this->_learnedMaterias[i]->getType() == type) {
			// std::cout << "Cloned materia: " << _learnedMaterias[i]->getType() << std::endl;
			return _learnedMaterias[i]->clone();
		}
	}
	std::cout << "Did not find matching materia in memmory for: " << type << std::endl;
	return NULL;
}

