#include "PhoneBook.hpp"

std::string strToUpper(std::string str) {
	std::string strUpper = str;
	size_t length = strUpper.length();
	for (size_t i = 0; i < length; i++) {
		strUpper[i] = std::toupper(strUpper[i]);
	}
	return (strUpper);
}
