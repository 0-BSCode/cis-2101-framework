#ifndef STACK_LINKEDLIST_V2
#define STACK_LINKEDLIST_V2
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *link;
} Node, *STACK;

void initialize(STACK *SP);
void push(char elem, STACK *SP);
void insertBottom(char elem, STACK *SP);
void pop(STACK *SP);
char top(STACK S);
bool isEmpty(STACK S);
void displayStack(STACK* SP);

#endif