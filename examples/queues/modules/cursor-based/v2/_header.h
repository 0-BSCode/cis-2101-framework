#ifndef QUEUE_CURSORBASED_V2
#define QUEUE_CURSORBASED_V2
#include <stdbool.h>

#define MAX 10

typedef struct {
    char data;
    int next;
} Node;

typedef struct {
    Node Nodes[MAX];
    int Avail;
} VirtHeap;

typedef int LIST;

typedef struct {
    VirtHeap VH;
    LIST L;
} QUEUE;

void initialize(QUEUE *QP);
void enqueue(char elem, QUEUE *QP);
void dequeue(QUEUE *QP);
void insertFront(char elem, QUEUE *QP);
void insertPos(int pos, char elem, QUEUE *QP);
char front(QUEUE Q);
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void makeNull(QUEUE *QP);
void displayList(QUEUE *QP);

int allocSpace(QUEUE *QP);
void deallocSpace(QUEUE *QP, int idx);


#endif