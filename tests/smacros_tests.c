#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "stest.h"
#include "smacros.h"





// -----------------  SET_BIT  -----------------
TEST(test_SET_BIT_1)
{
    unsigned int reg = 0;

    SET_BIT(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_SET_BIT_2)
{
    unsigned int reg = 1;

    SET_BIT(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_SET_BIT_3)
{
    unsigned int reg = 0;

    SET_BIT(reg, 1);

    TEST_ASSERT(reg == 2);


    TEST_PASS(NULL);
}



TEST(test_SET_BIT_4)
{
    uint32_t reg;
    int i;

    for(i = 0; i < 32; i++)
    {
        reg = 0;
        SET_BIT(reg, i);

        TEST_ASSERT( reg == (1u << i) );
    }


    TEST_PASS(NULL);
}



TEST(test_SET_BIT_5)
{
    uint32_t reg = 0xFFFFFFFF;
    int i;

    for(i = 0; i < 32; i++)
    {
        SET_BIT(reg, i);

        TEST_ASSERT( reg == 0xFFFFFFFF );
    }


    TEST_PASS(NULL);
}



// -----------------  CLR_BIT  -----------------
TEST(test_CLR_BIT_1)
{
    unsigned int reg = 0;

    CLR_BIT(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_CLR_BIT_2)
{
    unsigned int reg = 1;

    CLR_BIT(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_CLR_BIT_3)
{
    unsigned int reg = 0;

    CLR_BIT(reg, 1);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_CLR_BIT_4)
{
    uint32_t reg = 0;
    int i;

    for(i = 0; i < 32; i++)
    {
        CLR_BIT(reg, i);

        TEST_ASSERT( reg == 0 );
    }


    TEST_PASS(NULL);
}



TEST(test_CLR_BIT_5)
{
    uint32_t reg = 0xFFFFFFFF;
    int i;

    for(i = 0; i < 32; i++)
        CLR_BIT(reg, i);


    TEST_ASSERT( reg == 0 );


    TEST_PASS(NULL);
}



// -----------------  INV_BIT  -----------------
TEST(test_INV_BIT_1)
{
    unsigned int reg = 0;

    INV_BIT(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_INV_BIT_2)
{
    unsigned int reg = 1;

    INV_BIT(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_INV_BIT_3)
{
    unsigned int reg = 2;

    INV_BIT(reg, 1);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_INV_BIT_4)
{
    uint32_t reg = 0;
    int i;

    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);

    TEST_ASSERT( reg == 0xFFFFFFFF );


    TEST_PASS(NULL);
}



TEST(test_INV_BIT_5)
{
    uint32_t reg = 0xFFFFFFFF;
    int i;

    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);

    TEST_ASSERT( reg == 0 );


    TEST_PASS(NULL);
}



//==============================================================================



// -----------------  SET_FLAG  -----------------
TEST(test_SET_FLAG_1)
{
    unsigned int reg = 0;

    SET_FLAG(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_SET_FLAG_2)
{
    unsigned int reg = 1;

    SET_FLAG(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_SET_FLAG_3)
{
    unsigned int reg = 0;

    SET_FLAG(reg, 1);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_SET_FLAG_4)
{
    uint32_t reg, i;

    for(i = 0; i < 32; i++)
    {
        reg = 0;
        SET_FLAG(reg, i);

        TEST_ASSERT( reg == i );
    }


    TEST_PASS(NULL);
}



TEST(test_SET_FLAG_5)
{
    uint32_t reg = 0xFFFFFFFF;
    int i;

    for(i = 0; i < 32; i++)
    {
        SET_FLAG(reg, i);

        TEST_ASSERT( reg == 0xFFFFFFFF );
    }


    TEST_PASS(NULL);
}



// -----------------  CLR_FLAG  -----------------
TEST(test_CLR_FLAG_1)
{
    unsigned int reg = 0;

    CLR_FLAG(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_CLR_FLAG_2)
{
    unsigned int reg = 1;

    CLR_FLAG(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_CLR_FLAG_3)
{
    unsigned int reg = 0;

    CLR_FLAG(reg, 1);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_CLR_FLAG_4)
{
    uint32_t reg = 0xAA55AA55;

    CLR_FLAG(reg, 0xAA55AA55);

    TEST_ASSERT( reg == 0 );


    TEST_PASS(NULL);
}



TEST(test_CLR_FLAG_5)
{
    uint32_t reg = 0xFFFFFFFF;

    CLR_FLAG(reg, 0xAA55AA55);

    TEST_ASSERT( reg == 0x55AA55AA );


    TEST_PASS(NULL);
}



// -----------------  INV_FLAG  -----------------
TEST(test_INV_FLAG_1)
{
    unsigned int reg = 0;

    INV_FLAG(reg, 0);

    TEST_ASSERT(reg == 0);


    TEST_PASS(NULL);
}



TEST(test_INV_FLAG_2)
{
    unsigned int reg = 1;

    INV_FLAG(reg, 0);

    TEST_ASSERT(reg == 1);


    TEST_PASS(NULL);
}



TEST(test_INV_FLAG_3)
{
    unsigned int reg = 2;

    INV_FLAG(reg, 1);

    TEST_ASSERT(reg == 3);


    TEST_PASS(NULL);
}



TEST(test_INV_FLAG_4)
{
    uint32_t reg = 0;

    INV_FLAG(reg, 0xAA55AA55);

    TEST_ASSERT( reg == 0xAA55AA55 );


    TEST_PASS(NULL);
}



TEST(test_INV_FLAG_5)
{
    uint32_t reg = 0xFFFFFFFF;

    INV_FLAG(reg, 0xAA55AAFF);

    TEST_ASSERT( reg == 0x55AA5500 );


    TEST_PASS(NULL);
}



// -----------------  ALIGNMENT  -----------------
TEST(test_ALIGNMENT_1)
{
    TEST_ASSERT(ALIGNMENT(1, 2) == 2);

    TEST_PASS(NULL);
}



TEST(test_ALIGNMENT_2)
{
    int i;

    for( i = 0; i < 4096; i++)
    {
        TEST_ASSERT(ALIGNMENT(i, 4096) == 4096);
    }


    TEST_PASS(NULL);
}



ptest_func tests[] =
{

    //SET_BIT
    test_SET_BIT_1,
    test_SET_BIT_2,
    test_SET_BIT_3,
    test_SET_BIT_4,
    test_SET_BIT_5,


    //CLR_BIT
    test_CLR_BIT_1,
    test_CLR_BIT_2,
    test_CLR_BIT_3,
    test_CLR_BIT_4,
    test_CLR_BIT_5,


    //INV_BIT
    test_INV_BIT_1,
    test_INV_BIT_2,
    test_INV_BIT_3,
    test_INV_BIT_4,
    test_INV_BIT_5,


    //=============


    //SET_FLAG
    test_SET_FLAG_1,
    test_SET_FLAG_2,
    test_SET_FLAG_3,
    test_SET_FLAG_4,
    test_SET_FLAG_5,


    //CLR_FLAG
    test_CLR_FLAG_1,
    test_CLR_FLAG_2,
    test_CLR_FLAG_3,
    test_CLR_FLAG_4,
    test_CLR_FLAG_5,


    //INV_FLAG
    test_INV_FLAG_1,
    test_INV_FLAG_2,
    test_INV_FLAG_3,
    test_INV_FLAG_4,
    test_INV_FLAG_5,


    //ALIGNMENT
    test_ALIGNMENT_1,
    test_ALIGNMENT_2,

};



MAIN_TESTS(tests)
