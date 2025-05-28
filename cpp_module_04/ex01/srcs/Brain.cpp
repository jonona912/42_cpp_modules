#include "Brain.hpp"

const int STR_ARRAY_SIZE = 100;

Brain::Brain() {
	this->ideas = new std::string[STR_ARRAY_SIZE];
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain() {
	delete [] this->ideas;
	std::cout << "Brain Desctructor Called" << std::endl;
}

Brain::Brain(const Brain &src) {
	this->ideas = new std::string[STR_ARRAY_SIZE];
	for (int i = 0; i < STR_ARRAY_SIZE; i++) {
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain &rhs) {
	if (this != &rhs) { 
		for (int i = 0; i < STR_ARRAY_SIZE; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

void Brain::addIdea(const int &index, const std::string &setIdea) {
	if (index >= 0 && index < STR_ARRAY_SIZE)
		this->ideas[index] = setIdea;
	else
		std::cout << "Index out of range. Index from 0 to 99" << std::endl;
}

std::string Brain::getIdea(const int &index) const {
	if (index >= 0 && index < STR_ARRAY_SIZE)
		return this->ideas[index];
	return "Invalid index";
}
