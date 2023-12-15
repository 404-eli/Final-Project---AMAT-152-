
#include "fun.h"
#include "unity.h"
#include "struct.h"

void test_deleterecords(void);
void test_searchrecords(void);
void test_addrecords(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_deleterecords);
  RUN_TEST(test_searchrecords);
  RUN_TEST(test_addrecords);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_deleterecords(void)
{
    char smartcardnumber[20]="KHY123456";
    TEST_ASSERT_EQUAL("KHY123456", smartcardnumber);
   
}

void test_searchrecords(void)
{
    char smartcardnumber[20]="KHY123456";
    TEST_ASSERT_EQUAL("KHY123456", smartcardnumber);
   
}

void test_addrecords(void)
{
    char smartcardnumber[20]="KHY123456";

    char name[20]="SOOGURESH";

    char amount [20]="1000";

 TEST_ASSERT_EQUAL("KHY123456",smartcardnumber);
 TEST_ASSERT_EQUAL("SOOGURESH", name);
 TEST_ASSERT_EQUAL("1000", amount);
   
}

