#ifndef PRIORITYQUEUE_HEAP
#define PRIORITYQUEUE_HEAP

#define HEAP_MAX 15

typedef struct {
    int from;
    int to;
} EdgeInfo;

typedef struct {
    int cost;
    EdgeInfo path;
} Edge;

typedef struct {
    Edge edges[HEAP_MAX];
    int lastIdx;
} HEAP;

void initialize(HEAP *H);
void insert(HEAP *H, Edge data);
Edge deleteMin(HEAP *H);
void heapify(HEAP *H, int idx);
void displayHeap(HEAP H);
void displayEdge(Edge e);

#endif