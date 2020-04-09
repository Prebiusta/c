#ifndef MY_STR
#define MY_STR

// Length of the string array
int my_strlen(const char* str);

// Comparing two strings. Returns 0 if are same, otherwise return 1
int my_strcmp(const char* str1, const char* str2);

// Copy char array to different array
char* my_strcpy(char* dest, const char* src);

// Duplicates char array
char* my_strdup(const char* str);

#endif