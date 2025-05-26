#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog Constructor called for " << this->type << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type) {
	std::cout << "Dog Constructor called for " << type << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Copy Constructor called" << std::endl;
    *this = src;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->type << " is barking" << std::endl;
}
 