#ifndef STACKS_CURSORBASED_V2
#define STACKS_CURSORBASED_V2
#include <stdbool.h>

#define MAX 10

typedef struct {
    char elem;
    int link;
} Node;

typedef struct {
    Node Nodes[MAX];
    int Avail;
} VHeap;

typedef int LIST;

typedef struct {
    VHeap VH;
    LIST L;
} STACK;

void initialize(STACK *SP);
void push(char elem, STACK *SP);
void insertBottom(char elem, STACK *SP);
void pop(STACK *SP);
char top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void displayStack(STACK* SP);

int allocSpace(STACK *SP);
void deallocSpace(int ndx, STACK *SP);

#endif