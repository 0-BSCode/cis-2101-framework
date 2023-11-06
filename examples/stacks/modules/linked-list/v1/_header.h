#ifndef STACK_LINKEDLIST_V1
#define STACK_LINKEDLIST_V1

typedef struct node {
    char elem;
    struct node* link;
} NodeType, *STACK;

void initialize(STACK *SP);
void push(char elem, STACK *SP);
void pop(STACK *SP);
char top(STACK S);
int isEmpty(STACK S);
void displayStack(STACK* SP);

#endif