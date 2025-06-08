/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:46:24 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 15:57:17 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
	} catch (const RPN::RPNInvalidInputException &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
