/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:37:10 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/25 18:44:57 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	FragTrap ft1("Destroyer");
	FragTrap defaultFT;
	
	ft1.attack("Enemy");
	ft1.takeDamage(30);
	ft1.beRepaired(15);
	
	std::cout << "\n--- Testing energy points depletion ---" << std::endl;
	for (int i = 0; i < 100; i++) {
		ft1.attack("Training Dummy");
	}
	ft1.attack("Training Dummy");
	
	ft1.beRepaired(20);
	
	std::cout << "\n--- Testing high fives ---" << std::endl;
	ft1.highFivesGuys();
	
	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	FragTrap ft2(ft1);
	ft2.highFivesGuys();
	ft2.attack("Shadow");
	
	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	FragTrap ft3("Temporary");
	ft3 = ft1;
	ft3.attack("Clone");
	ft3.highFivesGuys();
	
	std::cout << "\n--- Testing hit points depletion ---" << std::endl;
	FragTrap ft4("GlassCannon");
	ft4.takeDamage(50);
	ft4.takeDamage(60);
	ft4.attack("Someone");
	ft4.highFivesGuys();
	
	return 0;
}