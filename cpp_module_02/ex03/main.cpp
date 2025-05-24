/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:41:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 12:02:57 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

int main(void) {
    Point a(0.26f, 0.53f);
    Point b(1.67f, 0.67f);
    Point c(1.29f, 2.57f);
    Point check(1.29f, 2.1f);
    bool isInside = bsp(a, b, c, check);
    std::cout << "Inside: " << isInside << std::endl;
    Point outside(1.32f, 2.65f);
    isInside = bsp(a, b, c, outside);
    std::cout << "Outside: " << isInside << std::endl;
    Point onEdge(1.29f, 2.57f);
    isInside = bsp(a, b, c, onEdge);
    std::cout << "On Edge: " << isInside << std::endl;
    Point onVertex(0.26f, 0.53f);
    isInside = bsp(a, b, c, onVertex);
    std::cout << "On Vertex: " << isInside << std::endl;
    Point negativePoint(-1.0f, -1.0f);
    isInside = bsp(a, b, c, negativePoint);
    std::cout << "Negative Point: " << isInside << std::endl;
    Point largePoint(1000.0f, 1000.0f);
    isInside = bsp(a, b, c, largePoint);
    std::cout << "Large Point: " << isInside << std::endl;
    Point zeroPoint(0.0f, 0.0f);
    isInside = bsp(a, b, c, zeroPoint);
    std::cout << "Zero Point: " << isInside << std::endl;
    Point closePoint(1.29f, 2.580f);
    isInside = bsp(a, b, c, closePoint);
    std::cout << "Close Point: " << isInside << std::endl;
    Point anotherInsidePoint(1.53, 1.05);
    isInside = bsp(a, b, c, anotherInsidePoint);
    std::cout << "Another Inside Point: " << isInside << std::endl;
    return (0);
}
