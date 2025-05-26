#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal& operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
protected:
	std::string type;
};

#endif // WRONG_ANIMAL_HPP
