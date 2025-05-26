#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &src);
	Brain& operator=(const Brain &rhs);
	void addIdea(const int &index, const std::string &setIdea);
	std::string getIdea(const int &index) const;
protected:
	std::string *ideas;
};



#endif