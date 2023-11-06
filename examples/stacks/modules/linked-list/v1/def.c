#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

void initialize(STACK *SP) {
    *SP = NULL;
}

void push(char elem, STACK *SP) {
    NodeType *node = (NodeType*)malloc(sizeof(NodeType));

    if (node != NULL) {
        node->elem = elem;
        node->link = *SP;
        *SP = node;
    }
}

void pop(STACK *SP) {
    if (*SP != NULL) {
        NodeType *node = *SP;
        *SP = node->link;
        free(node);
    }
}

char top(STACK S) {
    char res = '\0';

    if (!isEmpty(S)) {
        res = S->elem;
    }

    return res;
}

int isEmpty(STACK S) {
    return S == NULL;
}

void displayStack(STACK* SP) {
    STACK temp;
    char elem;

    initialize(&temp);
    printf("STACK: ");
    for (elem = top(*SP); !isEmpty(*SP); pop(SP), push(elem, &temp), elem = top(*SP)) {
        printf("%c ", elem);
    }
    printf("\n");

    for (elem = top(temp); !isEmpty(temp); pop(&temp), push(elem, SP), elem = top(temp)) {}
}
