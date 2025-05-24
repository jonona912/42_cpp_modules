#include <iostream>
#include <string>

int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR= &brain;
	std::string &stringREF = brain;
	std::cout << "Brain address  " << &brain << std::endl;
	std::cout << "strPTR Address " << stringPTR << std::endl;
	std::cout << "strREF Address " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Brain value  " << brain << std::endl;
	std::cout << "strPTR value " << *stringPTR << std::endl;
	std::cout << "strREF value " << stringREF << std::endl;

	return 0;
}
