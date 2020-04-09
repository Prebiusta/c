#include "list.h"

#include <stdlib.h>

typedef struct list {
  void *data;
  struct list *next;
} list;

list_t list_create(void) {
  list_t _newList = calloc(sizeof(list), 1);

  if (NULL == _newList) {
    return NULL;
  }

  return _newList;
};

list_ReturnCode_t list_addItem(list_t self, void *item) {
  if (self == NULL) {
    return LIST_NULL;
  }

  if (self->data != NULL) {
    self->data = item;
  }

  list_t _lastItem = self;

  while (_lastItem->next != NULL) {
    _lastItem = _lastItem->next;
  }

  list_t _newItemInList = calloc(sizeof(list), 1);

  if (_newItemInList == NULL) {
    return LIST_ERROR;
  }

  _newItemInList->data = item;

  _lastItem->next = _newItemInList;

  return LIST_OK;
}

list_ReturnCode_t list_getItem(list_t self, void **item, uint16_t index) {
  list_t _current = self;

  if (self == NULL) {
    return LIST_NULL;
  }

  if (index == 0) {
    *item = _current->data;
  }

  for (int i = 0; i < index; i++) {
    if (_current->next == NULL) {
      *item = NULL;
      return LIST_NOT_FOUND;
    }
    _current = _current->next;
  }

  *item = _current->data;

  return LIST_OK;
}

list_ReturnCode_t list_removeItem(list_t self, void *item) {
  if (self == NULL) {
    return LIST_NULL;
  }

  list_t current = self;
  list_t previous = NULL;

  while (current != NULL) {
    if (current->data == item) {
      previous->next = current->next;
      free(current);
      return LIST_OK;
    }
    previous = current;
    current = current->next;
  }
  return LIST_NOT_FOUND;
}

uint16_t list_noOfItems(list_t self) {
  uint16_t count = 0;

  list_t current = self;

  while (current->next != NULL) {
    count++;
    current = current->next;
  }

  return count;
}