#include "_header.h"
#include <stdio.h>
#include <stdbool.h>

void initialize(QUEUE *QP) {
    QP->rear = -1;
    QP->front = 0;
}
void enqueue(char elem, QUEUE *QP) {
    if (!isFull(*QP)) {
        QP->rear = (QP->rear + 1) % MAX;
        QP->Elem[QP->rear] = elem;
    }
}
void dequeue(QUEUE *QP) {
    if (!isEmpty(*QP)) {
        QP->front = (QP->front + 1) % MAX;
    }
}
char front (QUEUE Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.Elem[Q.front];
    }
}
void insertFront(char elem, QUEUE *QP) {
    if (!isFull(*QP)) {
        QUEUE temp;
        initialize(&temp);

        enqueue(elem, &temp);
        char frontElem;

        for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {}

        *QP = temp;
    }
}
void insertAtPos(int pos, char elem, QUEUE *QP) {
    if (!isFull(*QP)) {
        QUEUE temp;
        initialize(&temp);
        char frontElem;
        int ctr;

        for (frontElem = front(*QP), ctr = 0; !isEmpty(*QP) && ctr < pos; enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP), ctr++) {}

        enqueue(elem, &temp);

        for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {}

        *QP = temp;
    }
}
bool isEmpty(QUEUE Q) {
    return (Q.rear + 1) % MAX == Q.front;
}
bool isFull(QUEUE Q) {
    return (Q.rear + 2) % MAX == Q.front;
}
void makeNull(QUEUE *QP) {
    while (!isEmpty(*QP)) {
        dequeue(QP);
    }
}
void displayList(QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    char frontElem;

    printf("QUEUE: ");
    for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {
        printf("%c ", frontElem);
    }
    printf("\n");

    for (frontElem = front(temp); !isEmpty(temp); enqueue(frontElem, QP), dequeue(&temp), frontElem = front(temp)) {}
}