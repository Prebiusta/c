#include <stdio.h>

#include "addition.h"

int main()
{
    char str[100];
    int i;
    double x;

    printf("Hello David, enter a Value: ");

    scanf("%d %s", &i, str);

    printf("\nYou entered: %d__%s\n", i, str);
    printf("Value added to each other is %d", esw_add(i, i));

    printf("Specify double: ");

    scanf("%lf", &x);

    printf("\nYou entered: %lf\n", x);

    return 0;
}

// Press F6 to compile and run