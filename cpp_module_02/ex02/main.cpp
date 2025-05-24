/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:41:14 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 12:09:23 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
// Color constants for test output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(void) {
    std::cout << BLUE << "\n===== SUBJECT REQUIRED TESTS =====" << RESET << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    std::cout << BLUE << "\n===== ARITHMETIC OPERATOR TESTS =====" << RESET << std::endl;
    Fixed c(10);
    Fixed d(2.5f);
    
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    
    // Test addition
    Fixed add_result = c + d;
    float expected_add = 12.5f;
    bool add_test = (std::abs(add_result.toFloat() - expected_add) < 0.01f);
    std::cout << "c + d = " << add_result << " (expecting " << expected_add << ") ";
    std::cout << (add_test ? GREEN : RED) << (add_test ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test subtraction
    Fixed sub_result = c - d;
    float expected_sub = 7.5f;
    bool sub_test = (std::abs(sub_result.toFloat() - expected_sub) < 0.01f);
    std::cout << "c - d = " << sub_result << " (expecting " << expected_sub << ") ";
    std::cout << (sub_test ? GREEN : RED) << (sub_test ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test multiplication
    Fixed mul_result = c * d;
    float expected_mul = 25.0f;
    bool mul_test = (std::abs(mul_result.toFloat() - expected_mul) < 0.01f);
    std::cout << "c * d = " << mul_result << " (expecting " << expected_mul << ") ";
    std::cout << (mul_test ? GREEN : RED) << (mul_test ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test division
    Fixed div_result = c / d;
    float expected_div = 4.0f;
    bool div_test = (std::abs(div_result.toFloat() - expected_div) < 0.01f);
    std::cout << "c / d = " << div_result << " (expecting " << expected_div << ") ";
    std::cout << (div_test ? GREEN : RED) << (div_test ? "PASS" : "FAIL") << RESET << std::endl;
    
    std::cout << BLUE << "\n===== COMPARISON OPERATOR TESTS =====" << RESET << std::endl;
    Fixed e(5);
    Fixed f(5.0f);
    Fixed g(10);
    
    std::cout << "e: " << e << " (5)" << std::endl;
    std::cout << "f: " << f << " (5.0f)" << std::endl;
    std::cout << "g: " << g << " (10)" << std::endl;
    
    // Test equality operator (==)
    bool eq_test1 = (e == f);
    bool eq_test2 = (e == g);
    std::cout << "e == f: " << (eq_test1 ? "true" : "false") << " (expecting true) ";
    std::cout << (eq_test1 ? GREEN : RED) << (eq_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "e == g: " << (eq_test2 ? "true" : "false") << " (expecting false) ";
    std::cout << (!eq_test2 ? GREEN : RED) << (!eq_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test inequality operator (!=)
    bool neq_test1 = (e != f);
    bool neq_test2 = (e != g);
    std::cout << "e != f: " << (neq_test1 ? "true" : "false") << " (expecting false) ";
    std::cout << (!neq_test1 ? GREEN : RED) << (!neq_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "e != g: " << (neq_test2 ? "true" : "false") << " (expecting true) ";
    std::cout << (neq_test2 ? GREEN : RED) << (neq_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test greater than operator (>)
    bool gt_test1 = (g > e);
    bool gt_test2 = (e > g);
    std::cout << "g > e: " << (gt_test1 ? "true" : "false") << " (expecting true) ";
    std::cout << (gt_test1 ? GREEN : RED) << (gt_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "e > g: " << (gt_test2 ? "true" : "false") << " (expecting false) ";
    std::cout << (!gt_test2 ? GREEN : RED) << (!gt_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test less than operator (<)
    bool lt_test1 = (e < g);
    bool lt_test2 = (g < e);
    std::cout << "e < g: " << (lt_test1 ? "true" : "false") << " (expecting true) ";
    std::cout << (lt_test1 ? GREEN : RED) << (lt_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "g < e: " << (lt_test2 ? "true" : "false") << " (expecting false) ";
    std::cout << (!lt_test2 ? GREEN : RED) << (!lt_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test greater than or equal operator (>=)
    bool ge_test1 = (e >= f);
    bool ge_test2 = (g >= e);
    bool ge_test3 = (e >= g);
    std::cout << "e >= f: " << (ge_test1 ? "true" : "false") << " (expecting true) ";
    std::cout << (ge_test1 ? GREEN : RED) << (ge_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "g >= e: " << (ge_test2 ? "true" : "false") << " (expecting true) ";
    std::cout << (ge_test2 ? GREEN : RED) << (ge_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "e >= g: " << (ge_test3 ? "true" : "false") << " (expecting false) ";
    std::cout << (!ge_test3 ? GREEN : RED) << (!ge_test3 ? "PASS" : "FAIL") << RESET << std::endl;
    
    // Test less than or equal operator (<=)
    bool le_test1 = (e <= f);
    bool le_test2 = (e <= g);
    bool le_test3 = (g <= e);
    std::cout << "e <= f: " << (le_test1 ? "true" : "false") << " (expecting true) ";
    std::cout << (le_test1 ? GREEN : RED) << (le_test1 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "e <= g: " << (le_test2 ? "true" : "false") << " (expecting true) ";
    std::cout << (le_test2 ? GREEN : RED) << (le_test2 ? "PASS" : "FAIL") << RESET << std::endl;
    std::cout << "g <= e: " << (le_test3 ? "true" : "false") << " (expecting false) ";
    std::cout << (!le_test3 ? GREEN : RED) << (!le_test3 ? "PASS" : "FAIL") << RESET << std::endl;
    
    std::cout << BLUE << "\n===== MIN/MAX FUNCTION TESTS =====" << RESET << std::endl;
    std::cout << "Fixed::min(e, g): " << Fixed::min(e, g) << " (expecting 5) ";
    std::cout << (Fixed::min(e, g) == e ? GREEN : RED) << (Fixed::min(e, g) == e ? "PASS" : "FAIL") << RESET << std::endl;
    
    std::cout << "Fixed::max(e, g): " << Fixed::max(e, g) << " (expecting 10) ";
    std::cout << (Fixed::max(e, g) == g ? GREEN : RED) << (Fixed::max(e, g) == g ? "PASS" : "FAIL") << RESET << std::endl;
    
    const Fixed h(7);
    const Fixed i(3);
    std::cout << "Fixed::min(const h, const i): " << Fixed::min(h, i) << " (expecting 3) ";
    std::cout << (Fixed::min(h, i) == i ? GREEN : RED) << (Fixed::min(h, i) == i ? "PASS" : "FAIL") << RESET << std::endl;
    
    std::cout << "Fixed::max(const h, const i): " << Fixed::max(h, i) << " (expecting 7) ";
    std::cout << (Fixed::max(h, i) == h ? GREEN : RED) << (Fixed::max(h, i) == h ? "PASS" : "FAIL") << RESET << std::endl;

    return 0;
}