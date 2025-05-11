#ifndef CLASS_PHONE_BOOK_HPP
#define CLASS_PHONE_BOOK_HPP

#include "ClassContact.hpp"
#include <iostream>

class PhoneBook {
public:
	PhoneBook( void );
	~PhoneBook( void );

	void SetContact(std::string info_arr[5]);
	int DisplayContact( int index ) const;
	int	returnNumOfContacts() const;
private:
	Contact contacts[8];
	int		num_of_contacts;
	int		index_to_set_to;
};

#endif
