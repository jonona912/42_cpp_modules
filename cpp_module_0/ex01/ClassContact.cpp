#include "ClassContact.hpp"

#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact (void){
	seperator = " | ";
	// std::cout << "Contrusctor called" << std::endl;
};

Contact::~Contact ( void ){
	// std::cout << "Destructor called" << std::endl;
};

void Contact::setContact (std::string info_arr[5]) {
	firstName = info_arr[0];
	lastName = info_arr[1];
	nickName = info_arr[2];
	darkestSecret = info_arr[3];
	phoneNumber = info_arr[4];
}

void Contact::display(int index) const{
	std::cout << index + 1 << seperator;
	_displayContactWithFormat(firstName);
	_displayContactWithFormat(lastName);
	_displayContactWithFormat(darkestSecret);
	_displayContactWithFormat(phoneNumber);
	std::cout << std::endl;
}

void Contact::_displayContactWithFormat(std::string str) const {
	if (str.length() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) + "." << seperator;
	else
		std::cout << std::setw(10) << str << seperator;
}