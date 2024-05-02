/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:13:11 by misargsy          #+#    #+#             */
/*   Updated: 2024/05/02 21:15:10 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void	Account::_displayTimestamp(void) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::cout
		<< "[" 
		<< now->tm_year + 1900
		<< (now->tm_mon < 9 ? "0" : "") << now->tm_mon + 1
		<< (now->tm_mday < 10 ? "0" : "") << now->tm_mday
		<< "_"
		<< (now->tm_hour < 10 ? "0" : "") << now->tm_hour
		<< (now->tm_min < 10 ? "0" : "") << now->tm_min
		<< (now->tm_sec < 10 ? "0" : "") << now->tm_sec
		<< "]";
}

Account::Account(void) {
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created"
		<< std::endl;
}

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account:: displayAccountsInfos(void) {
	_displayTimestamp();

	std::cout
		<< " "
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	
	std::cout << " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	
	std::cout << " "
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";";
		
	_totalAmount += deposit;
	_amount += deposit;

	std::cout
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	
	std::cout << " "
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";";
		
	if (_amount < withdrawal) {
		std::cout
			<< "withdrawal:refused"
			<< std::endl;
		return false;
	}

	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;

	return true;
}

int	Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();

	std::cout << " "
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
}
