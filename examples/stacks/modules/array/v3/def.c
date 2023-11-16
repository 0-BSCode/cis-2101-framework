#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

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
void insertBottom(char elem, STACK *SP) {
    STACK temp;
    initialize(&temp);
    char topElem;

    for (topElem = top(*SP); !isEmpty(*SP); push(topElem, &temp), pop(SP), topElem = top(*SP)) {}

    push(elem, SP);

    for (topElem = top(temp); !isEmpty(temp); push(topElem, SP), pop(&temp), topElem = top(temp)) {}
}
char top(STACK S) {
    char res = '\0';

    if (!isEmpty(S)) {
        res = S.data[S.top];
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
    char topElem;

    printf("STACK: ");
    for (topElem = top(*SP); !isEmpty(*SP); push(topElem, &temp), pop(SP), topElem = top(*SP)) {
        printf("%c ", topElem);
    }

    printf("\n");

    for (topElem = top(temp); !isEmpty(temp); push(topElem, SP), pop(&temp), topElem = top(temp)) {}
}