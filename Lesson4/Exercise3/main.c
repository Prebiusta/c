#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Student {
    char firstName[20];
    char lastName[20];
    int studentId;
    char nationality[20];
} student_t;

void printStudentInfo(student_t *data){
    printf("_____________________| %s %s |_____________________\n", data->firstName, data->lastName);

    printf("Student ID: %d\n", data->studentId);
    printf("Nationality: %s\n\n", data->nationality);
}

// Finds a student based on Student ID. Return location of student in memory or NULL if not found.
void *getByStudentId(int studentId){
    int size = noOfItems();

    for (int i = 0; i < size - 1; i++){
        student_t *student = (student_t *)getItem(i);

        if (student->studentId == studentId){
            return student;
        }
    }

    return NULL;
}

// Finds a student based on Last Name. Return location of student in memory or NULL if not found.
void *getByLastName(char lastName){
     int size = noOfItems();

    for (int i = 0; i < size - 1; i++){
        student_t *student = (student_t *)getItem(i);

        if (*(char *)student->lastName == lastName){
            return student;
        }
    }

    return NULL;
}


int main() {

    // Declare pointer with information about David
    student_t *pointerToDavid;

    pointerToDavid = (student_t *)malloc(sizeof(student_t));

    strcpy(pointerToDavid->firstName, "David");
    strcpy(pointerToDavid->lastName, "Franko");
    strcpy(pointerToDavid->nationality, "Slovakia");
    pointerToDavid->studentId = 279949;

    // Declare pointer with information about Dorcia
    student_t *pointerToDorcia;

    pointerToDorcia = (student_t *)malloc(sizeof(student_t));

    strcpy(pointerToDorcia->firstName, "Dorcia Fiona");
    strcpy(pointerToDorcia->lastName, "Dinesh");
    strcpy(pointerToDorcia->nationality, "India");
    pointerToDorcia->studentId = 280923;

    // Declare pointer with information about Angel
    student_t *pointerToAngel;

    pointerToAngel = (student_t *)malloc(sizeof(student_t));

    strcpy(pointerToAngel->firstName, "Angel Arman");
    strcpy(pointerToAngel->lastName, "Somicu");
    strcpy(pointerToAngel->nationality, "Romania");
    pointerToAngel->studentId = 260123;



    // Add all students to list
    addItem(pointerToAngel);
    addItem(pointerToDavid);
    addItem(pointerToDorcia);

    // Print students one by one

    for (int i = 0; i < 3; i++){
        student_t *student = (student_t *)getItem(i);
        printStudentInfo(student);
    }

    printf("Find student with ID 279949\n");

    printStudentInfo(getByStudentId(279949));

    printf("Find student with Last Name Dinesh\n");

    char *lastName = "Dinesh";

    printStudentInfo(getByLastName(*lastName));
}