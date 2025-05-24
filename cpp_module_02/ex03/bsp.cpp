/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:02:50 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 12:02:51 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <cmath>
float hypotenuse_form_x_y(Point const a, Point const b) {
	Point aDiffB = a - b;
	float xSqrd = aDiffB.getX().toFloat() * aDiffB.getX().toFloat();
	float ySqrd = aDiffB.getY().toFloat() * aDiffB.getY().toFloat();
	float hypotenuse = sqrt(xSqrd + ySqrd);

	return hypotenuse;
}

float triangleArea(Point const a, Point const b, Point const c) {
	float sideA = hypotenuse_form_x_y(a, b);
	float sideB = hypotenuse_form_x_y(b, c);
	float sideC = hypotenuse_form_x_y(a, c);
	float semiPerimeter = (sideA + sideB + sideC) / 2;
	float area = sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
	return (area);
}


bool bsp( Point const a, Point const b, Point const c, Point const point){
	float abcArea = triangleArea(a, b, c);
	float acPointArea = triangleArea(a, c, point);
	float abPointArea = triangleArea(a, b, point);
	float bcPointArea = triangleArea(b, c, point);
	float totalPointArea = acPointArea + abPointArea + bcPointArea;
	Fixed const totalPointAreaFixed(totalPointArea);
	Fixed const abcAreaFixed(abcArea);
	if (totalPointAreaFixed != abcAreaFixed) {
		std::cout << "The point is outside the triangle." << std::endl;
		return false;
	}
	std::cout << "The point is inside the triangle." << std::endl;
	return true;
}
