#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "ClassPhoneBook.hpp"
#include <cstdlib>  // For std::atoi
#include <cctype>   // For std::isdigit
#include <iostream>

// addToPhoneBook.cpp
int	addToPhoneBook(PhoneBook &theBook);

// confirmExit.cpp
bool	confirmExit();

// searchPhoneBook.cpp
int	searchPhoneBook(PhoneBook &theBook);

// stringConversions.cpp
std::string strToUpper(std::string str);

#endif