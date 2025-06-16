/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:49:22 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/16 19:04:37 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char *av[]) {
	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << " <positive integers...>" << std::endl;
		return 1;
	}
	try {
		PmergeMe pmerge(ac, av);
		pmerge.sortAndMeasure();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
