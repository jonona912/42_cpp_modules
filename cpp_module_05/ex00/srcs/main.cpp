/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:25:22 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/29 15:00:48 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

void createBureucrat(std::string name, int grade) {
	try {
		Bureaucrat br(name, grade);
		std::cout << "Name : " << br.getName() << std::endl;
		std::cout << "Grade: " << br.getGrade() << std::endl;
		std::cout << "Insertion overload: " << br << std::endl;
		std::cout << "\033[35mIncrementing or decreementing\033[0m" << std::endl;
		if (br.getGrade() == 150)
			br.decrementGrade();
		else if (br.getGrade() == 1)
			br.incrementGrade();
		else
			br.incrementGrade();
		std::cout << "------------------------------" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	createBureucrat("FailedTest1", 151);
	createBureucrat("FailedTest2", 0);
	createBureucrat("Success1", 150);
	createBureucrat("Success2", 1);
	createBureucrat("Success2", 2);
	return 0;
}
