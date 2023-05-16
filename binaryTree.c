#include "binaryTree.h"
#include <stddef.h>
#include <stdlib.h>

void insertTreeElement(BinaryTree **tree, int value)
{
    if (*tree == NULL)
    {
        BinaryTree *temp = malloc(sizeof(BinaryTree));
        temp->right = NULL;
        temp->left = NULL;
        temp->value = value;
        *tree = temp;
        return;
    }

    if (value <= (*tree)->value)
        insertTreeElement(&((*tree)->left), value);
    else
        insertTreeElement(&((*tree)->right), value);
}

BinaryTree *findMinimum(BinaryTree *tree)
{
    if (tree == NULL)
        return NULL;

    BinaryTree *minimum = tree->left;

    while (minimum->left != NULL)
    {
        minimum = minimum->left;
    }

    return minimum;
}

BinaryTree *findMaximum(BinaryTree *tree)
{
    if (tree == NULL)
        return NULL;

    BinaryTree *minimum = tree->right;

    while (minimum->right != NULL)
    {
        minimum = minimum->right;
    }

    return minimum;
}