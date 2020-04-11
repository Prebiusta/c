#pragma once
#include <stdio.h>
#include "student.h"
#include "list.h"

list_t studentHandler_create(void);
void studentHandler_printStudentInfo(student_t student);
void studentHandler_printAllStudentsInfo(list_t studentList);
student_t studentHandler_searchStudentById(list_t studentList, int studentId);
student_t studentHandler_searchStudentByLastName(list_t studentList, char *lastName);
void studentHandler_addStudent(list_t studentList, student_t student);