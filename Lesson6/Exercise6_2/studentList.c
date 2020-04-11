#include "studentList.h"
#include <stdio.h>

list_t studentList_create(void)
{
    return list_create();
}

list_ReturnCode_t studentList_addStudent(list_t studentList, student_t student)
{
    if (studentList == NULL)
    {
        return LIST_NULL;
    }

    return list_addItem(studentList, student);
}

list_ReturnCode_t studentList_getStudent(list_t studentList, student_t *student, uint16_t index)
{
    if (studentList == NULL)
    {
        return LIST_NULL;
    }

    return list_getItem(studentList, (void *)student, index);
    ;
}

list_ReturnCode_t studentList_removeStudent(list_t studentList, student_t student)
{
    if (studentList == NULL)
    {
        return LIST_NULL;
    }

    return list_removeItem(studentList, student);
}

uint16_t studentList_noOfStudents(list_t studentList)
{
    if (studentList == NULL)
    {
        return LIST_NULL;
    }

    uint16_t number = list_noOfItems(studentList);

    return number;
}