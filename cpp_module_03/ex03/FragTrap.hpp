#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string name);
	~FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap& operator=(const FragTrap &rhs);
	void highFivesGuys(void);
};

#endif