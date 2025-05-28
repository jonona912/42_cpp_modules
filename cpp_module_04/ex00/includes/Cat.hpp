#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const std::string &type);
	~Cat();
	Cat(const Cat &src);
	Cat& operator=(const Cat &rhs);
	void makeSound() const;
};



#endif // CAT_HPP