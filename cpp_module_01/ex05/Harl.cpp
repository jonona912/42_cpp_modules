#include "Harl.hpp"

#include <iostream>

#include "Harl.hpp"
#include <iostream>

struct Harl::Complains {
	std::string	type;
	void (Harl::*func)(void);
};

Harl::Harl() {
	complaints = new Complains[4];
	
	complaints[0].type = "DEBUG";
	complaints[0].func = &Harl::debug;
	
	complaints[1].type = "INFO";
	complaints[1].func = &Harl::info;
	
	complaints[2].type = "WARNING";
	complaints[2].func = &Harl::warning;
	
	complaints[3].type = "ERROR";
	complaints[3].func = &Harl::error;
}
Harl::~Harl() {
	delete []complaints;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (level == complaints[i].type) {
			(this->*(complaints[i].func))();
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
