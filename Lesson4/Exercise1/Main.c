#include <stdio.h>
#include "myStr.h"

int main(){
    char string1[10] = "Dorcia";
    char string2[10] = "";

    printf("Length of string 1: %d \n", my_strlen(string1));
    printf("Length of string 2: %d \n", my_strlen(string2));


    printf("Comparing string 1 and string 2 with result: %d\n", my_strcmp(string2, string1));

    char source[] = "Testing copy";
    char destination[25];

    printf("%p\n", my_strcpy(source, destination));

    char copyChar[] = "David loves Dorcia";

    printf("Duplicating String: %s\nDuplicate: %s\n", copyChar, my_strdup(copyChar));
    

    return 0;
}