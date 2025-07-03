#pragma once

#include <stack>
#include <string>

typedef enum {
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
} Operation;

class RPN {
	private:
		std::stack<int>	_nums;
		std::string		_strRPN;
		void			checkForExtChars() const;
		void			performCalculations();
		Operation		operationType(std::string const &character) const;
	public:
		RPN(std::string const &strRPN);
		~RPN();
		RPN(RPN const &other);
		RPN& operator=(RPN const &other);
		
		int		getResult();
		class RPNInvalidInputException : public std::exception {
			public:
				const char *what() const throw();
		};
};
