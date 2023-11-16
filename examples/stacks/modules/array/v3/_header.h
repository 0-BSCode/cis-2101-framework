#ifndef STACK_ARRAY_V3
#define STACK_ARRAY_V3
#include <stdbool.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int top;
} STACK;

void initialize(STACK *SP);
void push(char elem, STACK *SP);
void pop(STACK *SP);
void insertBottom(char elem, STACK *SP);
char top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void displayStack(STACK* SP);

#endif