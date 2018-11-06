#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <caesar.h>
#include <gen_test.h>

int test_123(char *str, int neg_input, int pos_input)
{
  check_magic_number();

  printf("Test 1: Shift with a negative input\n");
  gen_test(str, neg_input);
  printf("\nTest 2: Shift with a positive input\n");
  gen_test(str, pos_input);

  return 0;
}

int test_01(void)
{
    char str[] = "People of Earth";
    test_123(str, -3, 7);
    return 0;
}

int test_02(void)
{
    char str[] = "People of Earth, your attention please";
    test_123(str, -3, 7);
    return 0;
}

int test_03(void)
{
    char str[] = "People of Earth";
    test_123(str, INT_MIN, INT_MAX);
    return 0;
}
