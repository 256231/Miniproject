#include"unity.h"
#include"unity_internals.h"
#include"header.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
void ghost1_direction_test()
{
    TEST_ASSERT_EQUAL(1,ghost1_direction(1));
}

/*void ghost2_direction_test()
    {
        TEST_ASSERT_EQUAL(1,ghost2_direction(1));
    }*/

int main()
{
   UNITY_BEGIN();
    RUN_TEST(ghost1_direction_test);
    RUN_TEST(ghost2_direction_test);
    return UNITY_END();

}