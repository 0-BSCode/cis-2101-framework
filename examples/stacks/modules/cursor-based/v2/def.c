#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(STACK *SP) {
    int idx;

    for (idx = 0; idx < MAX; idx++) {
        SP->VH.Nodes[idx].link = idx - 1;
    }

    SP->VH.Avail = MAX - 1;
    SP->L = -1;
}

void push(char elem, STACK *SP) {
    int idx = allocSpace(SP);

    if (idx != -1) {
        SP->VH.Nodes[idx].elem = elem;
        SP->VH.Nodes[idx].link = SP->L;
        SP->L = idx;
    }
}

void insertBottom(char elem, STACK *SP) {
    int idx = allocSpace(SP);

    if (idx != -1) {
        STACK temp;
        initialize(&temp);
        char topElem;

        for (topElem = top(*SP); !isEmpty(*SP); pop(SP), push(topElem, &temp), topElem = top(*SP)) {}

        push(elem, SP);

        for (topElem = top(temp); !isEmpty(temp); pop(&temp), push(topElem, SP), topElem = top(temp)) {}
    }
}
void pop(STACK *SP) {
    if (!isEmpty(*SP)) {
        int temp = SP->L;
        SP->L = SP->VH.Nodes[temp].link;

        deallocSpace(temp, SP);
    }
}
char top(STACK S) {
    char res = '\0';

    if (!isEmpty(S)) {
        res = S.VH.Nodes[S.L].elem;
    }

    return res;
}
bool isEmpty(STACK S) {
    return S.L == -1;
}
bool isFull(STACK S) {
    return S.VH.Avail == -1;
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

int allocSpace(STACK *SP) {
    int res = SP->VH.Avail;

    if (res != -1) {
        SP->VH.Avail = SP->VH.Nodes[res].link;
    }

    return res;
}
void deallocSpace(int ndx, STACK *SP) {
    if (ndx > -1 && ndx < MAX) {
        SP->VH.Nodes[ndx].link = SP->VH.Avail;
        SP->VH.Avail = ndx;
    }
}