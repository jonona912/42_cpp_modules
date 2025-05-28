#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat Constructor called for " << this->type << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type) {
	std::cout << "WrongCat Constructor called for " << type << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = src;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << this->type << " is meowing" << std::endl;
}
