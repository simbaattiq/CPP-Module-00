/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:38:29 by mel-atti          #+#    #+#             */
/*   Updated: 2025/01/07 23:39:31 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";" ;
    std::cout << "total:" << getTotalAmount() << ";" ;
    std::cout << "deposits:" << getNbDeposits() << ";" ;
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << checkAmount() << ";" ;
    std::cout << "created" << std::endl ;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "amount:" << checkAmount() << ";" ;
    std::cout << "closed" << std::endl ;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "p_amount:" << checkAmount() << ";" ;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "deposit:" << deposit << ";" ;
    std::cout << "amount:" << checkAmount() << ";" ;
    std::cout << "nb_deposits:" << this->_nbDeposits ;
    std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "index:" << this->_accountIndex << ";" ;
        std::cout << "p_amount:" << checkAmount() << ";" ;
        std::cout << "withdrawal:refused" << std::endl ;
        return (false);
    }
    int new_amount = this->_amount - withdrawal;
    std::cout << "index:" << this->_accountIndex << ";" ;
    std::cout << "p_amount:" << checkAmount() << ";" ;
    std::cout << "withdrawal:" << withdrawal << ";" ;
    this->_amount = new_amount;
    std::cout << "amount:" << checkAmount() << ";" ;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << "nb_withdrawal:" << this->_nbWithdrawals << std::endl ;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *localTime = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer << " " ;
}
