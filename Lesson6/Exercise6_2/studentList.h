#pragma once
#include "list.h"
#include "student.h"

list_ReturnCode_t studentList_addStudent(student_t student);
list_ReturnCode_t studentList_getStudent(student_t student, uint16_t index);
list_ReturnCode_t studentList_removeStudent(student_t student);
uint16_t studentList_noOfStudents();