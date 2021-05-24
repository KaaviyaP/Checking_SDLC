
#include "unity.h"
#include "virtual_cricket.h"


#include "unity.h"
#include "virtual_cricket.h"


#include "virtual_cricket.h"
#define PROJECT_NAME    "virtual_cricket"

/* Prototypes for all the test functions */
void test_validateID(void);



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


  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Test function to check resistor4 */ 
void test_validateID(void) {
  TEST_ASSERT_EQUAL(1, validateID(1,1,1));
}




