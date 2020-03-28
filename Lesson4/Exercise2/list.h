#ifndef LIST_H
#define LIST_H

#include <stdint.h>

// Return 0 if item added else -1
int addItem(void *item);

// Return pointer to item at given index in the list
void *getItem(uint16_t index);

// Return no of items in list
int noOfItems();

// Return 0 if item removed else -1
int removeItem(void *item);

// Prints addresses and ints of values int list
void printAddressesAndInts();

#endif