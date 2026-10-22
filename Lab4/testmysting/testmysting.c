#include "unity.h"
#include "../../Lab4/mysting.h"

void setUp() {}    // Nothing to do yet
void tearDown() {} // Nothing to do yet

void Test_memchr(void)
{
  char *res = mystr_memchr("hello", 'h', sizeof("hello"));
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('h', *res, "Find in first char");
  res = mystr_memchr("hello", 'o', sizeof("hello"));
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('o', *res, "Find in last char");
  res = mystr_memchr("hello", 'l', sizeof("hello"));
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('l', *res, "Find in middle char");
  res = mystr_memchr("hello", 'k', sizeof("hello"));
  TEST_ASSERT_NULL_MESSAGE(res, "Char not found in string");
}
void Test_memcmp(void)
{
  int a[4] = {10, 9, 8}, b[4] = {7, 6, 3}, c[4] = {10, 0, 8};
  int res = mystr_memcmp(a, b, 4);
  TEST_ASSERT_GREATER_THAN_INT_MESSAGE(0, res, "Fisrst is bigger");
  res = mystr_memcmp(b, a, 4);
  TEST_ASSERT_LESS_THAN_INT_MESSAGE(0, res, "Second is bigger");
  res = mystr_memcmp(c, a, 4);
  TEST_ASSERT_EQUAL_INT_MESSAGE(0, res, "Both Equal");
}
void Test_memcpy(void)
{
  int a[4] = {10, 9, 8}, b[4] = {7, 6, 3};
  mystr_memcpy(a, b, sizeof(a));
  TEST_ASSERT_EQUAL_MEMORY_MESSAGE(a, b, sizeof(a), "Copy one array into another.");
}
void Test_memmove(void)
{
  char a[] = "12345";
  mystr_memmove(a + 1, a + 2, 3);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("13455", a, "memmove with overlap");
}
void Test_memset(void)
{
  char a[] = "12345";
  mystr_memset(a, 'f', 3);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("fff45", a, "memset block of memory");
}
void Test_strchr(void)
{
  char str[] = "hello";
  char *res = mystr_strchr("hello", 'h');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('h', *res, "Find in first char");
  res = mystr_strchr("hello", 'o');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('o', *res, "Find in last char");
  res = mystr_strchr("hello", 'l');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_CHAR_MESSAGE('l', *res, "Find in middle char");
  res = mystr_strchr("hello", 'k');
  TEST_ASSERT_NULL_MESSAGE(res, "Char not found in string");
}

void Test_strcat(void)
{
  char a[30] = "Hello", b[] = " World!";
  char *c = mystr_strcat(a, b);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Hello World!", c, "Sting concat");
}
void Test_strcmp(void)
{
  char a[] = "Mario", b[] = "Anas", c[] = "Mario";
  int res = mystr_strcmp(a, b);
  TEST_ASSERT_GREATER_THAN_INT_MESSAGE(0, res, "Fisrst is bigger");
  res = mystr_strcmp(b, a);
  TEST_ASSERT_LESS_THAN_INT_MESSAGE(0, res, "Second is bigger");
  res = mystr_strcmp(c, a);
  TEST_ASSERT_EQUAL_INT_MESSAGE(0, res, "Both Equal");
}
void Test_strcpy(void)
{
  char a[20] = "Hello", b[] = "No";
  mystr_strcpy(a, b);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(a, "No", "Check dest same as source");
  TEST_ASSERT_EQUAL_STRING_MESSAGE(b, "No", "Check Source not corrupted");
}
void Test_strspn(void)
{
  char str[20] = "Hello,world!", search[10] = ",!";
  int len = mystr_strspn(str, search);
  TEST_ASSERT_EQUAL_INT_MESSAGE(len, 5, "Find first in search in miidle of string");
  search[0] = '!';
  search[1] = ',';
  len = mystr_strspn(str, search);
  TEST_ASSERT_EQUAL_INT_MESSAGE(len, 5, "Find last in search in miidle of string");
  mystr_strcpy(str, ",Hello");
  len = mystr_strspn(str, search);
  TEST_ASSERT_EQUAL_INT_MESSAGE(len, 0, "Find last in search in first of string");
  mystr_strcpy(str, "Hello!");
  len = mystr_strspn(str, search);
  TEST_ASSERT_EQUAL_INT_MESSAGE(len, 5, "Find last in search in last of string");
  mystr_strcpy(str, "Hello?");
  len = mystr_strspn(str, search);
  TEST_ASSERT_EQUAL_INT_MESSAGE(len, 6, "NotFound search in string ");
}
void Test_strlen(void)
{
  char emptystr[] = "", normalstr[] = "Hellow World!";
  unsigned int len = mystr_strlen(emptystr);
  TEST_ASSERT_EQUAL_INT_MESSAGE(0, len, "Zero lenth for empty sting");
  len = mystr_strlen(normalstr);
  TEST_ASSERT_EQUAL_INT_MESSAGE(13, len, "Normal string length");
}

