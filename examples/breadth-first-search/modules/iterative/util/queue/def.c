#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(QUEUE *QP) {
    QP->rear = -1;
    QP->front = 0;
}
void enqueue(int elem, QUEUE *QP) {
    if (!isFull(*QP)) {
        QP->rear = (QP->rear + 1) % QUEUE_MAX;
        QP->Elem[QP->rear] = elem;
    }
}
void dequeue(QUEUE *QP) {
    if (!isEmpty(*QP)) {
        QP->front = (QP->front + 1) % QUEUE_MAX;
    }
}
int front (QUEUE Q) {
    int res = '\0';

    if (!isEmpty(Q)) {
        res = Q.Elem[Q.front];
    }
}
bool isEmpty(QUEUE Q) {
    return (Q.rear + 1) % QUEUE_MAX == Q.front;
}
bool isFull(QUEUE Q) {
    return (Q.rear + 2) % QUEUE_MAX == Q.front;
}
void displayList(QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    int frontElem;

    printf("QUEUE: ");
    for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {
        printf("%c ", frontElem);
    }
    printf("\n");

    for (frontElem = front(temp); !isEmpty(temp); enqueue(frontElem, QP), dequeue(&temp), frontElem = front(temp)) {}
}