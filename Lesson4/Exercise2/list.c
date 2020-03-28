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

    for (int i = 0; i < index - 1; i++)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        current = current->next;
    }

    return current->next;
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
        printf("Current data %p, item: %p\n", current, item);

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

void print_list(void (*fptr)(void *))
{
    node_t *current = head;

    while (current != NULL)
    {
        (*fptr)(current);
        current = current->next;
    }
};

void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

void printChar(void *n)
{
    printf(" %d", *(char *)n);
}

void printAddresses(void *n)
{
    printf("%p\n", n);
}

void printAddressesAndChars(void *n)
{
    printf("Address: %p || Value: %d\n", n, *(char *)n);
}

void printAddressesAndInts()
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("Address: %p || Value: %d\n", current, *(int *)current->data);
        current = current->next;
    }
}