typedef struct BinaryTree {
    struct BinaryTree* left;
    int leftNodesCount;
    struct BinaryTree* right;
    int rightNodesCount;
    int value;
} BinaryTree;

extern void insertTreeElement(BinaryTree** tree, int value);
extern BinaryTree* findMinimum(BinaryTree* tree);
extern BinaryTree* findMaximum(BinaryTree* tree);
extern BinaryTree* searchTree(BinaryTree* tree, int value);
extern void deleteFromTree(BinaryTree** tree, int value);