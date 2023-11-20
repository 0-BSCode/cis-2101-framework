#ifndef QUEUE_ARRAY_V3
#define QUEUE_ARRAY_V3
#include <stdbool.h>

#define MAX 10

typedef struct {
    char Elem[MAX];
    int front;
    int rear;
} QUEUE;

void initialize(QUEUE *QP);
void enqueue(char elem, QUEUE *QP);
void dequeue(QUEUE *QP);
char front (QUEUE Q);
void insertFront(char elem, QUEUE *QP);
void insertAtPos(int pos, char elem, QUEUE *QP);
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void makeNull(QUEUE *QP);
void displayList(QUEUE *QP);

#endif