#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic") {
	std::cout << "Default constrctor called for Generic WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	this->type = src.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal making generic sound, if there is sucha a thing" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
