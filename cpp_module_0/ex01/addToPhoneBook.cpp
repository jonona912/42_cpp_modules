#include "PhoneBook.hpp"

bool	hasWhiteSpace (std::string str){
	size_t	length = str.length();
	if (length > 0)
		length--;
	for (size_t i = 0; i < length; i++) {
		if (std::isspace(str[i])) {
			return (true);
			break;
		}
	}
	return (false);
}

bool isAllAlpha(std::string str)
{
	size_t len = str.length();
	for (size_t i = 0; i < len; i++) {
		if (!std::isalpha(str[i])){
			std::cout << "Invalid character present. Try again" << std::endl;
			return false;
		}
	}
	return (true);
}

bool checkNames(std::string str){
	if (str.length() <= 1) {
		std::cout << "Name should be equal to or longer than 2 characters" << std::endl;
		return false;
	}
	if (!isAllAlpha(str))
		return (false);
	if (hasWhiteSpace(str)) {
		std::cout << "Space detected, try again" << std::endl;
		return false;
	}
	return (true);
}

bool checkPhoneNumberValidity(std::string str){
	size_t str_len = str.length();

	if (str_len <= 7 || str_len >= 15){
		std::cout << "Invalid length" << std::endl;
		return false;
	}
	for (size_t i = 0; i < str_len; i++)
	{
		if (i == 0 && str[i] == '+')
			continue;
		if (!std::isdigit(str[i])) {
			std::cout << "Invalid character" << std::endl;
			return false;
		}
	}
	return true;
}

bool isUserInputValid(std::string str, size_t i)
{
	if (str.length() == 0)
		return false;
	if (i < 3)
		return (checkNames(str));
	else if (i == 3){
		if (str.length() < 3) {
			std::cout << "Invalid input" << std::endl;
			return false;
		}
		else
			return true;
	}
	else
		return (checkPhoneNumberValidity(str));
}

int	addToPhoneBook(PhoneBook &theBook) {
	size_t		num_of_prompts = 5;
	std::string	prompts_arr[num_of_prompts];
	prompts_arr[0] = "First Name: ";
	prompts_arr[1] = "Last Name: ";
	prompts_arr[2] = "Nickname: ";
	prompts_arr[3] = "Darkest Secret: ";
	prompts_arr[4] = "Phone Number: ";

	std::string contactInfoArr[num_of_prompts];
	size_t i = 0;
	while (i < num_of_prompts)
	{
		std::cout << prompts_arr[i];
		if (!std::getline(std::cin, contactInfoArr[i])) {
			std::cerr << std::endl << "EOF (Ctrl+D) was entered" << std::endl;
			exit (1);
		}
		if (isUserInputValid(contactInfoArr[i], i))
			i++;
	}
	theBook.SetContact(contactInfoArr);
	return (1);
}
