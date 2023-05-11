#include "linkedList.h"

#include <stdlib.h>
#include <stddef.h>

void insertElement(LinkedList **list, int value)
{
    LinkedList *newElement = malloc(sizeof(LinkedList));
    newElement->value = value;
    newElement->sentinel = 0;

    if (*list == NULL)
    {
        LinkedList *sentinel = malloc(sizeof(LinkedList));
        sentinel->sentinel = 1;
        sentinel->value = 0;
        sentinel->next = NULL;

        *list = newElement;
        (*list)->next = sentinel;
        return;
    }

    newElement->next = *list;
    *list = newElement;
}

LinkedList *searchList(LinkedList *list, int value)
{
    if (list == NULL)
        return NULL;

    if (list->value == value)
        return list;

    return searchList(list->next, value);
}

void removeElement(LinkedList **list, LinkedList *element)
{
    if (*list == element)
    {
        *list = element->next;
        free(element);
        return;
    }

    LinkedList *next = element->next;
    element->value = next->value;
    element->next = next->next;

    free(next);
}
