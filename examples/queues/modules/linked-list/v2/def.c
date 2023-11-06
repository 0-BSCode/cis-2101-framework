#include "_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(QUEUE *QP) {
    QP->front = NULL;
    QP->rear = NULL;
}

void enqueue(char elem, QUEUE *QP) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp != NULL) {
        temp->data = elem;
        temp->next = NULL;

        if (QP->front ==  NULL) {
            QP->front = temp;
        } else {
            QP->rear->next = temp;

        }
        QP->rear = temp;
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

    for (; !isEmpty(*QP); enqueue(front(*QP), &temp), dequeue(QP)) {}
    enqueue(elem, QP);
    for (; !isEmpty(temp); enqueue(front(temp), QP), dequeue(&temp)) {}
}

void insertPos(int pos, char elem, QUEUE *QP) {
    if (pos >= 0) {
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
        res = Q.front->data;
    }

    return res;
}

bool isEmpty(QUEUE Q) {
    return Q.front == NULL;
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