typedef struct {
    int* buffer;
    int position;
    int capacity;
    int minValue;
} Stack;

extern Stack* init(int len);
extern int push(Stack* stack, int element);
extern int pop(Stack* stack);
extern void freeStack(Stack* stack);
extern int findMin(Stack* stack);