#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



#include "unit_tests.h"
#include "simple_macros.h"




// -----------------  SET_BIT  -----------------
int test_SET_BIT_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    SET_BIT(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_BIT_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    SET_BIT(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_BIT_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    SET_BIT(reg, 1);

    if(reg != 2)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_BIT_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg;
    int i;


    for(i = 0; i < 32; i++)
    {
        reg = 0;
        SET_BIT(reg, i);

        if( reg != (1 << i) )
            return TEST_BROKEN;
    }


    return TEST_PASSED;
}



int test_SET_BIT_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;
    int i;


    for(i = 0; i < 32; i++)
    {

        SET_BIT(reg, i);

        if( reg != 0xFFFFFFFF )
            return TEST_BROKEN;
    }


    return TEST_PASSED;
}



// -----------------  CLR_BIT  -----------------
int test_CLR_BIT_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    CLR_BIT(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_BIT_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    CLR_BIT(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_BIT_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    CLR_BIT(reg, 1);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_BIT_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0;
    int i;


    for(i = 0; i < 32; i++)
    {

        CLR_BIT(reg, i);

        if( reg != 0 )
            return TEST_BROKEN;
    }


    return TEST_PASSED;
}



int test_CLR_BIT_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;
    int i;


    for(i = 0; i < 32; i++)
        CLR_BIT(reg, i);


    if( reg != 0 )
        return TEST_BROKEN;


    return TEST_PASSED;
}



// -----------------  INV_BIT  -----------------
int test_INV_BIT_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    INV_BIT(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_BIT_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    INV_BIT(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_BIT_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 2;


    INV_BIT(reg, 1);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_BIT_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0;
    int i;


    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);


    if( reg != 0xFFFFFFFF )
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_BIT_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;
    int i;


    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);


    if( reg != 0 )
        return TEST_BROKEN;


    return TEST_PASSED;
}



//==============================================================================



// -----------------  SET_FLAG  -----------------
int test_SET_FLAG_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    SET_FLAG(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_FLAG_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    SET_FLAG(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_FLAG_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    SET_FLAG(reg, 1);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_SET_FLAG_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg;
    int i;


    for(i = 0; i < 32; i++)
    {
        reg = 0;
        SET_FLAG(reg, i);

        if( reg != i )
            return TEST_BROKEN;
    }


    return TEST_PASSED;
}



int test_SET_FLAG_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;
    int i;


    for(i = 0; i < 32; i++)
    {

        SET_FLAG(reg, i);

        if( reg != 0xFFFFFFFF )
            return TEST_BROKEN;
    }


    return TEST_PASSED;
}



// -----------------  CLR_FLAG  -----------------
int test_CLR_FLAG_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    CLR_FLAG(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_FLAG_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    CLR_FLAG(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_FLAG_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    CLR_FLAG(reg, 1);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_CLR_FLAG_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xAA55AA55;


    CLR_FLAG(reg, 0xAA55AA55);

    if( reg != 0 )
        return TEST_BROKEN;



    return TEST_PASSED;
}



int test_CLR_FLAG_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;


    CLR_FLAG(reg, 0xAA55AA55);

    if( reg != 0x55AA55AA )
        return TEST_BROKEN;


    return TEST_PASSED;
}



// -----------------  INV_FLAG  -----------------
int test_INV_FLAG_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 0;


    INV_FLAG(reg, 0);

    if(reg != 0)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_FLAG_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 1;


    INV_FLAG(reg, 0);

    if(reg != 1)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_FLAG_3(struct test_info_t  *test_info)
{

    TEST_INIT;

    unsigned int reg = 2;


    INV_FLAG(reg, 1);

    if(reg != 3)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_FLAG_4(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0;


    INV_FLAG(reg, 0xAA55AA55);


    if( reg != 0xAA55AA55 )
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_INV_FLAG_5(struct test_info_t  *test_info)
{

    TEST_INIT;

    uint32_t reg = 0xFFFFFFFF;


    INV_FLAG(reg, 0xAA55AAFF);


    if( reg != 0x55AA5500 )
        return TEST_BROKEN;


    return TEST_PASSED;
}



// -----------------  ALIGNMENT  -----------------
int test_ALIGNMENT_1(struct test_info_t  *test_info)
{

    TEST_INIT;


    if(ALIGNMENT(1, 2) != 2)
        return TEST_BROKEN;


    return TEST_PASSED;
}



int test_ALIGNMENT_2(struct test_info_t  *test_info)
{

    TEST_INIT;

    int i;

    for( i = 0; i < 4096; i++)
    {

        if(ALIGNMENT(i, 4096) != 4096)
            return TEST_BROKEN;
    }


    return TEST_PASSED;
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



int main(void)
{

    RUN_TESTS(tests);

    return 0;
}

