#ifndef QUEUE_CURSORBASED_V1
#define QUEUE_CURSORBASED_V1
#include <stdbool.h>

#define MAX 8

typedef int LIST;

typedef struct node {
    char data;
    int next;
} Node;

typedef struct {
    Node Nodes[MAX];
    int Avail;
} VirtualHeap;

typedef struct {
    LIST front;
    LIST rear;
    VirtualHeap VH;
} Queue;

void initialize(Queue *QP);
void enqueue(char elem, Queue *QP);
void dequeue(Queue *QP);
void insertFront(char elem, Queue *QP);
void insertPos(int pos, char elem, Queue *QP);
char front(Queue Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void makeNull(Queue *QP);
void displayList(Queue *QP);

int allocSpace(VirtualHeap *VHP);
void deallocSpace(VirtualHeap *VHP, int idx);

#endif