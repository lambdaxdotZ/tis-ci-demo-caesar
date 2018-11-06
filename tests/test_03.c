#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <caesar.h>
#include <gen_test.h>

int main(void)
{
    check_magic_number();

    char str[] = "People of Earth";

    printf("Test 1: Shift with a negative input\n");
    gen_test(str, INT_MIN);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(str, INT_MAX);

    return 0;
}
