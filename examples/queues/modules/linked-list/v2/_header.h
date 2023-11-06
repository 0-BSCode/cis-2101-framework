#ifndef QUEUE_LINKEDLIST_V2
#define QUEUE_LINKEDLIST_V2
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} QUEUE;

void initialize(QUEUE *QP);
void enqueue(char elem, QUEUE *QP);
void dequeue(QUEUE *QP);
void insertFront(char elem, QUEUE *QP);
void insertPos(int pos, char elem, QUEUE *QP);
char front(QUEUE Q);
bool isEmpty(QUEUE Q);
void makeNull(QUEUE *QP);
void displayList(QUEUE *QP);

#endif