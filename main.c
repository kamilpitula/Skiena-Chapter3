#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "linkedList.h"
#include "tictactoe.h"
#include "anagram.h"
#include "binaryTree.h"

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

    // executeParentheses();

    // LinkedList *list = NULL;
    // insertElement(&list, 4);
    // insertElement(&list, 7);
    // insertElement(&list, 5);

    // reverse(&list);

    // LinkedList *searchResult = searchList(list, 7);
    // removeElement(&list, searchResult);

    // printf("Search result %i\n", searchResult->value);

    TicTacToe *game;
    initBoard(&game, 3);
    Move moves[] = {
        {.row = 1, .column = 1, .player = 1},
        {.row = 1, .column = 2, .player = 2},
        {.row = 2, .column = 2, .player = 1},
        {.row = 3, .column = 3, .player = 2},
        {.row = 2, .column = 1, .player = 1},
        {.row = 3, .column = 1, .player = 2},
        {.row = 3, .column = 2, .player = 1},
        {.row = 2, .column = 3, .player = 2},
        {.row = 1, .column = 3, .player = 1},
    };

    int winner = performMoves(game, moves, sizeof(moves) / sizeof(Move));

    deleteBoard(game);

    bool areAnagramsResult = areAnagrams("silent", "listen");

    BinaryTree* tree = NULL;

    insertTreeElement(&tree, 2);
    insertTreeElement(&tree, 1);
    insertTreeElement(&tree, 7);
    insertTreeElement(&tree, 4);
    insertTreeElement(&tree, 8);
    insertTreeElement(&tree, 3);
    insertTreeElement(&tree, 6);
    insertTreeElement(&tree, 5);

    int isTreeBalanced = isBalanced(tree);

    printf("%s", isTreeBalanced == -1 ? "Tree is not balanced\n" : "Tree is balanced\n");

    BinaryTree* balancedTree = NULL;

    insertTreeElement(&balancedTree, 2);
    insertTreeElement(&balancedTree, 1);
    insertTreeElement(&balancedTree, 7);
    insertTreeElement(&balancedTree, 4);

    printf("%s", isBalanced(balancedTree) == -1 ? "Tree is not balanced\n" : "Tree is balanced\n");

    // BinaryTree* minimum = findMinimum(tree);
    // BinaryTree* maximum = findMaximum(tree);

    // BinaryTree* searchResult_3 = searchTree(tree, 3);
    // BinaryTree* searchResult_5 = searchTree(tree, 5);

    BinaryTree* a = searchKSmallest(tree, 2);
    BinaryTree* b = searchKSmallest(tree, 1);
    BinaryTree* c = searchKSmallest(tree, 8);

    deleteFromTree(&tree, 4);
    deleteFromTree(&tree, 1);

    return 0;
}
