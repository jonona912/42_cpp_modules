/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:23:15 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/07 21:51:55 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange {
private:
	std::multimap<std::string, float> _data;
	std::map<std::string, float> _btcRates;
	void	loadData(const std::string& filename);
	void	loadBtcRates(const std::string& filename);
	void	printMap() const;
	// float	getExchangeRate(const std::string& date) const;
	bool	validateDate(const std::string& date) const;
	bool isLeapYear(int year) const;
	bool isValidDate(int day, int month, int year) const;
	// bool	validateRate(const std::string& rateStr) const;
	// void	printExchangeRate(const std::string& date, float amount) const;
	void	printError(const std::string& message) const;
public:
	BitcoinExchange(const std::string& filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void	printExchangeRates();
};
