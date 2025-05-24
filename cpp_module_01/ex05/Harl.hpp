#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
public:
	Harl();
	~Harl();
	void complain( std::string level );
	
private:
	struct Complains;
	Complains* complaints;
	void info( void );
	void debug( void );
	void warning( void );
	void error( void );
};

#endif
