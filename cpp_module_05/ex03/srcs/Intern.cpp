#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

Intern::Intern(Intern const &other) {
	(void)other;
}

Intern& Intern::operator=(Intern const &other) {
	(void)other;
	return *this;
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

const Intern::_FormType Intern::_formTypes[] = {
	{"shrubbery creation", createShrubbery},
	{"robotomy request", createRobotomy},
	{"presidential pardon", createPresidential}
};

AForm *Intern::makeForm(std::string const &formName, std::string const &formTarget) {
	const size_t formCount = sizeof(_formTypes) / sizeof(_FormType);

	for (size_t i = 0; i < formCount; ++i) {
		if (formName == _formTypes[i].name) {
			AForm* form = _formTypes[i].create(formTarget);
			std::cout << "Intern creates " << formName << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create " << formName << " form: unknown form type" << std::endl;
	return NULL;
}