void Test_strncat(void)
{
  char a[30] = "Hello", b[] = " World!";
  char *c = mystr_strncat(a, b, 3);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Hello Wo", c, "Sting concat");
}
void Test_strncmp(void)
{
  char a[] = "MarioZ", b[] = "MarioB", c[] = "MarioZa";
  int res = mystr_strncmp(a, b, 6);
  TEST_ASSERT_GREATER_THAN_INT_MESSAGE(0, res, "Fisrst is bigger");
  res = mystr_strncmp(a, c, 7);
  TEST_ASSERT_LESS_THAN_INT_MESSAGE(0, res, "Second is bigger");
  res = mystr_strncmp(c, a, 6);
  TEST_ASSERT_EQUAL_INT_MESSAGE(0, res, "Both Equal");
}
void Test_strncpy(void)
{
  char a[20] = "Hello world!", b[] = "Cairo";
  mystr_strncpy(a, b, 5);
  TEST_ASSERT_EQUAL_STRING_MESSAGE(a, "Cairo world!", "Check dest same as source");
  TEST_ASSERT_EQUAL_STRING_MESSAGE(b, "Cairo", "Check Source not corrupted");
}
void Test_strrchr(void)
{
  char str[20] = "hello";
  char *res = mystr_strrchr(str, 'h');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(str, res, "Find in first char");
  mystr_strcpy(str, "oelolo");
  res = mystr_strrchr(str, 'o');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(str + 5, res, "Find in last char");

  res = mystr_strrchr(str, 'l');
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(str + 4, res, "Find in middle char");
  res = mystr_strrchr("hello", 'k');
  TEST_ASSERT_NULL_MESSAGE(res, "Char not found in string");
}
void Test_strstr(void)
{
  char tststr[] = "Hello World!";
  char *res = mystr_strstr(tststr, "He");
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(tststr, res, "Find at first");
  res = mystr_strstr(tststr, "o W");
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(tststr + 4, res, "Find at middle");
  res = mystr_strstr(tststr, "ld!");
  TEST_ASSERT_NOT_NULL(res);
  TEST_ASSERT_EQUAL_PTR_MESSAGE(tststr + 9, res, "Find at last");
  res = mystr_strstr(tststr, "illo");
  TEST_ASSERT_NULL_MESSAGE(res, "str not found in string");
}
void Test_strTok()
{
  char tststr[] = "Hello there,I'm here.", delim[] = " ,.";
  char *tok = mystr_strtok(tststr, delim);
  // expected "Hello"
  TEST_ASSERT_NOT_NULL(tok);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Hello", tok, "Find at first token");
  // expected "there"
  tok = mystr_strtok(NULL, delim);
  TEST_ASSERT_NOT_NULL(tok);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("there", tok, "Find at second token");
  // expected I'm
  tok = mystr_strtok(NULL, delim);
  TEST_ASSERT_NOT_NULL(tok);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("I'm", tok, "Find at third token");
  // expected "here"
  tok = mystr_strtok(NULL, delim);
  TEST_ASSERT_NOT_NULL(tok);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("here", tok, "Find at last token");
  tok = mystr_strtok(NULL, delim);
  TEST_ASSERT_NULL_MESSAGE(tok, "No more tokens return null");
}
int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(Test_memchr);
  RUN_TEST(Test_memcmp);
  RUN_TEST(Test_memcpy);
  RUN_TEST(Test_memmove);
  RUN_TEST(Test_memset);
  RUN_TEST(Test_strchr);
  RUN_TEST(Test_strcat);
  RUN_TEST(Test_strcmp);
  RUN_TEST(Test_strcpy);
  RUN_TEST(Test_strspn);
  RUN_TEST(Test_strlen);
  RUN_TEST(Test_strncat);
  RUN_TEST(Test_strncmp);
  RUN_TEST(Test_strncpy);
  RUN_TEST(Test_strrchr);
  RUN_TEST(Test_strstr);
  RUN_TEST(Test_strTok);
  return UNITY_END();
}