/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:07:03 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 16:34:51 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

str_type getType(std::string const &str) {
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])) {
		return TYPE_CHAR;
	}
	if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff" || str == "nan") {
		return TYPE_FLOAT;
	}
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
		if (isprint(str[1]) && !isdigit(str[1])) {
			return TYPE_CHAR;
		} else {
			return TYPE_INVALID;
		}
	}
	if (str.length() == 0 || (str.length() == 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
		return TYPE_INVALID;
	}
	if (str[0] == '-' || str[0] == '+') {
		if (str.length() == 1) {
			return TYPE_INVALID;
		}
	}
	if (str.find_first_not_of("0123456789.-+f") != std::string::npos) {
		return TYPE_INVALID;
	}
	if (str.find('.') != std::string::npos && str.find('f') != std::string::npos) {
		if (str[str.length() - 1] == 'f')
		{
			return TYPE_FLOAT;
		} else {
			return TYPE_INVALID;
		}
	}
	if (str.find('.') != std::string::npos && str.find('f') == std::string::npos) {
		return TYPE_DOUBLE;
	}
	if (str.find('f') != std::string::npos && str[str.length() - 1] != 'f') {
		return TYPE_INVALID;
	}
	if (str.find_first_not_of("0123456789") == std::string::npos) {
		return TYPE_INT;
	}
	return TYPE_INVALID;
}

void printCharConversions(char c) {
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void printIntConversions(int i) {
	std::cout << "char: ";
	if (i >= 32 && i <= 126)
		std::cout << "'" << static_cast<char>(i) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void printFloatConversions(float f) {
	std::cout << "char: ";
	if (f >= 32 && f <= 126)
		std::cout << "'" << static_cast<char>(f) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
		std::cout << static_cast<int>(f) << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void printDoubleConversions(double d) {
	std::cout << "char: ";
	if (d >= 32 && d <= 126)
		std::cout << "'" << static_cast<char>(d) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
		std::cout << static_cast<int>(d) << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}

void printInvalidType() {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}
