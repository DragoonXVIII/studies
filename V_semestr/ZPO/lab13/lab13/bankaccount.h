#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <stdexcept>

class BankAccount
{
private:
    std::string last_name;
    std::string account_number;
    double balance;

public:

    BankAccount(const std::string& lastName, const std::string& accountNumber, double initialBalance);

    void setLastName(const std::string& lastName);
    std::string getLastName() const;
    void setAccountNumber(const std::string& accountNumber);
    std::string getAccountNumber() const;
    void setBalance(double newBalance);
    double getBalance() const;

    void add(double amount);
    void withdraw(double amount);
    bool isMillionaire() const;
};


#endif // BANKACCOUNT_H
