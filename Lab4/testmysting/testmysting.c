#include "unity.h"
#include "../../Lab4/mysting.h"

void setUp() {} //Nothing to do yet
void tearDown() {} //Nothing to do yet

void Test_memchr(void)
{
    char* res=mystr_memchr("hello",'h',sizeof("hello"));
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('h',*res,"Find in first char");
    res=mystr_memchr("hello",'o',sizeof("hello"));
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('o',*res,"Find in last char");
    res=mystr_memchr("hello",'l',sizeof("hello"));
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_CHAR_MESSAGE('l',*res,"Find in middle char");
    res=mystr_memchr("hello",'k',sizeof("hello"));
    TEST_ASSERT_NULL_MESSAGE(res,"Char not found in string");
}
void  Test_memcmp(void)
{
  int a[4]={10,9,8},b[4]={7,6,3},c[4]={10,0,8};
  int res=mystr_memcmp(a,b,4);
  TEST_ASSERT_GREATER_THAN_INT_MESSAGE(0,res,"Fisrst is bigger");
  res=mystr_memcmp(b,a,4);
  TEST_ASSERT_LESS_THAN_INT_MESSAGE(0,res,"Second is bigger");
   res=mystr_memcmp(c,a,4);
  TEST_ASSERT_EQUAL_INT_MESSAGE(0,res,"Both Equal");
}
void  Test_memcpy(void)
{
  int a[4]={10,9,8},b[4]={7,6,3};
  mystr_memcpy(a,b,4);
  TEST_ASSERT_EQUAL_MEMORY_MESSAGE(a,b,sizeof(a),"Copy one array into another.");
  
}


// void test_AverageThreeBytes_should_AverageHighValues(void)
// {
//   TEST_ASSERT_EQUAL_HEX8(80, AverageThreeBytes(70, 80, 90));
//   TEST_ASSERT_EQUAL_HEX8(127, AverageThreeBytes(127, 127, 127));
//   TEST_ASSERT_EQUAL_HEX8(84, AverageThreeBytes(0, 126, 126));
// }

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(Test_memchr);
  RUN_TEST(Test_memcmp);
  RUN_TEST(Test_memcpy);
  return UNITY_END();
}