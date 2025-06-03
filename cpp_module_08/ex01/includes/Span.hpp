#pragma once
#include <vector>
#include <string>

class Span {
public:
	Span(unsigned int arrSize);
	~Span();
	// copy construcot
	// assignment 
	// Any attempt to add a new element if there are already N elements stored should throw an exception.
	void			addNumber(unsigned int n);
	void			addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	// If there are no numbers stored,
	// or only one, no span can be found. Thus, throw an exception.
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	// throw exception
	class SpanException : public std::exception {
		public:
			virtual const char *what() const throw();
			virtual ~SpanException() throw();
			SpanException(std::string const &message);
		private:
			std::string _message;

	};
private:
	std::vector<unsigned int>	_numArr;
	// unsigned int				_arrSize;
};

