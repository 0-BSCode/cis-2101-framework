#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(QUEUE *QP) {
    QP->front = 0;
    QP->rear = MAX - 1;
}

void enqueue(char elem, QUEUE *QP) {
    if (!isFull(*QP)) {
        QP->rear = (QP->rear + 1) % MAX;
        QP->elem[QP->rear] = elem;
    }
}

void insertFront(char elem, QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);

    for (; !isEmpty(*QP); enqueue(front(*QP), &temp), dequeue(QP)) {}
    
    enqueue(elem, &temp);

    for (; !isEmpty(temp); enqueue(front(temp), QP), dequeue(&temp)) {}

    *QP = temp;
}

void insertAtPos(int pos, char elem, QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    int ctr;

    for (ctr = 0; ctr < pos; ctr++) {
        printf("Transferring %c\n", front(*QP));
        enqueue(front(*QP), &temp);
        dequeue(QP);
    }

    enqueue(elem, QP);

    while (!isEmpty(temp)) {
        enqueue(front(temp), QP);
        dequeue(&temp);
    }
}

void dequeue(QUEUE *QP) {
    if (!isEmpty(*QP)) {
        QP->front = (QP->front + 1) % MAX;
    }
}

char front(QUEUE Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.elem[Q.front];
    }

    return res;
}

bool isEmpty(QUEUE Q) {
    return Q.front == (Q.rear + 1) % MAX;
}

bool isFull(QUEUE Q) {
    return Q.front == (Q.rear + 2) % MAX;
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

    for (data = front(temp); !isEmpty(temp); enqueue(data, QP), dequeue(&temp), data = front(temp)) {}
}