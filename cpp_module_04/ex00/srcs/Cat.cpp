/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:28:10 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/26 11:28:10 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat Constructor called for " << this->type << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type) {
	std::cout << "Cat Constructor called for " << type << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat Copy Constructor called" << std::endl;
    *this = src;
}

Cat& Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->type << " is meowing" << std::endl;
}
