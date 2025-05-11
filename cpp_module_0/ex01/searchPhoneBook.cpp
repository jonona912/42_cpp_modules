#include "PhoneBook.hpp"

bool	isValidNumberAndRange(const std::string& str) {
	size_t length = str.length();
	if (length == 0)
		return false;
	size_t start = 0;
	if (str[0] == '+' || str[0] == '-') {
		start = 1;
		if (length == 1)
			return false;
	}
	for (size_t i = start; i < length; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	int num = std::atoi(str.c_str());
	return (num >= 1 && num <= 8);
}

int	searchPhoneBook(PhoneBook &theBook) {
	std::string user_idx;

	while (true)
	{
		std::cout << "Please enter index from 1 to 8 to search: ";
		std::getline(std::cin, user_idx);
		if (isValidNumberAndRange(user_idx))
		{
			int	idx = std::atoi(user_idx.c_str());
			theBook.DisplayContact(idx - 1);
			break ;
		}
		else
			std::cout << "Invalid number or range" << std::endl;
	}
	return (1);
}
