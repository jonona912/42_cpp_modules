/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:25:22 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 19:35:26 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

// void 

void bureaucratExec() {
	Bureaucrat intern("intern", 150);
	Bureaucrat vazir("Vazir", 3);
	PresidentialPardonForm form1("Duzd");
	intern.executeForm(form1);
	std::cout << form1 << std::endl;
	vazir.signForm(form1);
	std::cout << form1 << std::endl;
	intern.executeForm(form1);
	vazir.executeForm(form1);
	form1.execute(vazir);
}

void presidentialPardonFormFuncs() {
	waitForEnter("Ready to test Presidential Form with different grades.");
	testPresidentialFormWithDifferentGrades();

	waitForEnter("Ready to test borderline cases.");
	testBorderlineCases();

	waitForEnter("Ready to test exception handling.");
	testExceptionHandling();
}

void shrubberyDemo() {
	Bureaucrat intern("intern", 150);
	Bureaucrat vazir("Vazir", 3);
	ShrubberyCreationForm shrub1("Butta");
	intern.signForm(shrub1);
	intern.executeForm(shrub1);
	vazir.signForm(shrub1);
	intern.executeForm(shrub1);
	vazir.executeForm(shrub1);
	std::cout << "SHRUBBERY EXECUTION" << std::endl;
	shrub1.execute(vazir);
	shrub1.execute(intern);
	
}

void robotomizeDemo() {
	RobotomyRequestForm rob1("Agar");
	Bureaucrat vazir("Vazir", 3);
	rob1.execute(vazir);
	vazir.signForm(rob1);
	rob1.execute(vazir);
	
}

int main() {
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Bureaucrat intern("intern", 150);
		Bureaucrat vazir("Vazir", 3);
		intern.signForm(*rrf);
		std::cout << *rrf << std::endl;
		vazir.signForm(*rrf);
		std::cout << *rrf << std::endl;
		AForm *shouldBeNull = someRandomIntern.makeForm("Noneexistant", "None");
		std::cout << "NULL: " << shouldBeNull << std::endl;
		delete rrf;
	}
	return 0;
}
