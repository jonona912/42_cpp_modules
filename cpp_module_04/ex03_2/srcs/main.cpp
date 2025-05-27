/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:06:09 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/27 17:52:37 by zkhojazo         ###   ########.fr       */
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
	delete cure1;
	delete ice1;
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
	Character ch2("onona");
	ch1.use(0, ch2);
	ch1.use(1, ch2);
	delete ice1;
	delete cure1;
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

int main(void) {
	subjectDemo();
	// materiaSourceDemo();
	// characterDemo();
	return 0;
}
