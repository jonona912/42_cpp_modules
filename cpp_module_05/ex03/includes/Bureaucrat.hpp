#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int const &grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat& operator=(Bureaucrat const &other);
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(AForm &form);
	void		executeForm(AForm const & form) const;
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw(); 
	};
private:
	std::string const	_name;
	int					_grade;
	void checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
