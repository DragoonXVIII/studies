#include "bankaccount.h"

BankAccount::BankAccount(const std::string& lastName, const std::string& accountNumber, double initialBalance)
    : last_name(lastName), account_number(accountNumber), balance(initialBalance) {};

void BankAccount::setLastName(const std::string& lastName)
{
    last_name = lastName;
}

std::string BankAccount::getLastName() const
{
    return last_name;
}

void BankAccount::setAccountNumber(const std::string& accountNumber)
{
    account_number = accountNumber;
}

std::string BankAccount::getAccountNumber() const
{
    return account_number;
}

void BankAccount::setBalance(double newBalance)
{
    balance = newBalance;
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::add(double amount)
{
    if(amount <= 0) throw std::invalid_argument("Kwota musi byc dodatnia");
    balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if(amount <= 0) throw std::invalid_argument("Kwota musi byc dodatnia");
    if(balance - amount < 0) throw std::invalid_argument("Saldo nie wystarcza");
    balance -= amount;
}

bool BankAccount::isMillionaire() const
{
    return balance >= 1000000;
}
