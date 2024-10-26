#include <gtest/gtest.h>
#include "bankaccount.h"

// Testy get,set,budowniczych(zawsze da rade)
TEST(BankAccountTest, ConstructorAndAccessors)
{
    BankAccount account("Smith", "1234567890", 500.0);

    EXPECT_EQ(account.getLastName(), "Smith");
    EXPECT_EQ(account.getAccountNumber(), "1234567890");
    EXPECT_DOUBLE_EQ(account.getBalance(), 500.0);
}

// Testy  add
TEST(BankAccountTest, AddPositiveAmount)
{
    BankAccount account("Doe", "1111111111", 200.0);
    account.add(300.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 500.0);
}
TEST(BankAccountTest, AddNegativeAmountThrowsException)
{
    BankAccount account("Doe", "1111111111", 200.0);
    EXPECT_THROW(account.add(-100.0), std::invalid_argument);
}

// Testy  withdraw
TEST(BankAccountTest, WithdrawValidAmount)
{
    BankAccount account("Doe", "1111111111", 500.0);
    account.withdraw(200.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 300.0);
}

TEST(BankAccountTest, WithdrawInvalidAmountThrowsException)
{
    BankAccount account("Doe", "1111111111", 200.0);
    EXPECT_THROW(account.withdraw(300.0), std::invalid_argument);  // Saldo niewystarczające
    EXPECT_THROW(account.withdraw(-50.0), std::invalid_argument);  // Kwota ujemna
}

// Testy  isMillionaire
TEST(BankAccountTest, IsMillionaireTrue)
{
    BankAccount account("Doe", "1111111111", 1000000.0);
    EXPECT_TRUE(account.isMillionaire());
}

TEST(BankAccountTest, IsMillionaireFalse) {
    BankAccount account("Doe", "1111111111", 999999.99);
    EXPECT_FALSE(account.isMillionaire());
}

//kocham stacka,dzk
/*class ToBeTested
{
protected:
    bool SensitiveInternal(int p1, int p2); // Still needs testing
}

// Google-test:
class ToBeTestedFixture : public ToBeTested, public testing::Test
{
   // Empty - bridge to protected members for unit-testing
}

TEST_F(ToBeTestedFixture, TestSensitive)
{
    ASSERT_TRUE(SensitiveInternal(1, 1));
    ASSERT_FALSE(SensitiveInternal(-1, -1));
}*/



// Testy parametryczne add
class AddTest : public ::testing::TestWithParam<double> {};

TEST_P(AddTest, AddVariousAmounts)
{
    BankAccount account("Test", "2222222222", 500.0);
    double amount = GetParam();
    if(amount > 0)
    {
        account.add(amount);
        EXPECT_DOUBLE_EQ(account.getBalance(), 500.0 + amount);
    }
    else
    {
        EXPECT_THROW(account.add(amount), std::invalid_argument);
    }
}

INSTANTIATE_TEST_SUITE_P(ValidAndInvalidAmounts, AddTest, ::testing::Values(100.0, 0.0, -50.0));

// Testy parametryczne withdraw
class WithdrawTest : public ::testing::TestWithParam<double> {};

TEST_P(WithdrawTest, WithdrawVariousAmounts) {
    BankAccount account("Test", "2222222222", 500.0);
    double amount = GetParam();
    if(amount > 0 && amount <= 500.0)
    {
        account.withdraw(amount);
        EXPECT_DOUBLE_EQ(account.getBalance(), 500.0 - amount);
    }
    else
    {
        EXPECT_THROW(account.withdraw(amount), std::invalid_argument);
    }
}

INSTANTIATE_TEST_SUITE_P(ValidAndInvalidAmounts, WithdrawTest, ::testing::Values(100.0, 500.0, 600.0, -50.0));
