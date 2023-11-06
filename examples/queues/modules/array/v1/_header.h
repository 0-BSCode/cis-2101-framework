#ifndef QUEUE_ARRAY_V1
#define QUEUE_ARRAY_V1
#include <stdbool.h>

#define MAX 8

typedef struct {
    char Elem[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *QP);
void enqueue(char elem, Queue *QP);
void dequeue(Queue *QP);
char front(Queue Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void makeNull(Queue *QP);
void displayList(Queue *QP);

#endif