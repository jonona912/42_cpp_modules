/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:02:18 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 17:26:12 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <stdint.h>

class Data {
public:
	Data();
	~Data();
	Data(std::string testStr);
	Data(const Data &other);
	Data &operator=(const Data &other);
	std::string getTestStr() const;
private:
	std::string _testStr;
};

std::ostream &operator<<(std::ostream &os, const Data &data);
