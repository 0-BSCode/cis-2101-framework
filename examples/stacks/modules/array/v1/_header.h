#ifndef STACK_ARRAY_V1
#define STACK_ARRAY_V1
#include <stdbool.h>

#define MAX 10
typedef struct node {
    char Elem[MAX];
    int top; // Grows from 0 to MAX - 1
} STACK;

void initialize(STACK *SP);
void push(char elem, STACK *SP);
void insertBottom(char elem, STACK *SP);
void pop(STACK *SP);
char top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void displayStack(STACK* SP);

#endif