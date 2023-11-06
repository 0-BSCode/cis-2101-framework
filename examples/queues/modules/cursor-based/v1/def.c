#include "_header.h"
#include <stdbool.h>
#include <stdio.h>

void initialize(Queue *QP) {
    int ctr;

    for (ctr = 0; ctr < MAX; ctr++) {
        QP->VH.Nodes[ctr].next = ctr - 1;
    }

    QP->VH.Avail = ctr - 1;
    QP->front = -1;
    QP->rear = -1;
}

void enqueue(char elem, Queue *QP) {
    LIST temp = allocSpace(&(QP->VH));

    if (temp != -1) {
        QP->VH.Nodes[temp].data = elem;
        QP->VH.Nodes[temp].next = -1;

        if (QP->front == -1) {
            QP->front = temp;
        } else {
            QP->VH.Nodes[QP->rear].next = temp;
        }

        QP->rear = temp;
    }
}

void dequeue(Queue *QP) {
    if (!isEmpty(*QP)) {
        LIST temp = QP->front;
        QP->front = QP->VH.Nodes[temp].next;
        deallocSpace(&(QP->VH), temp);
    }
}

void insertFront(char elem, Queue *QP) {
    if (!isFull(*QP)) {
        Queue tempQ;
        initialize(&tempQ);

        while (!isEmpty(*QP)) {
            enqueue(front(*QP), &tempQ);
            dequeue(QP);
        }

        enqueue(elem, QP);

        while (!isEmpty(tempQ)) {
            enqueue(front(tempQ), QP);
            dequeue(&tempQ);
        }
    }
}

void insertPos(int pos, char elem, Queue *QP) {
    
}

char front(Queue Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.VH.Nodes[Q.front].data;
    }

    return res;
}

bool isEmpty(Queue Q) {
    return Q.front == -1;
}

bool isFull(Queue Q) {
    return allocSpace(&Q.VH) == -1;
}

void makeNull(Queue *QP) {
    while (!isEmpty(*QP)) {
        dequeue(QP);
    }
}

void displayList(Queue *QP) {
    Queue tempQ;
    initialize(&tempQ);

    printf("QUEUE: ");
    while (!isEmpty(*QP)) {
        printf("%c ", front(*QP));
        enqueue(front(*QP), &tempQ);
        dequeue(QP);
    }
    printf("\n");

    while (!isEmpty(tempQ)) {
        enqueue(front(tempQ), QP);
        dequeue(&tempQ);
    }
}

int allocSpace(VirtualHeap *VHP) {
    int res = VHP->Avail;

    if (VHP->Avail != -1) {
        VHP->Avail = VHP->Nodes[res].next;
    }

    return res;
}

void deallocSpace(VirtualHeap *VHP, int idx) {
    if (idx > 0 && idx < MAX) {
        VHP->Nodes[idx].next = VHP->Avail;
        VHP->Avail = idx;
    }
}
