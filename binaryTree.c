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

BinaryTree *searchTree(BinaryTree *tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (tree->value == value)
        return tree;

    if (value < tree->value)
        return searchTree(tree->left, value);

    return searchTree(tree->right, value);
}

void deleteFromTree(BinaryTree **tree, int value)
{
    if (value < (*tree)->value)
    {
        deleteFromTree(&(*tree)->left, value);
        return;
    }

    if (value > (*tree)->value)
    {
        deleteFromTree(&(*tree)->right, value);
        return;
    }

    if (tree == NULL)
        return;

    if ((*tree)->left == NULL && (*tree)->right == NULL)
    {
        free(*tree);
        *tree = NULL;
        return;
    }

    if ((*tree)->left != NULL && (*tree)->right == NULL)
    {
        BinaryTree *temp = *tree;
        *tree = (*tree)->left;
        free(temp);
        return;
    }

    if ((*tree)->right != NULL && (*tree)->left == NULL)
    {
        BinaryTree *temp = *tree;
        *tree = (*tree)->right;
        free(temp);
        return;
    }

    BinaryTree *successor = findMinimum((*tree)->right);
    int tempValue = successor->value;
    deleteFromTree(&(*tree)->right, tempValue);
    (*tree)->value = tempValue;
}
