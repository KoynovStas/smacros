#include <stdint.h>

#include "stest.h"
#include "smacros.h"





// -----------------  SET_BIT  -----------------
TEST(test_SET_BIT_1)
{
    unsigned int reg = 0;

    SET_BIT(reg, 0);
    TEST_ASSERT(reg == 1);

    SET_BIT(reg, 0);
    TEST_ASSERT(reg == 1);

    TEST_PASS(NULL);
}



TEST(test_SET_BIT_2)
{
    unsigned int reg = 2;

    SET_BIT(reg, 0);
    TEST_ASSERT(reg == 3);

    SET_BIT(reg, 0);
    TEST_ASSERT(reg == 3);

    SET_BIT(reg, 1);
    TEST_ASSERT(reg == 3);

    TEST_PASS(NULL);
}



TEST(test_SET_BIT_3)
{
    unsigned int reg = 0;

    SET_BIT(reg, 1);
    TEST_ASSERT(reg == 2);

    SET_BIT(reg, 1);
    TEST_ASSERT(reg == 2);

    SET_BIT(reg, 0);
    TEST_ASSERT(reg == 3);

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

        TEST_ASSERT( reg == (1u << i)   );
        TEST_ASSERT( reg == BIT_FLAG(i) );
    }


    uint64_t reg64;
    for(i = 0; i < 64; i++)
    {
        reg64 = 0;
        SET_BIT(reg64, i);

        TEST_ASSERT( reg64 == ((uint64_t)1 << i) );
        TEST_ASSERT( reg64 == BIT_FLAG(i)        );
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


    uint64_t reg64 = 0xFFFFFFFFFFFFFFFFull;
    for(i = 0; i < 64; i++)
    {
        SET_BIT(reg64, i);
        TEST_ASSERT( reg64 == 0xFFFFFFFFFFFFFFFFull );
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


    uint64_t reg64 = 0xFFFFFFFFFFFFFFFF;

    for(i = 0; i < 64; i++)
        CLR_BIT(reg64, i);

    TEST_ASSERT( reg64 == 0 );

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

    INV_BIT(reg, 0);
    TEST_ASSERT(reg == 1);

    TEST_PASS(NULL);
}



TEST(test_INV_BIT_3)
{
    unsigned int reg = 2;

    INV_BIT(reg, 1);
    TEST_ASSERT(reg == 0);

    INV_BIT(reg, 1);
    TEST_ASSERT(reg == 2);

    TEST_PASS(NULL);
}



TEST(test_INV_BIT_4)
{
    uint32_t reg = 0;
    int i;

    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);

    TEST_ASSERT( reg == 0xFFFFFFFF );


    uint64_t reg64 = 0;
    for(i = 0; i < 64; i++)
        INV_BIT(reg64, i);

    TEST_ASSERT( reg64 == 0xFFFFFFFFFFFFFFFFull );


    TEST_PASS(NULL);
}



TEST(test_INV_BIT_5)
{
    uint32_t reg = 0xFFFFFFFF;
    int i;

    for(i = 0; i < 32; i++)
        INV_BIT(reg, i);

    TEST_ASSERT( reg == 0 );


    uint64_t reg64 = 0xFFFFFFFFFFFFFFFFull;
    for(i = 0; i < 64; i++)
        INV_BIT(reg64, i);

    TEST_ASSERT( reg64 == 0 );


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


    uint64_t reg64 = 0xAA55AA55AA55AA55ull;

    CLR_FLAG(reg64, 0xAA55AA55AA55AA55ull);
    TEST_ASSERT( reg64 == 0 );


    TEST_PASS(NULL);
}



TEST(test_CLR_FLAG_5)
{
    uint32_t reg = 0xFFFFFFFF;

    CLR_FLAG(reg, 0xAA55AA55);
    TEST_ASSERT( reg == 0x55AA55AA );


    uint64_t reg64 = 0xFFFFFFFFFFFFFFFFull;

    CLR_FLAG(reg64, 0xAA55AA55AA55AA55ull);
    TEST_ASSERT( reg64 == 0x55AA55AA55AA55AAull );


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


    uint64_t reg64 = 0;

    INV_FLAG(reg64, 0xAA55AA55AA55AA55ull);
    TEST_ASSERT( reg64 == 0xAA55AA55AA55AA55ull );


    TEST_PASS(NULL);
}



