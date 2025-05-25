/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:37:10 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/25 18:53:47 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
    DiamondTrap dt1("Sparkles");
    DiamondTrap defaultDT;
    
    dt1.attack("Enemy");
    dt1.takeDamage(30);
    dt1.beRepaired(15);
    
    std::cout << "\n--- Testing whoAmI method ---" << std::endl;
    dt1.whoAmI();
    defaultDT.whoAmI();
    
    std::cout << "\n--- Testing inherited ScavTrap ability ---" << std::endl;
    dt1.guardGate();
    
    std::cout << "\n--- Testing inherited FragTrap ability ---" << std::endl;
    dt1.highFivesGuys();
    
    std::cout << "\n--- Testing energy points depletion ---" << std::endl;
    for (int i = 0; i < 50; i++) {
        dt1.attack("Training Dummy");
    }
    dt1.attack("Training Dummy");
    
    std::cout << "\n--- Testing copy constructor ---" << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    dt2.attack("Shadow");
    
    std::cout << "\n--- Testing assignment operator ---" << std::endl;
    DiamondTrap dt3("Temporary");
    dt3 = dt1;
    dt3.whoAmI();
    dt3.attack("Clone");
    
    std::cout << "\n--- Testing hit points depletion ---" << std::endl;
    DiamondTrap dt4("Crystal");
    dt4.takeDamage(50);
    dt4.takeDamage(60);
    dt4.attack("Someone");
    dt4.whoAmI();
    
    return 0;
}