#include "_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(STACK *SP) {
    *SP = NULL;
}

void push(char elem, STACK *SP) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp != NULL) {
        temp->data = elem;
        temp->link = *SP;
        *SP = temp;
    }
}

void insertBottom(char elem, STACK *SP) {
    STACK temp;
    initialize(&temp);

    for (; !isEmpty(*SP); push(top(*SP), &temp), pop(SP)) {}

    push(elem, SP);

    for (; !isEmpty(temp); push(top(temp), SP), pop(&temp)) {}
}

void pop(STACK *SP) {
    if (!isEmpty(*SP)) {
        Node *temp = *SP;
        *SP = temp->link;
        free(temp);
    }
}

char top(STACK S) {
    char res = -1;

    if (!isEmpty(S)) {
        res = S->data;
    }

    return res;
}

bool isEmpty(STACK S) {
    return S == NULL;
}

void displayStack(STACK* SP) {
    STACK temp;
    initialize(&temp);
    char elem;

    printf("STACK: ");
    for (elem = top(*SP); !isEmpty(*SP); push(elem, &temp), pop(SP), elem = top(*SP)) {
        printf("%c ", elem);
    }
    printf("\n");

    for (elem = top(temp); !isEmpty(temp); push(elem, SP), pop(&temp), elem = top(temp)) {}
}