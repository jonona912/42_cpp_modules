#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5),
	_target("Empty Space") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("Presidential Pardon Form", 25, 5),
	_target(target)
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

// You must check that the form is signed and that the grade of the bureaucrat
// attempting to execute the form is high enough. Otherwise, throw an appropriate exception.

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	try {
		checkExecutionRights(executor);
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		std::cout << "Presidential Pardon was executed by " << executor.getName() << " for " << this->_target << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Presidential Pardon Execution failed for " << executor.getName() << ": " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, PresidentialPardonForm const &PPForm) {
	// Call the base class operator<< through static_cast to avoid infinite recursion
	out << static_cast<AForm const&>(PPForm) << ", Target: " << PPForm.getTarget();
	return out;
}
