#include "_header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(Queue *QP) {
    QP->front = NULL;
    QP->rear = NULL;
}

void enqueue(char elem, Queue *QP) {
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp != NULL) {
        temp->data = elem;
        temp->link = NULL;

        if (QP->front == NULL) {
            QP->front = temp;
        } else {
            QP->rear->link = temp;
        }

        QP->rear = temp;
    }
}

void dequeue(Queue *QP) {
    if (!isEmpty(*QP)) {
        Node *temp = QP->front;
        QP->front = temp->link;
        free(temp);
    }
}

void insertFront(char elem, Queue *QP) {
    Node *temp = (Node *)malloc(sizeof(Node));
    
    if (temp != NULL) {
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
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp != NULL && pos >= 0) {
        int ctr;
        Queue tempQ;
        initialize(&tempQ);

        // TODO: Check if pos is valid
        for (ctr = 0; ctr < pos && !isEmpty(*QP); ctr++) {
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

char front(Queue Q) {
    char res = '\0';

    if (!isEmpty(Q)) {
        res = Q.front->data;
    }

    return res;
}

bool isEmpty(Queue Q) {
    return Q.front == NULL;
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