#ifndef STACK_ARRAY_V3
#define STACK_ARRAY_V3
#include <stdbool.h>

#define STACK_MAX 10

typedef struct {
    int data[STACK_MAX];
    int top;
} STACK;

void initialize(STACK *SP);
void push(int elem, STACK *SP);
void pop(STACK *SP);
int top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void displayStack(STACK* SP);

#endif