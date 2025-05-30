#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm& operator=(PresidentialPardonForm const &other);
	std::string getTarget() const;
	void		execute(Bureaucrat const &executor) const;
private:
	std::string	const _target;
};

std::ostream& operator<<(std::ostream &out, PresidentialPardonForm const &PPForm);
