#include "ClassPhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	index_to_set_to = 0;
	num_of_contacts = 0;
	std::cout << "PhoneBook initialized" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::SetContact(std::string info_arr[5]) {
	contacts[index_to_set_to].setContact(info_arr);
	if (index_to_set_to < 7)
		index_to_set_to++;
	else
		index_to_set_to = 0;
	if (num_of_contacts < 7)
		num_of_contacts++;
}

int PhoneBook::DisplayContact(int index) const {
	if (index >= 0 && index < 8)
	{
		contacts[index].display(index);
		return (1);
	}
	else
	{
		std::cout << "Invalid range" << index << std::endl;
		return (0);
	}
}

int	PhoneBook::returnNumOfContacts() const {
	return (num_of_contacts);
}
