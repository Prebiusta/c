#pragma once
#include <string.h>

typedef struct student *student_t;

student_t student_createStudent(char *firstName, char *lastName, int studentId, char *nationality);
char* student_getStudentLastName(student_t student);
int student_getStudentId(student_t student);
void student_printInfo(student_t self);