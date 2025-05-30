/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:07:31 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 18:08:57 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> 
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robot Request Form", 72, 45),
	_target("Standard Robot") 
{}

RobotomyRequestForm::~RobotomyRequestForm() {};


RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("Robot Request Form", 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm created for target: " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
	AForm(other),
	_target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	try {
		checkExecutionRights(executor);
		std::cout << "* DRILLING NOISES *" << std::endl;
		if (getRandomBool()) {
			std::cout << this->_target << " has been successfully robotomized!" << std::endl;
		} else {
			std::cout << "The robotomy of " << this->_target << " failed!" << std::endl;
		}
	}
	catch(std::exception &e) {
		std::cout << executor.getName() << " couldn't execute because " << e.what() << std::endl;
	}
}

bool RobotomyRequestForm::getRandomBool() const {
	static bool initialized = false;
	if (!initialized) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		initialized = true;
	}
	return (std::rand() % 2) == 0;
}

const char* RobotomyRequestForm::RobomizationFailedException::what() const throw() {
	return "Could not Robotomize";
}

std::ostream& operator<<(std::ostream &out, RobotomyRequestForm const &RRForm) {
	out << static_cast<AForm const&>(RRForm) << ", Target " << RRForm.getTarget();
	return out;
}
