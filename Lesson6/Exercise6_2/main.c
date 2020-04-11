#include <stdlib.h>
#include "student.h"
#include "studentHandler.h"

int main()
{

    // list_t myList = list_create();

    // int myNumber = 1;
    // list_addItem(myList, &myNumber);
    // list_addItem(myList, &myNumber);
    // list_addItem(myList, &myNumber);
    // list_addItem(myList, &myNumber);
    // list_addItem(myList, &myNumber);
    // uint16_t numberOfItems = list_noOfItems(myList);
    // printf("Number of items: %d\n", numberOfItems);
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

    printf("_________________________________ Printing student list ONE _________________________________\n");
    studentHandler_printAllStudentsInfo(studentListOne);

    printf("_________________________________ Printing student list TWO _________________________________\n");
    studentHandler_printAllStudentsInfo(studentListTwo);

    printf("_________________________________ Search student with ID 123123 _________________________________\n");
    student_t searchStudent = studentHandler_searchStudentById(studentListOne, 123123);
    studentHandler_printStudentInfo(searchStudent);

    printf("_________________________________ Search student with last name Dinesh _________________________________\n");
    char lastNameSearch[] = "Dinesh";
    searchStudent = studentHandler_searchStudentByLastName(studentListOne, lastNameSearch);
    studentHandler_printStudentInfo(searchStudent);
}