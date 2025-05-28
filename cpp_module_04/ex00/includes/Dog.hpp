#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const std::string &type);
	~Dog();
	Dog(const Dog &src);
	Dog& operator=(const Dog &rhs);
	void makeSound() const;
};

#endif
