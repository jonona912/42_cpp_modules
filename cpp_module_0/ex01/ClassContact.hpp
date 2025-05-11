#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP

#include <string>

class Contact {
public:
	Contact ( void );
	~Contact ( void );
	void	setContact(std::string s[5]);
	void	display(int index) const;
private:
	void	_displayContactWithFormat(std::string str) const;
	std::string seperator;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	std::string phoneNumber;
};

#endif