#include "linkedList.h"

#include <stdlib.h>
#include <stddef.h>

void insertElement(LinkedList **list, int value)
{
    LinkedList *newElement = malloc(sizeof(LinkedList));
    newElement->value = value;

    if (*list == NULL)
    {
        *list = newElement;
        (*list)->next = NULL;
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

    LinkedList *itemAhead = *list;

    do
    {
        if (itemAhead->next == element)
            break;

        itemAhead = itemAhead->next;
    } while (itemAhead->next != NULL);

    itemAhead->next = element->next;
    free(element);
}
