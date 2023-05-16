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

    if(value <= (*tree)->value)
        insertTreeElement(&((*tree)->left), value);
    else
        insertTreeElement(&((*tree)->right), value);
}
