#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const std::string &type);
	~Cat();
	Cat(const Cat &src);
	Cat& operator=(const Cat &rhs);
	void makeSound() const;
	Brain* getBrain() const;
private:
	Brain* _brain;
};



#endif // CAT_HPP