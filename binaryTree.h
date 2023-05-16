typedef struct BinaryTree {
    struct BinaryTree* left;
    struct BinaryTree* right;
    int value;
} BinaryTree;

extern void insertTreeElement(BinaryTree** tree, int value);
extern BinaryTree* findMinimum(BinaryTree* tree);
extern BinaryTree* findMaximum(BinaryTree* tree);