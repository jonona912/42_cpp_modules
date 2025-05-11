#include "PhoneBook.hpp"

bool	confirmExit() {
	std::string input;

	std::cout << "Do you really want to exit, all contacts will be lost" << std::endl;
	while (true) {
		if (!std::getline(std::cin, input)) {
			std::cout << "EOF (Ctrl+D) was entered" << std::endl;
			exit (1);
		}
		input = strToUpper(input);
		if (input == "YES" || input == "Y")
			return true;
		else if (input == "NO" || input == "N")
			return false;
		else
			std::cout << "Please enter 'yes' or 'no'" << std::endl;
	}
}