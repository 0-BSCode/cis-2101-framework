#ifndef STACK_CURSORBASED_V1
#define STACK_CURSORBASED_V1
#include <stdbool.h>

#define MAX 10
typedef struct {
    char data;
    int link;
} Node;

typedef struct {
    Node Nodes[MAX];
    int Avail;
} VirtHeap;

typedef int LIST;

typedef struct {
    VirtHeap VH;
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