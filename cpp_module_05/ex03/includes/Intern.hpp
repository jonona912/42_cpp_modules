#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(Intern const &other);
	Intern& operator=(Intern const &other);
	AForm *makeForm(std::string const &formName, std::string const &formTarget);
private:
	struct _FormType {
		std::string name;
		AForm* (*create)(const std::string&);
	};
	static const _FormType	_formTypes[];
	int						_formNum;
};
