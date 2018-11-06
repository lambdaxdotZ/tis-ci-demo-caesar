#include <stdlib.h>
#include <stdio.h>
#include <caesar.h>
#include <gen_test.h>

int main(void)
{
    check_magic_number();

    char str[] = "People of Earth";

    printf("Test 1: Shift with a negative input\n");
    gen_test(str, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(str, 7);

    return 0;
}
