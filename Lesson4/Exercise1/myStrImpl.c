#include <stdlib.h>
#include "myStr.h"

int my_strlen(const char* str){
    int length = 0;

    if (str[0] == '\0'){
        return 0;
    }


    while (*str != '\0'){
        length++;
        str++;
    }

    return length;
}

int my_strcmp(const char* str1, const char* str2){
    
    if ((str1[0] == '\0') || (str2[0] == '\0')){
        return -1;
    }
    
    while (*str1 != '\0'){

        if (*str1 != *str2){
            return -1;
        }

        str1++;
        str2++;
    }

    return 0;
}

char* my_strcpy(char* dest, const char* src){
    char *ptr = dest;

    while((*dest++ = *src++) != '\0');

    return ptr;
}

char* my_strdup(const char* str){
    char *string;
    char *p;
    int len = 0;

    while(str[len])
        len++;

    string = malloc(len + 1);
    p = string;

    while(*str)
        *p++ = *str++;
    *p = '\0';
    
    return string;
}