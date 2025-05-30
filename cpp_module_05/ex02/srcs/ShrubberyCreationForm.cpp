/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:50:27 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 18:11:29 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("Shrubbery Form", 145, 137),
	_target(target)
{
	writeTreeToFile(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
	AForm(other),
	_target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try {
		checkExecutionRights(executor);
		writeTreeToFile(this->_target);
		std::cout << "Shrubbery was executed by " << executor.getName() << " named " << this->_target << " file" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Shrubbery Execution failed for " << executor.getName() << ": " << e.what() << std::endl;
	}
}

void ShrubberyCreationForm::writeTreeToFile(std::string const &target) const {
	std::ofstream file((target + "_shrubbery").c_str());
	if (file.is_open()) {
		file << "       _-_\n"
				"    /~~   ~~\\\n"
				" /~~   ASCI   ~~\\\n"
				"{      tree     }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\\n";
		file.close();
	}
	else
		std::cerr << "Failed to create shrubbery file for target: " << target << std::endl;
}


std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm const &SCForm) {
	out << static_cast<AForm const&>(SCForm) << ", Target " << SCForm.getTarget();
	return out;
}
