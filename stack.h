typedef struct {
    int* buffer;
    int position;
    int capacity;
} Stack;

extern Stack* init(int len);
extern int push(Stack* stack, int element);
extern int pop(Stack* stack);
extern void freeStack(Stack* stack);