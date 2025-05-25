/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:37:10 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/25 18:21:54 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


int main(void) {
	// Basic constructor test
	ClapTrap cp("Azhdahor");
	ClapTrap defaultCP;
	// Basic attacks and repairs
	cp.attack("Magas");
	cp.takeDamage(4);
	cp.beRepaired(3);

	// Test energy points depletion
	std::cout << "\n--- Testing energy points depletion ---" << std::endl;
	for (int i = 0; i < 10; i++) {
		cp.attack("Training Dummy");
	}
	// Should show "No energy points left"
	cp.attack("Training Dummy");
	
	// Test repairs after energy is depleted
	cp.beRepaired(5); // Should show "No energy points left"
	
	// Test copy constructor
	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	ClapTrap cp2 = ClapTrap("Warrior");
	ClapTrap cp3(cp2); // Copy constructor
	cp3.attack("Enemy");
	
	// Test assignment operator
	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	ClapTrap cp4("Original");
	ClapTrap cp5("WillBeOverwritten");
	cp5 = cp4; // Assignment
	cp5.attack("Target");
	
	// Test hit points depletion
	std::cout << "\n--- Testing hit points depletion ---" << std::endl;
	ClapTrap cp6("GlassCannon");
	cp6.takeDamage(5);
	cp6.takeDamage(10); // Should reduce to 0
	cp6.attack("Someone"); // Should fail due to no hit points
	cp6.takeDamage(1); // Should show "No hit point left to absorb damage"

	return 0;
}
