#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(QUEUE *QP) {
    int ctr;

    for (ctr = 0; ctr < MAX; ctr++) {
        QP->VH.Nodes[ctr].next = ctr - 1;
    }

    QP->VH.Avail = MAX - 1;
    QP->L = -1;
}

void enqueue(char elem, QUEUE *QP) {
    int temp = allocSpace(QP);

    if (temp != -1) {
        int *trav;

        for (trav = &(QP->L); *trav != -1; trav = &(QP->VH.Nodes[*trav].next)) {}

        QP->VH.Nodes[temp].data = elem;
        QP->VH.Nodes[temp].next = -1;
        *trav = temp;
    }
}

void dequeue(QUEUE *QP) {
    if (!isEmpty(*QP)) {
        int temp = QP->L;
        QP->L = QP->VH.Nodes[temp].next;
        deallocSpace(QP, temp);
    }
}

void insertFront(char elem, QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);

    for (; !isEmpty(*QP); enqueue(front(*QP), &temp), dequeue(QP)) {}
    enqueue(elem, QP);
    for (; !isEmpty(temp); enqueue(front(temp), QP), dequeue(&temp)) {}
}

// BUGGY
void insertPos(int pos, char elem, QUEUE *QP) {
    if (pos >= 0 && pos < MAX) {
        QUEUE temp;
        initialize(&temp);
        int ctr;

        for (ctr = 0; ctr < pos && !isEmpty(*QP); ctr++, enqueue(front(*QP), &temp), dequeue(QP)) {}
        enqueue(elem, QP);
        for (; !isEmpty(temp); enqueue(front(temp), QP), dequeue(&temp)) {}
    }
}

char front(QUEUE Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.VH.Nodes[Q.L].data;
    }

    return res;
}

bool isEmpty(QUEUE Q) {
    return Q.L == -1;
}

bool isFull(QUEUE Q) {
    return Q.VH.Avail == -1;
}

void makeNull(QUEUE *QP) {
    for (; !isEmpty(*QP); dequeue(QP)) {}
}

void displayList(QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    char data;

    printf("QUEUE: ");
    for (data = front(*QP); !isEmpty(*QP); enqueue(data, &temp), dequeue(QP), data = front(*QP)) {
        printf("%c ", data);
    }
    printf("\n");
    for (; !isEmpty(temp); enqueue(front(temp), QP), dequeue(&temp)) {}
}

int allocSpace(QUEUE *QP) {
    int res = QP->VH.Avail;

    if (res != -1) {
        QP->VH.Avail = QP->VH.Nodes[res].next;
    }
    
    return res;
}

void deallocSpace(QUEUE *QP, int idx) {
    if (idx > -1 && idx < MAX) {
        QP->VH.Nodes[idx].next = QP->VH.Avail;
        QP->VH.Avail = idx;
    }
}