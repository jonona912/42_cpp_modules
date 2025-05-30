#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string const &name, int const &signGrade, int const &execGrade) :
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

AForm::~AForm() {};

AForm::AForm(AForm const &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	checkGrade(other._signGrade);
	checkGrade(other._execGrade);
}

AForm& AForm::operator=(AForm const &other) {
	if (this != &other)
		this->_isSigned = 0;
	return *this;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSignStatus() const {
	return this->_isSigned;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExecGrade() const {
	return this->_execGrade;
}

void AForm::beSigned(Bureaucrat const &br) {
	if (br.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	try {
		checkExecutionRights(executor);
		std::cout << executor.getName() << " executed " << this->getName() << " form" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Execution failed for " << executor.getName() << ": " << e.what() << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw() {
		return "Form Not Signed";
}

void AForm::checkGrade(int const &grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

void AForm::checkExecutionRights(Bureaucrat const &executor) const {
	if (!this->getSignStatus())
		throw FormNotSignedException();
	else if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, AForm const &Aform) {
	out << "AForm: " << Aform.getName()
		<< ", Sign grade: " << Aform.getSignGrade()
		<< ", Execution grade: " << Aform.getExecGrade()
		<< ", Status: ";
	if (Aform.getSignStatus())
		out << "Signed";
	else
		out << "Not Signed";
	return out;
}
