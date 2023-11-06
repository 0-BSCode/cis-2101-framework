#include "_header.h"
#include <stdio.h>

void initialize(STACK *SP) {
    SP->top = -1;
}

void push(char elem, STACK *SP) {
    if (SP->top < MAX - 1) {
        SP->top++;
        SP->Elem[SP->top] = elem;
    }
}

void pop(STACK *SP) {
    if (SP->top != -1) {
        SP->top--;
    }
}

char top(STACK S) {
    char res = '\0';
    if (!isEmpty(S)) {
        res = S.Elem[S.top];
    }

    return res;
}

bool isEmpty(STACK S) {
    return S.top == -1;
}

bool isFull(STACK S) {
    return S.top == MAX - 1;
}

void displayStack(STACK* SP) {
    STACK temp;
    initialize(&temp);
    char elem;

    printf("STACK: ");
    for (elem = top(*SP); !isEmpty(*SP); pop(SP), push(elem, &temp), elem = top(*SP)) {
        printf("%c ", elem);
    }
    printf("\n");

    for (elem = top(temp); !isEmpty(temp); pop(&temp), push(elem, SP), elem = top(temp)) {}
}

void insertBottom(char elem, STACK *SP) {
    STACK temp;
    initialize(&temp);

    for (; !isEmpty(*SP); push(top(*SP), &temp), pop(SP)) {}

    push(elem, SP);

    for (; !isEmpty(temp); push(top(temp), SP), pop(&temp)) {}
}
