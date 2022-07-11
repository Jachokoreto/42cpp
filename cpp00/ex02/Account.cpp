/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:31:26 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 03:36:39 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// [19920104_091532] index:4;amount:1234;created
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "index:" << this->_accountIndex << "; "
			  << "amount:" << this->_amount << ";"
			  << "created" << std::endl;
}

// static int closedAccount = 0;
Account::~Account(void)
{
	// while (this->_accountIndex >= closedAccount)
	// 	;
	// closedAccount++;
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "index:" << this->_accountIndex << "; "
			  << "amount:" << this->_amount << ";"
			  << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "accounts:" << Account::getNbAccounts() << ";"
			  << "total:" << Account::getTotalAmount() << ";"
			  << "deposits:" << Account::getNbDeposits() << ";"
			  << "withdrawals:" << Account::getNbWithdrawals() << ";" << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount - deposit << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "\t"
				  << "index:" << this->_accountIndex << ";"
				  << "p_amount:" << this->_amount << ";"
				  << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount + withdrawal << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (0);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "\t"
			  << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout << std::time(nullptr);
}
