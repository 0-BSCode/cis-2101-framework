#ifndef PRIORITYQUEUE_HEAP_V1
#define PRIORITYQUEUE_HEAP_V1

#define MAX 14

typedef struct {
    int Elem[MAX];
    int lastNdx;
} HEAP;

void initialize(HEAP *H);
void insert(HEAP *H, int elem);
int deleteMin(HEAP *H);
void minHeapify(HEAP *H, int idx);
void makeNull(HEAP *H);

void displayHeap(HEAP H);

#endif
