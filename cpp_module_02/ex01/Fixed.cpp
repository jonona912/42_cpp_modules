/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:41:18 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/22 21:50:09 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
	_fpNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _fpNum(num << _fracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fNum) : _fpNum(roundf(fNum * (1 << _fracBits))) {
	std::cout << "Float constructor called" << std::endl;
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
	std::cout.flush();
	if (this != &rhs) {
		_fpNum = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fpNum);
}

void Fixed::setRawBits(int const raw) {
	_fpNum = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(_fpNum) / (1 << _fracBits));
}

int Fixed::toInt(void) const {
	return (_fpNum >> _fracBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& src) {
	out << src.toFloat();
	return out;
}

int const Fixed::_fracBits = 8;
