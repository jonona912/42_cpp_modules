#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
private:
	AMateria *_learnedMaterias[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &src);
	MateriaSource& operator=(MateriaSource const &rhs);

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif