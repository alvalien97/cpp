#include "Account.hpp"
#include <iostream>
#include <ctime>

// Variables estáticas globales
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit) {
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

// Destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

// Deposit
void Account::makeDeposit(int deposit) {
    int previous = _amount;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

// Withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    int previous = _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << previous;

    if (withdrawal > _amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

// Display account status
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

// Display all accounts info (static)
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

// Timestamp utility
void Account::_displayTimestamp() {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    std::cout << "[";

    std::cout << timeinfo->tm_year + 1900;

    if (timeinfo->tm_mon + 1 < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mon + 1;

    if (timeinfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mday;

    std::cout << "_";

    if (timeinfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_hour;

    if (timeinfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_min;

    if (timeinfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_sec;

    std::cout << "] ";
}
