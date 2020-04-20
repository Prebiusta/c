#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// Node to hold values
typedef struct Node
{
    void *data;
    struct Node *next;
} node_t;

node_t *head = NULL;

int addItem(void *item)
{
    node_t *newNode;
    newNode = (node_t *)malloc(sizeof(node_t));

    newNode->data = item;
    newNode->next = head;

    head = newNode;
    return 1;
};

void *getItem(uint16_t index)
{
    node_t *current = head;

    if (index == 0){
        return head->data;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        current = current->next;
    }

    return current->data;
};

int noOfItems()
{
    int count = 0;
    node_t *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
};

int removeItem(void *item)
{
    node_t *current = head;
    node_t *previous = NULL;

    while (current != NULL)
    {
        if (current == item)
        {
            previous->next = current->next;
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return -1;
};


