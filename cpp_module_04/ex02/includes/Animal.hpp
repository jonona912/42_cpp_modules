#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	Animal();
	Animal(const std::string type);
	Animal(const Animal &src);
	Animal& operator=(const Animal &rhs);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
protected:
	std::string type;
};

#endif // ANIMAL_HPP
