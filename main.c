#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

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

void executeParentheses()
{
    char *str = "(";
    int result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = ")";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = "";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = "(()())";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = "(()()";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = "((())())()";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);

    str = "((())())(()";
    result = validParentheses(str, strlen(str));
    printf("Result %i \n", result);
}

int main(void)
{
    executeParentheses();
    return 0;
}
