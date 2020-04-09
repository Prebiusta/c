#pragma once
#include <string.h>

typedef struct student *student_t;

student_t student_createStudent(char *firstName, char *lastName, int studentId,
                                char *nationality);

void student_printInfo(student_t self);