/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:41:18 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/22 13:41:19 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
	_fpNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	_fpNum = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_fpNum = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw) {
	_fpNum = raw;
}

int const Fixed::_fracBits = 8;
