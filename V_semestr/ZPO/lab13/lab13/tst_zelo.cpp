
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <cmath>
#include <stdexcept>

double reciprocal(double number)
{
    if (number == 0.0)
    {
        throw std::invalid_argument("Cannot calculate reciprocal of zero.");
    }
    return 1.0 / number;
}

bool isPrime(int number)
{
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(number); i += 6)
    {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

using namespace testing;

TEST(elo, zelo)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

//zad1
TEST(PrimeTest, NegativeNumbers) //liczb !pierwsze
{
    EXPECT_FALSE(isPrime(-5));
    EXPECT_FALSE(isPrime(-1));
}

TEST(PrimeTest, NonPrimeNumbers) //liczb !pierwsze
{
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(9));
}

TEST(PrimeTest, SmallPrimeNumbers) //liczb pierwsze
{
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
}

TEST(PrimeTest, LargePrimeNumbers) //liczb pierwsze
{
    EXPECT_TRUE(isPrime(17));
    EXPECT_TRUE(isPrime(19));
    EXPECT_TRUE(isPrime(97));
    EXPECT_TRUE(isPrime(101));
}

TEST(PrimeTest, LargeNonPrimeNumbers) //liczb !pierwsze
{
    EXPECT_FALSE(isPrime(100));
    EXPECT_FALSE(isPrime(102));
    EXPECT_FALSE(isPrime(104));
}

//zad2
TEST(ReciprocalTest, PositiveNumbers)
{
    EXPECT_DOUBLE_EQ(reciprocal(2.0), 0.5);    // 1 / 2 = 0.5
    EXPECT_DOUBLE_EQ(reciprocal(4.0), 0.25);   // 1 / 4 = 0.25
}

TEST(ReciprocalTest, NegativeNumbers)
{
    EXPECT_DOUBLE_EQ(reciprocal(-2.0), -0.5);  // 1 / -2 = -0.5
    EXPECT_DOUBLE_EQ(reciprocal(-4.0), -0.25); // 1 / -4 = -0.25
}

TEST(ReciprocalTest, FractionalNumbers)
{
    EXPECT_DOUBLE_EQ(reciprocal(0.5), 2.0);    // 1 / 0.5 = 2
    EXPECT_DOUBLE_EQ(reciprocal(-0.25), -4.0); // 1 / -0.25 = -4
}

TEST(ReciprocalTest, ZeroInputThrowsException)
{
    EXPECT_THROW(reciprocal(0.0), std::invalid_argument); //wyjatek z zadania ze 0
}

