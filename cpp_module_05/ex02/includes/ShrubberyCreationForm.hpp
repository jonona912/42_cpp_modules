#pragma once

#include "AForm.hpp"

#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &other);
	virtual void		execute(Bureaucrat const & executor) const;
	std::string			getTarget() const;
private:
	std::string const _target;
	void				writeTreeToFile(std::string const &target) const;
};

std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm const &SCForm);
