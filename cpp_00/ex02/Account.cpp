/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:25:20 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/20 11:30:56 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "created" << endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "closed" << endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	cout << "nb_deposits:" << this->_nbDeposits << endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	this->_amount -= withdrawal;
	if (checkAmount())
	{
		this->_amount += withdrawal;
		cout << "withdrawal:refused" << endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	cout << "withdrawal:" << withdrawal << ";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	cout << "amount:" << this->_amount << ";";
	cout << "nb_withdrawals:" << this->_nbWithdrawals << endl;
	return true;
}

int	Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return 1;
	return 0;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals << endl;
	return ;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:" << Account::_nbAccounts << ";";
	cout << "total:" << Account::_totalAmount << ";";
	cout << "deposits:" << Account::_totalNbDeposits << ";";
	cout << "withdrawals:" << Account::_totalNbWithdrawals << endl;
	return ;
}

void	Account::_displayTimestamp()
{
	time_t		time;
	struct tm	*t_stmp;

	std::time(&time);
	t_stmp = localtime(&time);
	cout << "[";
	cout << t_stmp->tm_year + 1900;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
	cout << "] ";
	return ;
}
