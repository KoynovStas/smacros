#include <stdio.h>
#include <stdlib.h>



#include "unit_tests.h"
#include "simple_macros.h"




int test_1(struct test_info_t  *test_info)
{

    TEST_INIT;

    //some code

    return TEST_PASSED;
}




ptest_func tests[] =
{

    test_1,

};



int main(void)
{

    RUN_TESTS(tests);

    return 0;
}

