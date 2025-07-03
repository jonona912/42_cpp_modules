#include "RPN.hpp"

#include <iostream>
#include <sstream>



RPN::RPN(std::string const &strRPN) : _strRPN(strRPN) {
	// perform check and print error if invalid
	checkForExtChars();
	performCalculations();
}

RPN::~RPN() {}

RPN::RPN(RPN const &other) {
	(void)other; // Suppress unused variable warning
}

const char *RPN::RPNInvalidInputException::what() const throw() {
	return "Error";
}

void RPN::checkForExtChars() const {
	// check if it is only numbers or /*+-
	if (this->_strRPN.find_first_not_of("0123456789*/-+ ") != std::string::npos) {
		throw RPNInvalidInputException();
	}
}

Operation RPN::operationType(std::string const &character) const {
	struct OperationMapping {
		const char* symbol;
		Operation op;
	};
	static const OperationMapping opTable[] = {
		{ "+", ADD },
		{ "-", SUBTRACT },
		{ "*", MULTIPLY },
		{ "/", DIVIDE }
	};

	for (size_t i = 0; i < sizeof(opTable)/sizeof(opTable[0]); ++i) {
		if (character == opTable[i].symbol)
			return opTable[i].op;
	}
	throw RPNInvalidInputException();
}

void RPN::performCalculations() {
	std::string character;
	int			tempNum;
	std::string RPNcpy = this->_strRPN;
	Operation	opType;
	int			a;
	int			b;

	for (size_t i = 0; i < RPNcpy.length(); i++) {
		while (i < RPNcpy.length() && RPNcpy.at(i) == ' ')
			i++;
		if (i >= RPNcpy.length())
			break;
		character = RPNcpy.at(i);
		// std::cout << "seperated char: " << character << std::endl;
		if (std::isdigit(character.at(0))) {
			std::istringstream ss(character);
			ss >> tempNum;
			this->_nums.push(tempNum);
		}
		else if (this->_nums.size() > 1) {
			opType = operationType(character);
			b = this->_nums.top();
			this->_nums.pop();
			a = this->_nums.top();
			this->_nums.pop();
			switch (opType)
			{
			case ADD:
				a += b;
				break;
			case SUBTRACT:
				a -= b;
				break;
			case MULTIPLY:
				a *= b;
				break;
			case DIVIDE:
				if (b == 0)
					throw RPNInvalidInputException();
				a /= b;
				break;
			default:
				std::cout << "No operation was performed" << std::endl;
				break;
			}
			this->_nums.push(a);
		}
		else {
			throw RPNInvalidInputException();
		}
	}
	if (this->_nums.size() != 1) {
		throw RPNInvalidInputException();
	}
	std::cout << this->_nums.top() << std::endl;
}
