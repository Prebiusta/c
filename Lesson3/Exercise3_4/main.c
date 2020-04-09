#include "my_string_func.h"
#include <stdio.h>
#define MAX_LENGTH 1000

int main()
{
    char line[MAX_LENGTH];
    char upper[MAX_LENGTH];

    int line_length;

    char myString[MAX_LENGTH] = "asdasdasdasdAFSDFaDF# ";
    char converted[MAX_LENGTH] = "";

    my_to_upper(myString, converted);

    printf("testing %s\n", converted);

    while (read_line(line) != 0)
    {
        my_to_upper(line, upper);
        line_length = my_length(line);
        printf("Length: %d\t%s\n", line_length, upper);
    }
    return 0;
}
