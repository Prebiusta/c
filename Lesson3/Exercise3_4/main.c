#include "my_string_func.h"
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char line[MAX_LENGTH] = {0};
    char upper[MAX_LENGTH] = {0};

    int line_length;

    while (read_line(line) != 0)
    {
        my_to_upper(line, upper);
        line_length = my_length(line);
        printf("Length: %d\t%s\n", line_length, upper);

        // Clean the upper char, so no letters stay from last line
        memset(upper, 0, MAX_LENGTH);
    }
    return 0;
}
