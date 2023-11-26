#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY
#include <stdbool.h>

#define QUEUE_MAX 10

typedef struct {
    int Elem[QUEUE_MAX];
    int front;
    int rear;
} QUEUE;

void initialize(QUEUE *QP);
void enqueue(int elem, QUEUE *QP);
void dequeue(QUEUE *QP);
int front (QUEUE Q);
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void displayList(QUEUE *QP);

#endif