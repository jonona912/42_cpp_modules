/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:28:10 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/26 14:52:34 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat Constructor called for " << this->type << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const std::string &type) : Animal(type) {
	std::cout << "Cat Constructor called for " << type << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain(*(src._brain));
	*this = src;
}

Cat& Cat::operator=(const Cat &rhs) {
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
	std::cout << "Cat Copy Assignment Called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->type << " is meowing" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
