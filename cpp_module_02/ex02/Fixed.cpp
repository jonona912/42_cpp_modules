/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:41:18 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 14:09:48 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) {
	_fpNum = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _fpNum(num << _fracBits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fNum) : _fpNum(roundf(fNum * (1 << _fracBits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	// std::cout << "Copy constructor called" << std::endl;
	_fpNum = src.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	std::cout.flush();
	if (this != &rhs) {
		_fpNum = rhs.getRawBits();
	}
	return *this;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    float temp;
    temp = this->toFloat() * rhs.toFloat();
    Fixed result(temp);
    return result;  // Now returns a copy, which is safe
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result((this->toFloat() + rhs.toFloat()));
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result(this->toFloat() - rhs.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	if (rhs.getRawBits() == 0) {
		std::cerr << "Division by zero error" << std::endl;
		throw std::runtime_error("Division by zero");
	}
	Fixed result((this->toFloat() / rhs.toFloat()));
	return (result);
}

bool Fixed::operator<(const Fixed& rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator>(const Fixed& rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed& Fixed::operator++(void) {
	float temp = this->toFloat() + (float) 1 / (1 << _fracBits);
	this->setRawBits(temp * (1 << _fracBits));
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	float set = this->toFloat() + (float) 1 / (1 << _fracBits);
	this->setRawBits(set * (1 << _fracBits));
	return temp;
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

Fixed& Fixed::max(Fixed &l, Fixed &r) {
	if (l.getRawBits() > r.getRawBits())
		return l;
	else
		return r;
}

const Fixed& Fixed::max(const Fixed &l, const Fixed &r) {
	if (l.getRawBits() > r.getRawBits())
		return l;
	else
		return r;
}

Fixed& Fixed::min(Fixed &l, Fixed &r) {
	if (l.getRawBits() < r.getRawBits())
		return l;
	else
		return r;
}

const Fixed& Fixed::min(const Fixed &l, const Fixed &r) {
	if (l.getRawBits() < r.getRawBits())
		return l;
	else
		return r;
}





int const Fixed::_fracBits = 8;
