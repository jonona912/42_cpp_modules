#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("StdBureaucrat"), _grade(150) {
	// std::cout << "Default constructor for " << _name << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name), _grade(grade) {
	checkGrade(grade);
	// std::cout << "Constructor called for " << this->_name << " grade " << this->_grade << std::endl;;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	// std::cout << "Copy constructor called for " << this->_name << " grade " << this->_grade << std::endl;;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	checkGrade(_grade - 1);
	this->_grade--;
	std::cout << "Grade incremented to " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade() {
	checkGrade(_grade + 1);
	this->_grade++;
	std::cout << "Grade decremented to " << this->_grade << std::endl;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		if (form.getSignStatus())
			std::cout << "Form already signed" << std::endl;
		else {
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() 
				<< " because " << e.what() << std::endl;
	}
}

// void Bureaucrat::executeForm(AForm const &form) const {
// 	try {
// 		form.execute(*this);
// 	}
// 	catch (std::exception &e) {
// 		std::cout << "Execute From: " << e.what() << std::endl;
// 	}
// }

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->_name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::checkGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw () {
	return "Grade is too high. (Grade must be >= 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low. (Grade must be <= 150)";
}
