#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
	Harl();
	~Harl();
	void complain( std::string level );
	void complaintCrazeMode(std::string complain);
	int	returnComplaintNum(std::string level);
	void executeComplaint(int level);
	std::string returnComplaintLevel(int idx);
private:
	struct Complains;
	Complains* _complaints;
	void info( void );
	void debug( void );
	void warning( void );
	void error( void );
};

#endif