TEST(test_INV_FLAG_5)
{
    uint32_t reg = 0xFFFFFFFF;

    INV_FLAG(reg, 0xAA55AAFF);
    TEST_ASSERT( reg == 0x55AA5500 );


    uint64_t reg64 = 0xFFFFFFFFFFFFFFFFull;

    INV_FLAG(reg64, 0xAA55AAFFAA55AAFFull);
    TEST_ASSERT( reg64 == 0x55AA550055AA5500ull );


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



TEST(test_CHECK_FLAG)
{
    uint32_t i32 = 0xFF002200;
    TEST_ASSERT(CHECK_FLAG_ALL(i32, 0xFF000000));
    TEST_ASSERT(CHECK_FLAG_ALL(i32, 0xF0000000));
    TEST_ASSERT(CHECK_FLAG_ALL(i32, 0xFF002200));
    TEST_ASSERT(CHECK_FLAG_ALL(i32, 0x00002200));
    TEST_ASSERT(!CHECK_FLAG_ALL(i32, 0xFF00FF00));

    TEST_ASSERT(CHECK_FLAG_ANY(i32, 0xFF000000));
    TEST_ASSERT(CHECK_FLAG_ANY(i32, 0xF0000000));
    TEST_ASSERT(CHECK_FLAG_ANY(i32, 0xFF002200));
    TEST_ASSERT(CHECK_FLAG_ANY(i32, 0x00002200));
    TEST_ASSERT(CHECK_FLAG_ANY(i32, 0xFF00FF00));

    TEST_ASSERT(!CHECK_FLAG_NONE(i32, 0xFF000000));
    TEST_ASSERT(!CHECK_FLAG_NONE(i32, 0xF0000000));
    TEST_ASSERT(!CHECK_FLAG_NONE(i32, 0xFF002200));
    TEST_ASSERT(!CHECK_FLAG_NONE(i32, 0x00002200));
    TEST_ASSERT(!CHECK_FLAG_NONE(i32, 0xFF00FF00));

    TEST_ASSERT(CHECK_FLAG_NONE(i32, 0x00FF0000));


    uint64_t i64 = 0xFF002200FF002200ull;
    TEST_ASSERT( CHECK_FLAG_ALL(i64, 0xFF00000000002200ull));
    TEST_ASSERT( CHECK_FLAG_ALL(i64, 0xF000000000000200ull));
    TEST_ASSERT( CHECK_FLAG_ALL(i64, 0xFF00220000000000ull));
    TEST_ASSERT( CHECK_FLAG_ALL(i64, 0x0000220000000000ull));
    TEST_ASSERT(!CHECK_FLAG_ALL(i64, 0xFF00FF0000000000ull));

    TEST_ASSERT(CHECK_FLAG_ANY(i64, 0xFF00000000000000ull));
    TEST_ASSERT(CHECK_FLAG_ANY(i64, 0xF000000000000000ull));
    TEST_ASSERT(CHECK_FLAG_ANY(i64, 0xFF00220000000000ull));
    TEST_ASSERT(CHECK_FLAG_ANY(i64, 0x0000220000000000ull));
    TEST_ASSERT(CHECK_FLAG_ANY(i64, 0xFF00FF0000000000ull));

    TEST_ASSERT(!CHECK_FLAG_NONE(i64, 0xFF00000000000000ull));
    TEST_ASSERT(!CHECK_FLAG_NONE(i64, 0xF000000000000000ull));
    TEST_ASSERT(!CHECK_FLAG_NONE(i64, 0xFF00220000000000ull));
    TEST_ASSERT(!CHECK_FLAG_NONE(i64, 0x0000220000000000ull));
    TEST_ASSERT(!CHECK_FLAG_NONE(i64, 0xFF00FF0000000000ull));

    TEST_ASSERT(CHECK_FLAG_NONE(i64, 0x00FF000000000000ull));

    TEST_PASS(NULL);
}



TEST(test_MODIFY_REG)
{
    uint32_t i = 0xFF0022;

    TEST_ASSERT(MODIFY_REG(i, 0xFF0000, 0x120000) == 0x120022);

    i = 0xFF0022;
    TEST_ASSERT(MODIFY_REG(i, 0xF00000, 0x500000) == 0x5F0022);

    i = 0xFF0022;
    TEST_ASSERT(MODIFY_REG(i, 0xFF0022, 0xAA0000) == 0xAA0000);

    i = 0xFF0022;
    TEST_ASSERT(MODIFY_REG(i, 0x000022, 0x000000) == 0xFF0000);

    i = 0xFF0022;
    TEST_ASSERT(MODIFY_REG(i, 0xFF00FF, 0x2200FF) == 0x2200FF);


    TEST_ASSERT(MODIFY_REG(i, 0xF00000, 0x500000) == 0x5200FF);
    TEST_ASSERT(MODIFY_REG(i, 0xFF0022, 0xAA0000) == 0xAA00DD);
    TEST_ASSERT(MODIFY_REG(i, 0x000022, 0x000000) == 0xAA00DD);
    TEST_ASSERT(MODIFY_REG(i, 0xFF00FF, 0x2200FF) == 0x2200FF);
    TEST_ASSERT(MODIFY_REG(i, 0x00FF00, 0x22AAFF) == 0x22AAFF);



    uint64_t i64 = 0xFF002200FF002200ull;

    TEST_ASSERT(MODIFY_REG(i64, 0xFF000000ull, 0x12000000ull) == 0xFF00220012002200ull);

    i64 = 0xFF002200FF002200ull;
    TEST_ASSERT(MODIFY_REG(i64, 0xF0000000ull, 0x50000000ull) == 0xFF0022005F002200ull);

    i64 = 0xFF002200FF002200ull;
    TEST_ASSERT(MODIFY_REG(i64, 0xFF002200ull, 0xAA000000ull) == 0xFF002200AA000000ull);

    i64 = 0xFF002200FF002200ull;
    TEST_ASSERT(MODIFY_REG(i64, 0x00002200ull, 0x00000000ull) == 0xFF002200FF000000ull);

    i64 = 0xFF002200FF002200ull;
    TEST_ASSERT(MODIFY_REG(i64, 0xFF00FF00ull, 0x2200FF00ull) == 0xFF0022002200FF00ull);


    TEST_ASSERT(MODIFY_REG(i64, 0xF0000000ull, 0x50000000ull) == 0xFF0022005200FF00ull);
    TEST_ASSERT(MODIFY_REG(i64, 0xFF002200ull, 0xAA000000ull) == 0xFF002200AA00DD00ull);
    TEST_ASSERT(MODIFY_REG(i64, 0x00002200ull, 0x00000000ull) == 0xFF002200AA00DD00ull);
    TEST_ASSERT(MODIFY_REG(i64, 0xFF00FF00ull, 0x2200FF00ull) == 0xFF0022002200FF00ull);
    TEST_ASSERT(MODIFY_REG(i64, 0x00FF0000ull, 0x22AAFF00ull) == 0xFF00220022AAFF00ull);

    TEST_PASS(NULL);
}


stest_func tests[] =
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

    test_CHECK_FLAG,
    test_MODIFY_REG,
};



MAIN_TESTS(tests)
