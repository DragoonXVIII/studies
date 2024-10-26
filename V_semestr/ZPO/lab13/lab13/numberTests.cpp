#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "number.h"

using namespace testing;

struct NumberTest:Test
{
        Number *n;
        NumberTest()
        {
            n=new Number(4);
        }

        ~NumberTest()
        {
            delete n;
        }
};

TEST_F(NumberTest,NumberInc)
{
    EXPECT_EQ(5,n->inc());
}

TEST_F(NumberTest,NumberGet)
{
    EXPECT_EQ(4,n->getN());
}

struct NumberState
{
    int inc;
    int nInit;
};

struct NumberParamTest: NumberTest, WithParamInterface<NumberState>
{
    NumberParamTest()
    {
        n->setN(GetParam().nInit);
    }
};

/*
TEST_P(NumberParamTest, NTests)
{
    NumberState as=GetParam();
    int inc=n->inc();
    EXPECT_EQ(as.inc,inc);
}

INSTANTIATE_TEST_SUITE_P(Default, NumberParamTest,
                         Values(NumberState{4,5}, NumberState{3,7}));
*/
/*
INSTANTIATE_TEST_CASE_P(Default, NumberParamTest,
                        Values(NumberState{4,5}, NumberState{3,4}));
*/
