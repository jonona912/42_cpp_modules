#include "Harl.hpp"

#include <iostream>

#include "Harl.hpp"
#include <iostream>

struct Harl::Complains {
	std::string	type;
	void (Harl::*func)(void);
};

Harl::Harl() {
	_complaints = new Complains[4];
	
	_complaints[0].type = "DEBUG";
	_complaints[0].func = &Harl::debug;
	
	_complaints[1].type = "INFO";
	_complaints[1].func = &Harl::info;
	
	_complaints[2].type = "WARNING";
	_complaints[2].func = &Harl::warning;
	
	_complaints[3].type = "ERROR";
	_complaints[3].func = &Harl::error;
}
Harl::~Harl() {
	delete []_complaints;
}

int	Harl::returnComplaintNum(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == _complaints[i].type) {
			return i;
		}
	}
	return -1;
}

void Harl::executeComplaint(int level) {
	if (level >= 0 && level <= 4) {
		std::cout << "[ " << _complaints[level].type << " ]" << std::endl;
		(this->*(_complaints[level].func))();
		std::cout << std::endl;
	}
	else
		std::cout << "Complain level out of range" << std::endl;
}

std::string Harl::returnComplaintLevel(int idx) {
	if (idx >= 0 && idx <= 4)
		return (_complaints[idx].type);
	return NULL;
}

void Harl::complaintCrazeMode(std::string complain) {
	bool didComplain = 0;
	if (_complaints == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (complain == _complaints[i].type) {
			didComplain = 1;
			while (i < 4) {
				std::cout << "[ " << _complaints[i].type << " ]" << std::endl;
				(this->*(_complaints[i].func))();
				std::cout << std::endl;
				i++;
			}
		}
		if (didComplain)
			break;
	}
	if (!didComplain)
		std::cout << "Harl's complaint vocabulary does not include "
					<< complain << "? Strange" << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == _complaints[i].type) {
			(this->*(_complaints[i].func))();
			return;
		}
	}
	std::cout	<< "Huh, surprisingly Harl does"
				<< " not have complains for " << level << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn't put enough bacon in my burger! If you did, "
			<< "I wouldn't be asking for more!" << std::endl;
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
			<< "special-ketchup burger. I really do!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. "
			<< "I've been coming for years, whereas you started working here just last month."
			<< std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
