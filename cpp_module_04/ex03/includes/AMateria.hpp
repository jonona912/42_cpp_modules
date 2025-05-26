#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
	std::string _type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(const AMateria &src);
	AMateria& operator=(const AMateria &rhs);

	std::string const& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
