#include "_header.h"
#include <stdbool.h>
#include <stdio.h>

void initialize(STACK *SP) {
    SP->top = -1;    
}

void push(char elem, STACK *SP) {
    if (!isFull(*SP)) {
        SP->top++;
        SP->data[SP->top] = elem;
    }
}

void pop(STACK *SP) {
    if (!isEmpty(*SP)) {
        SP->top--;
    }
}

char top(STACK S) {
    int res = -1;

    if (!isEmpty(S)) {
        res = S.data[S.top];
    }

    return res;
}

bool isEmpty(STACK S) {
    return S.top == -1;
}

bool isFull(STACK S) {
    return S.top == MAX;
}

void displayStack(STACK* SP) {
    STACK temp;
    initialize(&temp);
    int elem;

    printf("STACK: ");
    for (elem = top(*SP); !isEmpty(*SP); pop(SP), push(elem, &temp), elem = top(*SP)) {
        printf("%c ", elem);
    }
    printf("\n");

    for (elem = top(temp); !isEmpty(temp); pop(&temp), push(elem, SP), elem = top(temp)) {
    }
}

void insertBottom(char elem, STACK *SP) {
    STACK temp;
    initialize(&temp);

    for (; !isEmpty(*SP); push(top(*SP), &temp), pop(SP)) {}

    push(elem, SP);

    for (; !isEmpty(temp); push(top(temp), SP), pop(&temp)) {}
}