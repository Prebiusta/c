#include <stdlib.h>
#include <stdio.h>
#include "student.h"

typedef struct student {
  char *firstName;
  char *lastName;
  int studentId;
  char *nationality;
} student;

student_t student_createStudent(char *firstName, char *lastName, int studentId,
                                char *nationality) {
  student_t _newStudent = calloc(sizeof(student), 1);

  _newStudent->firstName = firstName;
  _newStudent->lastName = lastName;
  _newStudent->studentId = studentId;
  _newStudent->nationality = nationality;

  return _newStudent;
}

void student_printInfo(student_t self){
    printf("---------------------- %s %s ----------------------\n", self->firstName, self->lastName);
    printf("\tStudent ID: %d || Nationality: %s\n", self->studentId, self->nationality);
}