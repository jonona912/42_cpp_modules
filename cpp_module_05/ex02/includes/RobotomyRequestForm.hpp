/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:02:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:35 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const &other);
	virtual void			execute(Bureaucrat const & executor) const;
	std::string				getTarget() const;
	class RobomizationFailedException : public std::exception {
		virtual const char *what() const throw();
	};
private:
	std::string const	_target;
	bool				getRandomBool() const;
};

std::ostream& operator<<(std::ostream &out, RobotomyRequestForm const &RRForm);
