/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:03:04 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 12:03:05 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float a, const float b) : _x(a), _y(b) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point& Point::operator=(const Point &rhs) {
	(void)rhs;
	return *this;
}

Point::~Point(void) {}

Point Point::operator-(const Point &rhs) const {
	Fixed xDiff = this->getX() - rhs.getX();
	Fixed yDiff = this->getY() - rhs.getY();
	Point result(xDiff.toFloat(), yDiff.toFloat());
	return result;
}

Fixed const Point::getX(void) const {
	return(this->_x);
}

Fixed const Point::getY(void) const {
	return (this->_y);
}
