#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(Queue *QP) {
    QP->front = 0;
    QP->rear = MAX - 1;
}

void enqueue(char elem, Queue *QP) {
    if (!isFull(*QP)) {
        QP->rear = (QP->rear + 1) % MAX;
        QP->Elem[QP->rear] = elem;
    }
}

void dequeue(Queue *QP) {
    if (!isEmpty(*QP)) {
        QP->front = (QP->front + 1) % MAX;
    }
}

char front(Queue Q) {
    char res = '\0';
    
    if (!isEmpty(Q)) {
        res = Q.Elem[Q.front];
    }

    return res;
}

bool isEmpty(Queue Q) {
    return Q.front == (Q.rear + 1) % MAX;
}

bool isFull(Queue Q) {
    return Q.front == (Q.rear + 2) % MAX;
}

void makeNull(Queue *QP) {
    while (!isEmpty(*QP)) {
        dequeue(QP);
    }
}

void displayList(Queue *QP) {
    Queue temp;
    initialize(&temp);
    char frontElem;

    printf("QUEUE: ");
    for (frontElem = front(*QP); !isEmpty(*QP); frontElem = front(*QP)) {
        printf("%c ", frontElem);
        dequeue(QP);
        enqueue(frontElem, &temp);
    }
    printf("\n");

    for (frontElem = front(temp); !isEmpty(temp); frontElem = front(temp)) {
        dequeue(&temp);
        enqueue(frontElem, QP);
    }
}