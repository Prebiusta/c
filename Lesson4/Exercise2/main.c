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
    printf("Nationality: %s\n", data->nationality);
}

void main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    addItem(&a);
    addItem(&b);
    addItem(&c);
    addItem(&d);
    addItem(&e);

    printAddressesAndInts();

    int numberOfItems = noOfItems();
    printf("\nNumber of items in the list: %d\n\n", numberOfItems);

    void *item = getItem(2);

    printf("Returning item at index 2: %p\n\n", item);

    printf("Removing item at index 2: %d\n\n", removeItem(item));

    numberOfItems = noOfItems();
    printf("\nNumber of items in the list: %d\n\n", numberOfItems);

    printf("Printing list after deleting index 2\n\n");
    printAddressesAndInts();

    printf("-----------------------------------------------------\n\n\n\n");

    student_t *pointerToDavid;

    pointerToDavid = (student_t *)malloc(sizeof(student_t));

    strcpy(pointerToDavid->firstName, "David");
    strcpy(pointerToDavid->lastName, "Franko");
    strcpy(pointerToDavid->nationality, "Slovakia");
    pointerToDavid->studentId = 279949;

    printStudentInfo(pointerToDavid);


}