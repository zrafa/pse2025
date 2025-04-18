#include <stdio.h>

int main()
{
    char x;

    x = 1;
    printf("x <-- 1\n");
    printf("base 2: %b\n", x);

    x = ~(1<<5);

    printf("x <-- ~(1<<5)\n");
    printf("base 2: %b\n", x);
    printf("base 10: %d\n", x);

    return 0;
}