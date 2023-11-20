#include "_header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(QUEUE *QP) {
    QP->front = NULL;
    QP->rear = NULL;
}
void enqueue(char elem, QUEUE *QP) {
    Node *node = (Node *)malloc(sizeof(Node));

    if (node != NULL) {
        node->data = elem;
        node->next = NULL;

        if (isEmpty(*QP)) {
            QP->front = node;
        } else {
            QP->rear->next = node;
        }

        QP->rear = node;
    }
}
void dequeue(QUEUE *QP) {
    if (!isEmpty(*QP)) {
        Node *temp = QP->front;
        QP->front = temp->next;
        free(temp);
    }
}
void insertFront(char elem, QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    char frontElem;

    enqueue(elem, &temp);
    for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {}

    *QP = temp;
}
void insertAtPos(int pos, char elem, QUEUE *QP) {
    QUEUE temp;
    initialize(&temp);
    int ctr;
    char frontElem;

    for (frontElem = front(*QP), ctr = 0; !isEmpty(*QP) && ctr < pos; enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP), ctr++) {}

    enqueue(elem, &temp);

    for (frontElem = front(*QP); !isEmpty(*QP); enqueue(frontElem, &temp), dequeue(QP), frontElem = front(*QP)) {}

    *QP = temp;
}
char front(QUEUE Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.front->data;
    }

    return res;
}
bool isEmpty(QUEUE Q) {
    return Q.front == NULL;
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