#pragma once
#include "list.h"
#include "student.h"

list_t studentList_create(void);
list_ReturnCode_t studentList_addStudent(list_t studentList, student_t student);
list_ReturnCode_t studentList_getStudent(list_t studentList, student_t *student, uint16_t index);
list_ReturnCode_t studentList_removeStudent(list_t studentList, student_t student);
uint16_t studentList_noOfStudents(list_t studentList);