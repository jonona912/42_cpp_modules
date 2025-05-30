/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:44:15 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 08:48:13 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

void printColored(const std::string& message, const std::string& color) {
	std::cout << color << message << "\033[0m" << std::endl;
}

void waitForEnter(const std::string& message) {
	std::cout << message << " Press Enter to continue..." << std::endl;
	std::cin.get();
}

void executeTryCatch(AForm &form, Bureaucrat &br) {
	try {
		form.execute(br);
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}


