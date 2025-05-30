#pragma once
#ifndef A_FORM_HPP
#define A_FORM_HPP



class Bureaucrat; // because of circular dependency issue
#include <string>
#include <iostream>

class AForm {
public:
	AForm();
	AForm(std::string const &name, int const &signGrade, int const &execGrade);
	virtual ~AForm();
	AForm(AForm const &other);
	AForm& operator=(AForm const &other);
	virtual std::string	getName() const;
	virtual int			getSignGrade() const;
	virtual int			getExecGrade() const;
	virtual bool		getSignStatus() const;
	virtual void		beSigned(Bureaucrat const &br); //If the grade is too low, throw a AForm::GradeTooLowException.
	virtual void		execute(Bureaucrat const & executor) const;
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		virtual char const *what() const throw();
	};

protected:
	void				checkExecutionRights(Bureaucrat const &executor) const;
private:
	std::string const	_name;
	bool				_isSigned;
	int	const			_signGrade;
	int	const			_execGrade;
	void				checkGrade(int const &grade);
};

std::ostream& operator<<(std::ostream &out, AForm const &Aform);

#endif
