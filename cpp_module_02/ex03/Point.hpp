/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:03:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 12:03:08 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float a, const float b);
	Point(const Point& src);
	Point& operator=(const Point& rhs);
	Point operator-(const Point& rhs) const;
	~Point(void);
	Fixed const getX(void) const;
	Fixed const getY(void) const;
private:
	Fixed const _x;
	Fixed const _y;
};


#endif
