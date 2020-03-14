#include <stdio.h>

int main() {
    int number = 10;
    int *pnumber = &number;

    printf("Value of number variable: %d\n", number);
    printf("Address of number variable: %p\n\n", &number);

    printf("Value of pointer: %p\n", pnumber);
    printf("Address of pointer: %p\n", &pnumber);
    printf("Value of pointer address: %d\n", *pnumber);
    printf("Address of value of pointer address: %p\n", &(*pnumber));
}