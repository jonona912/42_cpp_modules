#include <iostream>
#include <string>



class Student {
private:
	std::string _login;

public:
	Student(std::string const &login) : _login(login) {
	}
	std::string &getLoginRef() {
		return (this->_login);
	}
	std::string const &getLoginRefConst() const {
		return (this->_login);
	}
	std::string	*getLoginPtr() {
		return &(this->_login);
	}
	std::string const *getLoginPtrConst() const {
		return &(this->_login);
	}
};



int main() {
	Student jnn = Student("jnn912");
	Student doose = Student("doose");
	std::cout << jnn.getLoginRef() << " " << jnn.getLoginRefConst() << std::endl;
	std::cout << *(jnn.getLoginPtr()) << " " << *(jnn.getLoginPtrConst()) << std::endl;
	jnn.getLoginRef() = "Mohru";
	std::cout << jnn.getLoginRefConst() << std::endl;
	*(jnn.getLoginPtr()) = "Backtojnn912";
	std::cout << *(jnn.getLoginPtrConst()) << std::endl;
	return (0);
}
















// void	byPtr(std::string *str){
// 	*str += " and Doose";
// }

// void byConstPtr(std::string const *str) {
// 	std::cout << *str << std::endl;
// 	(std::string) *str += "and test";
// }
// void byRef(std::string &str) {
// 	str += " and Jonik";
// }

// int main() {
// 	std::string jnn = "Jonona";
// 	std::cout << jnn << std::endl;
// 	byPtr(&jnn);
// 	// std::cout << jnn << std::endl;
// 	byConstPtr(&jnn);
// 	jnn = "Mohru";
// 	std::cout << jnn << std::endl;
// 	byRef(jnn);
// 	std::cout << jnn << std::endl;

// 	return (0);
// }

