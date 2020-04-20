#include <stdlib.h>
#include "student.h"
#include "studentHandler.h"

int main()
{
    student_t david = student_createStudent("David", "Franko", 279949, "Slovakia");
    student_t dorcia = student_createStudent("Dorcia Fiona", "Dinesh", 280145, "India");
    student_t valeriu = student_createStudent("Valeriu", "Rusu", 123123, "Moldova");
    student_t viktoria = student_createStudent("Viktoria", "Khouni", 165221, "Greece");

    list_t studentListOne = studentHandler_create();
    studentHandler_addStudent(studentListOne, david);
    studentHandler_addStudent(studentListOne, dorcia);
    studentHandler_addStudent(studentListOne, valeriu);
    studentHandler_addStudent(studentListOne, viktoria);

    student_t angel = student_createStudent("Angel", "Arman", 255667, "Romania");

    list_t studentListTwo = studentHandler_create();
    studentHandler_addStudent(studentListTwo, angel);
    studentHandler_addStudent(studentListTwo, dorcia);

    printf("____________________ Printing student list ONE ____________________\n");
    studentHandler_printAllStudentsInfo(studentListOne);

    printf("____________________ Printing student list TWO ____________________\n");
    studentHandler_printAllStudentsInfo(studentListTwo);

    printf("____________________ Search student with ID 123123 ____________________\n");
    student_t searchStudent = studentHandler_searchStudentById(studentListOne, 123123);
    studentHandler_printStudentInfo(searchStudent);

    printf("____________________ Search student with last name Franko ____________________\n");
    searchStudent = studentHandler_searchStudentByLastName(studentListOne, "Franko");
    studentHandler_printStudentInfo(searchStudent);

    printf("____________________ Search student with last name Dinesh ____________________\n");
    searchStudent = studentHandler_searchStudentByLastName(studentListOne, "Dinesh");
    studentHandler_printStudentInfo(searchStudent);

    printf("____________________ Search student with last name Rusu ____________________\n");
    searchStudent = studentHandler_searchStudentByLastName(studentListOne, "Rusu");
    studentHandler_printStudentInfo(searchStudent);

    printf("____________________ Search student with last name Khouni ____________________\n");
    searchStudent = studentHandler_searchStudentByLastName(studentListOne, "Khouni");
    studentHandler_printStudentInfo(searchStudent);
}