/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:35:11 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/26 11:24:02 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subjectDemo() {
	std::cout << "\033[35mSUBJECT DEMO\033[0m" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\033[34m\ngetType\033[0m" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\033[34m\nmakeSound\033[0m" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete i;
	delete j;
	delete meta;
}

void wrongAnimalDemo() {
	std::cout << "\033[35mWRONG ANIMAL DEMO\033[0m" << std::endl;
	const WrongAnimal *wrongAnDemo1 = new WrongAnimal();
	const WrongAnimal *wrongCat1 = new WrongCat();
	std::cout << "\033[34m\ngetType\033[0m" << std::endl;
	std::cout << wrongAnDemo1->getType() << " " << std::endl;
	std::cout << wrongCat1->getType() << " " << std::endl;
	std::cout << "\033[34m\ngetMakeSound\033[0m" << std::endl;
	wrongAnDemo1->makeSound();
	wrongCat1->makeSound();

	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete wrongAnDemo1;
	delete wrongCat1;
}

int main(void) {
	subjectDemo();
	wrongAnimalDemo();

	return 0;
}
