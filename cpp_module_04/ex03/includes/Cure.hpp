#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(std::string const &type);
	~Cure();
	Cure(const Cure &src);
	Cure& operator=(const Cure &rhs);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
