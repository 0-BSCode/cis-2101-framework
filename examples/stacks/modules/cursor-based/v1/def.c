#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(STACK *SP) {
    int ctr;

    for (ctr = 0; ctr < MAX; ctr++) {
        SP->VH.Nodes[ctr].link = ctr - 1;
    }

    SP->VH.Avail = ctr - 1;
    SP->L = -1;
}

void push(char elem, STACK *SP) {
    int temp = allocSpace(SP);

    if (temp != -1) {
        SP->VH.Nodes[temp].data = elem;
        SP->VH.Nodes[temp].link = SP->L;
        SP->L = temp;
    }
}

void insertBottom(char elem, STACK *SP) {
    STACK temp;
    initialize(&temp);
    int topElem;

    for (topElem = top(*SP); !isEmpty(*SP); push(topElem, &temp), pop(SP), topElem = top(*SP)) {}
    push(elem, SP);
    for (topElem = top(temp); !isEmpty(temp); push(topElem, SP), pop(&temp), topElem = top(temp)) {}
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
        res = S.VH.Nodes[S.L].data;
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
    int elem;

    printf("STACK: ");
    for (elem = top(*SP); !isEmpty(*SP); push(elem, &temp), pop(SP), elem = top(*SP)) {
        printf("%c ", elem);
    }
    printf("\n");

    for (elem = top(temp); !isEmpty(temp); push(elem, SP), pop(&temp), elem = top(temp)) {}

}

int allocSpace(STACK *SP) {
    int res = SP->VH.Avail;

    if (res != -1) {
        SP->VH.Avail = SP->VH.Nodes[res].link;
    }

    return res;
}

void deallocSpace(int ndx, STACK *SP) {
    if (ndx >= 0 && ndx < MAX) {
        SP->VH.Nodes[ndx].link = SP->VH.Avail;
        SP->VH.Avail = ndx;
    }
}