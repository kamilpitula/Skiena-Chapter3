#include <stdlib.h>
#include "stack.h"

Stack *init(int len)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->position = -1;
    stack->capacity = len;
    stack->buffer = (int*)malloc(sizeof(int*) * len);
    for (int i = 0; i < len; i++)
    {
        stack->buffer[i] = -1;
    }
    return stack;
}

int push(Stack *stack, int element)
{
    if (stack->position == stack->capacity - 1)
        return 0;

    stack->position++;
    stack->buffer[stack->position] = element;
    return 1;
}

int pop(Stack *stack)
{
    if (stack->position == -1)
        return -1;

    int result = stack->buffer[stack->position];
    stack->buffer[stack->position] = -1;
    stack->position--;

    return result;
}

void freeStack(Stack* stack){
    free(stack->buffer);
    free(stack);
}