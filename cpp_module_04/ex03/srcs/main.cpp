/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:06:09 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/27 21:00:46 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

// void printMateriaSource() {
	
// }

void materiaSourceDemo() {
	MateriaSource ms1;
	Ice *ice1 = new Ice();
	Cure *cure1 = new Cure();
	ms1.learnMateria(ice1);
	AMateria *materia1 = ms1.createMateria("ice");
	AMateria *materia2 = ms1.createMateria("cure");
	if (!materia2) {
		std::cout << "Failed to create materia that was not learned before: " << materia2 << std::endl;
	}
	ms1.learnMateria(cure1); 
	materia2 = ms1.createMateria("cure");
	std::cout << "created materia: " << materia1->getType() << std::endl;
	std::cout << "created materia: " << materia2->getType() << std::endl;
	AMateria *nonExistant1 = ms1.createMateria("nonExistant");
	if (!nonExistant1)
		std::cout << "Failed to create nonexistant materia  " << nonExistant1 << std::endl;
	// delete cure1;
	// delete ice1;
	delete materia1;
	delete materia2;
}

void characterDemo() {
	IMateriaSource* memory = new MateriaSource();
	AMateria *ice1 = new Ice();
	AMateria *cure1 = new Cure();
	memory->learnMateria(ice1);
	memory->learnMateria(cure1);
	Character ch1("Jon");
	AMateria* weaponTmp = memory->createMateria("ice");
	AMateria* weaponCure = memory->createMateria("cure");
	ch1.equip(weaponTmp);
	ch1.equip(weaponCure);
	Character ch2("Jonona");
	ch1.use(0, ch2);
	ch1.use(1, ch2);
	delete memory;
}

void subjectDemo() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void copyConstructorTest() {
    std::cout << "\033[35mCOPY CONSTRUCTOR TEST\033[0m" << std::endl;
    
    Character original("Original");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    
    original.equip(ice);
    original.equip(cure);
    
    std::cout << "Original character equipped with materias" << std::endl;
    original.use(0, original);
    original.use(1, original);
    
    Character copy(original);
    std::cout << "\nCopy character using materias (should be deep copied):" << std::endl;
    copy.use(0, original);
    copy.use(1, original);
    
    std::cout << "\nUnequipping original's materias shouldn't affect copy:" << std::endl;
    original.unequip(0);
    original.unequip(1);
    
    std::cout << "Original after unequip (should have no effect):" << std::endl;
    original.use(0, copy);
    original.use(1, copy);
    
    std::cout << "Copy after original's unequip (should still work):" << std::endl;
    copy.use(0, original);
    copy.use(1, original);
    
    std::cout << "\033[34mEnd of Test\033[0m" << std::endl;
    delete src;
    delete ice; // These were unequipped from original
    delete cure;
}

void assignmentOperatorTest() {
    std::cout << "\033[35mASSIGNMENT OPERATOR TEST\033[0m" << std::endl;
    
    Character ch1("Character1");
    Character ch2("Character2");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    
    ch1.equip(ice);
    ch2.equip(cure);
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << ch1.getName() << " uses slot 0: ";
    ch1.use(0, ch2);
    std::cout << ch2.getName() << " uses slot 0: ";
    ch2.use(0, ch1);
    
    ch2 = ch1;
    
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << ch1.getName() << " uses slot 0: ";
    ch1.use(0, ch2);
    std::cout << ch2.getName() << " uses slot 0: ";
    ch2.use(0, ch1);
    
    std::cout << "\033[34mEnd of Test\033[0m" << std::endl;
    delete src;
}

void inventoryManagementTest() {
    std::cout << "\033[35mINVENTORY MANAGEMENT TEST\033[0m" << std::endl;
    
    Character hero("Hero");
    IMateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    
    // Fill inventory
    std::cout << "Filling inventory with 4 materias:" << std::endl;
    for (int i = 0; i < 4; i++) {
        AMateria* mat = (i % 2 == 0) ? source->createMateria("ice") : source->createMateria("cure");
        hero.equip(mat);
        std::cout << "Equipped slot " << i << " with " << mat->getType() << std::endl;
    }
    
    // Try to equip when inventory is full
    AMateria* extraMat = source->createMateria("ice"); //
    std::cout << "\nTrying to equip when inventory is full:" << std::endl;
    hero.equip(extraMat);
    
    // Unequip and re-equip
    std::cout << "\nUnequipping slot 2 and re-equipping with new materia:" << std::endl;
	AMateria* unequippedMat = hero.getMateriaAddress(2);
    hero.unequip(2);
    hero.equip(extraMat);
    
    // Use all slots to verify
    std::cout << "\nUsing all materias after changes:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Slot " << i << ": ";
        hero.use(i, hero);
    }
    
    // Test invalid slot indices
    std::cout << "\nTesting invalid slot indices:" << std::endl;
    hero.use(-1, hero);
    hero.use(4, hero);
    hero.unequip(-1);
    hero.unequip(4);
    
    std::cout << "\033[34mEnd of Test\033[0m" << std::endl;
    delete source;
	delete unequippedMat;
    // Note: There might be memory leaks if unequipped materias aren't deleted properly
}

void materiaSourceCapacityTest() {
    std::cout << "\033[35mMATERIA SOURCE CAPACITY TEST\033[0m" << std::endl;
    
    MateriaSource source;
    
    // Test learning up to capacity
    std::cout << "Learning materias up to capacity:" << std::endl;
    for (int i = 0; i < 4; i++) {
		AMateria* mat;
		if (i % 2 == 0)
			mat = new Ice();
		else
			mat = new Cure();
        std::cout << "Learning " << mat->getType() << std::endl;
        source.learnMateria(mat);
    }
    
    // Try to learn beyond capacity
    std::cout << "\nTrying to learn beyond capacity:" << std::endl;
    AMateria* extraMat = new Ice();
    source.learnMateria(extraMat);
    
    // Test creating each type
    std::cout << "\nCreating materias of different types:" << std::endl;
    AMateria* ice = source.createMateria("ice");
    AMateria* cure = source.createMateria("cure");
    AMateria* unknown = source.createMateria("unknown");
    
    std::cout << "Created ice: " << (ice ? ice->getType() : "nullptr") << std::endl;
    std::cout << "Created cure: " << (cure ? cure->getType() : "nullptr") << std::endl;
    std::cout << "Created unknown: " << (unknown ? "not null" : "nullptr") << std::endl;
    
    std::cout << "\033[34mEnd of Test\033[0m" << std::endl;
    delete extraMat;
    delete ice;
    delete cure;
    // unknown should be nullptr, no need to delete
}

int main(void) {
	std::cout << "Starting tests... Press Enter to begin with subjectDemo" << std::endl;
	std::cin.get();

	subjectDemo();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to materiaSourceDemo\033[0m" << std::endl;
	std::cin.get();

	materiaSourceDemo();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to characterDemo\033[0m" << std::endl;
	std::cin.get();

	characterDemo();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to copyConstructorTest\033[0m" << std::endl;
	std::cin.get();

	copyConstructorTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();

	assignmentOperatorTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();

	inventoryManagementTest();
	std::cout << "\n\033[33mTest completed. Press Enter to continue to next test...\033[0m" << std::endl;
	std::cin.get();

	materiaSourceCapacityTest();
	std::cout << "\n\033[33mTest completed. Press Enter to exit...\033[0m" << std::endl;
	std::cin.get();

	return 0;
}
