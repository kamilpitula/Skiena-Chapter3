#include "binaryTree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

void insertTreeElement(BinaryTree **tree, int value)
{
    if (*tree == NULL)
    {
        BinaryTree *temp = malloc(sizeof(BinaryTree));
        temp->right = NULL;
        temp->rightNodesCount = 0;
        temp->left = NULL;
        temp->leftNodesCount = 0;
        temp->value = value;
        *tree = temp;
        return;
    }

    if (value <= (*tree)->value)
    {
        (*tree)->leftNodesCount++;
        insertTreeElement(&((*tree)->left), value);
    }
    else
    {
        (*tree)->rightNodesCount++;
        insertTreeElement(&((*tree)->right), value);
    }
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

bool deleteFromTree(BinaryTree **tree, int value)
{
    if (*tree == NULL)
        return false;

    if (value < (*tree)->value)
    {
        bool res = deleteFromTree(&(*tree)->left, value);
        if (res == true)
        {
            (*tree)->leftNodesCount--;
        }
        return res;
    }

    if (value > (*tree)->value)
    {
        bool res = deleteFromTree(&(*tree)->right, value);
        if (res == true)
        {
            (*tree)->rightNodesCount--;
        }
        return res;
    }

    if ((*tree)->left == NULL && (*tree)->right == NULL)
    {
        free(*tree);
        *tree = NULL;
        return true;
    }

    if ((*tree)->left != NULL && (*tree)->right == NULL)
    {
        BinaryTree *temp = *tree;
        *tree = (*tree)->left;
        free(temp);
        return true;
    }

    if ((*tree)->right != NULL && (*tree)->left == NULL)
    {
        BinaryTree *temp = *tree;
        *tree = (*tree)->right;
        free(temp);
        return true;
    }

    BinaryTree *successor = findMinimum((*tree)->right);
    int tempValue = successor->value;
    deleteFromTree(&(*tree)->right, tempValue);
    (*tree)->value = tempValue;
    (*tree)->rightNodesCount--;
    return true;
}

BinaryTree *searchKSmallest(BinaryTree *tree, int k)
{
    if (tree == NULL)
        return NULL;
    if (tree->leftNodesCount + 1 == k)
        return tree;

    if (tree->leftNodesCount >= k)
        return searchKSmallest(tree->left, k);

    return searchKSmallest(tree->right, k - tree->leftNodesCount - 1);
}

int isBalanced(BinaryTree *tree)
{
    if (tree == NULL)
        return 0;
    int leftHeight = isBalanced(tree->left);
    if(leftHeight == -1)
        return -1;
    int rightHeight = isBalanced(tree->right);
    if(rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1)
        return -1;
    
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}