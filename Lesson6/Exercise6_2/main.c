#include <stdlib.h>
#include "student.h"

int main(){
    char firstName[] = "David";
    char lastName[] = "Franko";
    int studentId = 279949;
    char nationality[] = "Slovakia";

    student_t david = student_createStudent(firstName, lastName, studentId, nationality);
    student_printInfo(david);
}