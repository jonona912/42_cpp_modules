#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string const &name, int const &signGrade, int const &execGrade) :
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

Form::~Form() {};

Form::Form(Form const &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	checkGrade(other._signGrade);
	checkGrade(other._execGrade);
}

Form& Form::operator=(Form const &other) {
	if (this != &other)
		this->_isSigned = 0;
	return *this;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSignStatus() const {
	return this->_isSigned;
}

int Form::getSignGrade() const {
	return this->_signGrade;
}

int Form::getExecGrade() const {
	return this->_execGrade;
}

void Form::beSigned(Bureaucrat const &br) {
	if (br.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

void Form::checkGrade(int const &grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, Form const &form) {
	out << "Form: " << form.getName()
		<< ", Sign grade: " << form.getSignGrade()
		<< ", Execution grade: " << form.getExecGrade()
		<< ", Status: ";
	if (form.getSignStatus())
		out << "Signed";
	else
		out << "Not Signed";
	return out;
}
