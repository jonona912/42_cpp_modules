/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 08:35:11 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/26 15:19:30 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subjectDemo() {
	std::cout << "\033[35mSUBJECT DEMO\033[0m" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\033[34m\nEnd of Constructors\033[0m" << std::endl;
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete j;//should not create a leak
	delete i;
}

void animalArrObjs() {
	std::cout << "\033[35mARRAY OF ANIMAL OBJECTS DEMO\033[0m" << std::endl;
	int n = 20;
	Animal** animalArray = new Animal*[n];
	
	for (int i = 0; i < n/2; i++) {
		animalArray[i] = new Cat();
		animalArray[n - i - 1] = new Dog();
	}
	std::cout << "\033[34m\nEnd of Constructors\033[0m" << std::endl;
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	for (int i = 0; i < 20; i++) {
		delete animalArray[i];
	}
	delete[] animalArray;
}

void deepCopyTest() {
	std::cout << "\033[35mDEEP COPY TEST\033[0m" << std::endl;
	
	Cat* originalCat = new Cat();
	Cat* copyCat = new Cat(*originalCat);
	std::cout << "\033[34m\nEnd of Constructors\033[0m" << std::endl;

	std::cout << "Original Cat address: " << originalCat << std::endl;
	std::cout << "Copy Cat address: " << copyCat << std::endl;
	std::cout << "Original Cat brain address: " << originalCat->getBrain() << std::endl;
	std::cout << "Copy Cat brain address: " << copyCat->getBrain() << std::endl;
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete originalCat;
	delete copyCat;
}

void copyAssignmentTest() {
	std::cout << "\033[35mCOPY ASSIGNMENT TEST\033[0m" << std::endl;
	
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	
	// Add some initial ideas to cat1
	cat1->getBrain()->addIdea(0, "Cat 1's first thought");
	cat1->getBrain()->addIdea(1, "Cat 1's second thought");
	
	// Add different ideas to cat2
	cat2->getBrain()->addIdea(0, "Cat 2's first thought");
	cat2->getBrain()->addIdea(1, "Cat 2's second thought");
	
	std::cout << "\033[34m\nBefore Assignment\033[0m" << std::endl;
	std::cout << "Cat 1 address: " << cat1 << std::endl;
	std::cout << "Cat 2 address: " << cat2 << std::endl;
	std::cout << "Cat 1 brain address: " << cat1->getBrain() << std::endl;
	std::cout << "Cat 2 brain address: " << cat2->getBrain() << std::endl;
	std::cout << "Cat 1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	// Perform the assignment
	*cat2 = *cat1;
	
	std::cout << "\033[34m\nAfter Assignment\033[0m" << std::endl;
	std::cout << "Cat 1 address: " << cat1 << std::endl;
	std::cout << "Cat 2 address: " << cat2 << std::endl;
	std::cout << "Cat 1 brain address: " << cat1->getBrain() << std::endl;
	std::cout << "Cat 2 brain address: " << cat2->getBrain() << std::endl;
	std::cout << "Cat 1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	// Modify cat1's ideas to confirm deep copy
	cat1->getBrain()->addIdea(0, "Cat 1's modified thought");
	
	std::cout << "\033[34m\nAfter Modifying Cat 1\033[0m" << std::endl;
	std::cout << "Cat 1 idea 0: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea 0: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete cat1;
	delete cat2;
}

void brainIdeasTest() {
	std::cout << "\033[35mBRAIN IDEAS TEST\033[0m" << std::endl;
	
	Cat* cat = new Cat();
	std::cout << "\033[34m\nEnd of Constructor\033[0m" << std::endl;
	Brain* catBrain = cat->getBrain();
	
	catBrain->addIdea(0, "I want to eat fish");
	catBrain->addIdea(1, "I need to sleep");
	catBrain->addIdea(2, "I should chase that mouse");
	
	Cat* catCopy = new Cat(*cat);
	std::cout << "\033[34m\nEnd of Constructors\033[0m" << std::endl;
	Brain* copiedBrain = catCopy->getBrain();
	
	std::cout << "Original cat idea 0: " << catBrain->getIdea(0) << std::endl;
	std::cout << "Copied cat idea 0: " << copiedBrain->getIdea(0) << std::endl;
	
	std::cout << "Original cat idea 1: " << catBrain->getIdea(1) << std::endl;
	std::cout << "Copied cat idea 1: " << copiedBrain->getIdea(1) << std::endl;
	
	copiedBrain->addIdea(1, "I want to play with yarn");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original cat idea 1: " << catBrain->getIdea(1) << std::endl;
	std::cout << "Copied cat idea 1: " << copiedBrain->getIdea(1) << std::endl;
	
	std::cout << "\033[34m\nEnd of Test\033[0m" << std::endl;
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete cat;
	delete catCopy;
}

void assignmentOperatorTest() {
	std::cout << "\033[35mASSIGNMENT OPERATOR TEST\033[0m" << std::endl;
	
	Cat* cat1 = new Cat();
	cat1->getBrain()->addIdea(0, "Cat 1's original thought");
	
	Cat* cat2 = new Cat();
	cat2->getBrain()->addIdea(0, "Cat 2's original thought");
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Cat 1 idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	*cat2 = *cat1;
	
	std::cout << "After assignment:" << std::endl;
	std::cout << "Cat 1 idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	cat1->getBrain()->addIdea(0, "Cat 1's new thought");
	std::cout << "After modifying Cat 1:" << std::endl;
	std::cout << "Cat 1 idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2 idea: " << cat2->getBrain()->getIdea(0) << std::endl;
	
	std::cout << "\033[34m\nEnd of Test\033[0m" << std::endl;
	std::cout << "\033[34m\nDestructors Should be Called\033[0m" << std::endl;
	delete cat1;
	delete cat2;
}

int main(void) {
	std::cout << "Starting tests... Press Enter to begin." << std::endl;
	std::cin.get();
	
	subjectDemo();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();
	
	animalArrObjs();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();
	
	deepCopyTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();
	
	copyAssignmentTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();
	
	brainIdeasTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();
	
	assignmentOperatorTest();
	std::cout << "\n\033[33mTest completed. Press Enter to exit...\033[0m" << std::endl;
	std::cin.get();
	
	return 0;
}