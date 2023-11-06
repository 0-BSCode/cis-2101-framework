#ifndef QUEUE_LINKEDLIST_V1
#define QUEUE_LINKEDLIST_V1
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *link;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initialize(Queue *QP);
void enqueue(char elem, Queue *QP);
void dequeue(Queue *QP);
void insertFront(char elem, Queue *QP);
void insertPos(int pos, char elem, Queue *QP);
char front(Queue Q);
bool isEmpty(Queue Q);
void makeNull(Queue *QP);
void displayList(Queue *QP);

#endif