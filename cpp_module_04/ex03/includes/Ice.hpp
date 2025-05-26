#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice(std::string const &type);
	~Ice();
	Ice(const Ice &src);
	Ice& operator=(const Ice &rhs);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
