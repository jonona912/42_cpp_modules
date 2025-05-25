/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:37:07 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/25 18:17:02 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string const &name);
	~ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap& operator=(ClapTrap const &rhs);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	std::string 	_name;
	unsigned int	_hitPts; // health of the object
	unsigned int	_energyPts;
	unsigned int	_attackDmg;
};


#endif
