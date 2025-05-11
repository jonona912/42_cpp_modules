#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( void ) {
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit ) {
	if (deposit > 0) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal <= 0 || withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t now = std::time(nullptr);
	std::tm *local = std::localtime(&now);
	std::cout << "[" << (local->tm_year + 1900)
	          << std::setw(2) << std::setfill('0') << (local->tm_mon + 1)
	          << std::setw(2) << std::setfill('0') << local->tm_mday << "_"
	          << std::setw(2) << std::setfill('0') << local->tm_hour
	          << std::setw(2) << std::setfill('0') << local->tm_min
	          << std::setw(2) << std::setfill('0') << local->tm_sec << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
