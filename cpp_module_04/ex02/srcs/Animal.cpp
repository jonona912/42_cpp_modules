/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:28:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/26 15:50:12 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Generic") {
	std::cout << "Default constrctor called for Generic Animal" << std::endl;
}

Animal::Animal(const std::string type) : type(type) {
	std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	this->type = src.type;
}

Animal& Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}
