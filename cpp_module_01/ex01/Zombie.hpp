#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie();
	~Zombie( void );
	void setName(std::string name);
	void anounce( void );
private:
	std::string _name;
};

#endif /* ZOMBIE_HPP */