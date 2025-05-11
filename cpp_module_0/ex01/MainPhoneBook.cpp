#include "PhoneBook.hpp"


#include <iostream>
#include <string>
#include <sstream> // For std::stringstream

int	main() {
	PhoneBook theBook;

	std::string user_input;
	std::string	mode;
	while (true)
	{
		std::cout << "Enter mode (ADD SEARCH EXIT): ";
		if (!std::getline(std::cin, mode)) {
			std::cout << "EOF (Ctrl+D) was entered" << std::endl;
			exit (1);
		}
		std::string modeUpper = strToUpper(mode);
		if (modeUpper == "ADD")
		{
			addToPhoneBook(theBook); // cannot contain space
		}
		else if (modeUpper == "SEARCH")
		{
			searchPhoneBook(theBook);
		}
		else if (modeUpper == "EXIT")
		{
			if (confirmExit())
				break ;
		}
	}
	theBook.DisplayContact(0);
	for (int i = 1; i < theBook.returnNumOfContacts(); i++)
		theBook.DisplayContact(i);
}
