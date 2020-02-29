#include <stdio.h>

int main()
{
    char str[100];
    int i;

    printf("Hello David, enter a Value: ");

    scanf("%d %s", &i, str);

    printf("\nYou entered: %d__%s\n", i, str);
    return 0;
}

// Press F6 to compile and run