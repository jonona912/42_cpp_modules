/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:32:03 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/08 10:28:28 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cmath>
#include <limits>
#include <string>
#include <cfloat>
#include <iomanip>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	loadBtcRates("data.csv"); // check if the file exists and is readable throw error
	(void)filename; // Suppress unused variable warning
	loadData(filename); // check  if the file exists and is readable throw error
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_data = other._data;
	}
	return *this;
}

// void  BitcoinExchange::printExchangeRates() {
	
// 	// for (const auto& entry : this->_data) {
// 	// 	std::cout << entry.first << " => " << entry.second << std::endl;
// 	// }
// 	for (size_t i = 0; i < this->_data.size(); ++i) {
// 		std::cout << "Date: " << this->_data.begin()->first
// 		<< ", Rate: " << this->_data.begin()->second << std::endl;
// 	}
// }

void BitcoinExchange::printMap() const {
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << "Date: " << it->first << ", Rate: " << it->second << std::endl;
	}
}

float validateRate(const std::string& rateStr) {
	double rate;
	std::istringstream ss(rateStr);
	if (!(ss >> rate)) {
		throw std::runtime_error("Invalid number format");
	}
	std::string remaining;
	ss >> remaining;
	if (!remaining.empty()) {
		throw std::runtime_error("Invalid number format");
	}
	if (rate < 0 || rate > FLT_MAX) {
		throw std::runtime_error("Not a positive number or too large a number");
	}
	return static_cast<float>(rate);
}

void BitcoinExchange::loadBtcRates(const std::string& filename) {
	std::string	line;
	float		rate;

	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		printError("Could not open file: " + filename);
		return ;
	}
	while (std::getline(file, line)) {
		if (line.find("date") != std::string::npos) {
			continue ;
		}
		std::string date = line.substr(0, line.find_first_of(" \t,"));
		if (!validateDate(date)) {
			throw std::runtime_error("Invalid date format: " + date);
		}
		std::string rateStr =  line.substr(line.find_first_of(",") + 1);
		if (!rateStr.empty()) {
			rate = validateRate(rateStr);
		}
		else {
			throw std::runtime_error("No rate provided for date: " + date);
		}
		this->_btcRates.insert(this->_btcRates.end(), std::make_pair(date, rate));
	}
}

bool isFloat(const std::string& str) {
	std::istringstream iss(str);
	float f;
	iss >> f;
	return iss.eof() && !iss.fail();
}

void BitcoinExchange::loadData(const std::string& filename) {
	float rate;
	float result;
	bool isHeader = true;
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		printError("Could not open file: " + filename);
		return ;
	}
	std::string line;
	while (std::getline(file, line)) {
		if (isHeader && line.find("date") != std::string::npos) {
			isHeader = false;
			continue;
		}
		std::string date = line.substr(0, line.find_first_of(" \t|"));
		if (!validateDate(date)) {
			printError("bad input => " + date);
			continue;
		}
		if (line.find_first_of("|") == std::string::npos) {
			printError("Error: Invalid format in line: " + line);
			continue;
		}
		std::string rateStr =  line.substr(line.find_first_of("|") + 1);
		if (!isFloat(rateStr)) {
			printError("Invalid float value: " + rateStr);
			continue;
		}
		if (!rateStr.empty()) {
			std::istringstream ss(rateStr);
			ss >> rate;
			if (rate < 0) {
				printError("not a positive number: " + ss.str());
				continue;
			}
			else if (rate > 1000) {
				printError("too large a number: " + ss.str());
				continue;
			}
		}
		result = rate * this->_btcRates.at(date);
	
		this->_data.insert(this->_data.end(), std::make_pair(date, rate));
		std::cout << date << " => " << rate << " => " << result << std::endl;
	}
	file.close();
}

void  BitcoinExchange::printError(const std::string& message) const {
	std::cerr << "Error: " << message << std::endl;
}

bool BitcoinExchange::validateDate(const std::string& date) const {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	int year = atoi(yearStr.c_str());
	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());
	if (!isValidDate(day, month, year)) {
		return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int day, int month, int year) const {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;

    return true;
}