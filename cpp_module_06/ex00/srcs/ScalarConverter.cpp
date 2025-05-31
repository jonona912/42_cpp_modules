/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:36:37 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 16:34:54 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "mainHeader.hpp"

#include <iostream>
#include <climits>
#include <cstdlib>
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {

	return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(std::string const &str) {
	str_type type = getType(str);
	switch (type) {
		case TYPE_CHAR: {
			char c = str[0];
			printCharConversions(c);
			break;
		}
		case TYPE_INT: {
			int i = atoi(str.c_str());
			printIntConversions(i);
			break;
		}
		case TYPE_FLOAT: {
			std::string tmp = str;
			if (str.length() > 0 && str[str.length() - 1] == 'f')
				tmp = str.substr(0, str.length() - 1);
			float f = static_cast<float>(atof(tmp.c_str()));
			printFloatConversions(f);
			break;
		}
		case TYPE_DOUBLE: {
			double d = atof(str.c_str());
			printDoubleConversions(d);
			break;
		}
		default:
			printInvalidType();
			break;
	}
}
