#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "linkedList.h"

int validParentheses(char *str, size_t len)
{
    Stack *stack = init(len);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
            push(stack, i);
        if (str[i] == ')')
        {
            char res = pop(stack);
            if (res == -1)
            {
                freeStack(stack);
                return i;
            }
        }
    }

    if (stack->position >= 0)
    {
        int result = pop(stack);
        freeStack(stack);
        return result;
    }

    freeStack(stack);
    return -1;
}

int maxValidParenthesesSequence(char *str, size_t len)
{
    Stack *stack = init(len);
    int sequences[len];

    for (int i = 0; i < len; i++)
        sequences[i] = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
            push(stack, i);
        if (str[i] == ')')
        {
            char res = pop(stack);
            if (res == -1)
                continue;

            sequences[i] = 1;
            sequences[res] = 1;
        }
    }

    int max = 0;
    int current = 0;

    for (int i = 0; i < len; i++)
    {
        if (sequences[i] == 0)
            current = 0;
        else
        {
            current++;
            if (current > max)
                max = current;
        }
    }

    freeStack(stack);
    return max;
}

void executeParentheses()
{
    char *str = "(";
    int result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = ")";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "(()())";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "(()()";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "((())())()";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "((())())(()";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);

    str = "()(()";
    result = maxValidParenthesesSequence(str, strlen(str));
    printf("Result %i \n", result);
}

int main(void)
{
    executeParentheses();

    // LinkedList *list = NULL;
    // insertElement(&list, 4);
    // insertElement(&list, 7);
    // insertElement(&list, 5);

    // reverse(&list);

    // LinkedList *searchResult = searchList(list, 7);
    // removeElement(&list, searchResult);

    // printf("Search result %i\n", searchResult->value);

    return 0;
}
