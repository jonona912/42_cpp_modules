#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog Constructor called for " << this->type << std::endl;
	this->_brain = new Brain;
}

Dog::Dog(const std::string &type) : Animal(type) {
	std::cout << "Dog Constructor called for " << type << std::endl;
	this->_brain = new Brain;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_brain = new Brain(*(src._brain));
    *this = src;
}

Dog& Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		if (this->_brain && rhs._brain) {
			*(this->_brain) = *(rhs._brain);
		}
		else if (rhs._brain) {
			this->_brain = new Brain(*(rhs._brain));
		}
		else {
			delete this->_brain;
			this->_brain = NULL;
		}
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->type << " is barking" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}
