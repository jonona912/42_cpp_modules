#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	for (int i = 0; i < 4; ++i) {
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; ++i) {
			delete _materias[i];
			if (rhs._materias[i])
				_materias[i] = rhs._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "Cannot learn a null materia." << std::endl;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (!_materias[i]) {
			_materias[i] = m;
			std::cout << "Learned materia: " << m->getType() << " at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Materia source is full, cannot learn " << m->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; ++i) {
		if (_materias[i] && _materias[i]->getType() == type) {
			std::cout << "Creating materia: " << type << " at index " << i << std::endl;
			return _materias[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}
