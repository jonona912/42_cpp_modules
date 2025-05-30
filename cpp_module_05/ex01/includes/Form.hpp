#pragma once
#ifndef FORM_HPP
#define FORM_HPP



class Bureaucrat; // because of circular dependency issue
#include <string>
#include <iostream>

class Form {
public:
	Form();
	Form(std::string const &name, int const &signGrade, int const &execGrade);
	~Form();
	Form(Form const &other);
	Form& operator=(Form const &other);
	std::string	getName() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	bool		getSignStatus() const;
	void		beSigned(Bureaucrat const &br); //If the grade is too low, throw a Form::GradeTooLowException.
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const	_name;
	bool				_isSigned;
	int	const			_signGrade;
	int	const			_execGrade;
	void				checkGrade(int const &grade);
};

std::ostream& operator<<(std::ostream &out, Form const &form);

#endif
