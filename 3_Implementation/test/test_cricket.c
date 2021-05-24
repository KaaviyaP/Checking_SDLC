
#include "unity.h"
#include "virtual_cricket.h"


#include "virtual_cricket.h"
#define PROJECT_NAME    "virtual_cricket"

/* Prototypes for all the test functions */
void test_validateID(void);
void test_checkIDRange(void);

void test_checktossTeam(void);
void test_checktossChoice(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_validateID);
  RUN_TEST(test_checkIDRange);
  
  RUN_TEST(test_validateID);
  RUN_TEST(test_checktossChoice);


  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Test function to check resistor4 */ 
void test_validateID(void) {
  TEST_ASSERT_EQUAL(1, validateID(1,1,1));
}

void test_checkIDRange(void)
{
  TEST_ASSERT_EQUAL(1,checkIDRange(8));
  TEST_ASSERT_EQUAL(1,checkIDRange(1));
  TEST_ASSERT_EQUAL(1,checkIDRange(5));
  TEST_ASSERT_EQUAL(0,checkIDRange(-1));
  TEST_ASSERT_EQUAL(0,checkIDRange(11));
}

void test_checktossTeam(void)
{
  TEST_ASSERT_EQUAL(1,checktossTeam("TeamA"));
  TEST_ASSERT_EQUAL(1,checktossTeam("TeamB"));
  TEST_ASSERT_EQUAL(0,checktossTeam("TeamC"));                                                                    
}

void test_checktossChoice(void)
{
  TEST_ASSERT_EQUAL(1,checktossChoice("BAT"));
  TEST_ASSERT_EQUAL(1,checktossChoice("BOWL"));
  TEST_ASSERT_EQUAL(0,checktossChoice("XYZ"));
}

