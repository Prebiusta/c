#pragma once

#include <stdint.h>

typedef struct list* list_t;

typedef enum {
  LIST_OK,
  LIST_EMPTY,
  LIST_NOT_FOUND,
  LIST_NULL,
  LIST_ERROR
} list_ReturnCode_t;

// Creates a list a returns pointer in the memory //
list_t list_create(void);

// Destroy a list passed in argument //
list_ReturnCode_t list_destroy(list_t self);

// Adds an item to a list //
list_ReturnCode_t list_addItem(list_t self, void* item);

// Gets an item from a list at specific index //
list_ReturnCode_t list_getItem(list_t self, void** item, uint16_t index);

// Removes an item from the list //
list_ReturnCode_t list_removeItem(list_t self, void* item);

// Return number of items in the list //
uint16_t list_noOfItems(list_t self);