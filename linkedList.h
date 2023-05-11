typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

extern void insertElement(LinkedList **list, int value);
extern void removeElement(LinkedList **list, LinkedList *element);
extern LinkedList *searchList(LinkedList *list, int value);