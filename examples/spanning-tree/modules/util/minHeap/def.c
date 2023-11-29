#include "_header.h"
#include <stdio.h>


void initialize(HEAP *H) {
    H->lastIdx = -1;
}

void insert(HEAP *H, Edge data) {
    if (H->lastIdx < HEAP_MAX - 1) {
        H->edges[++H->lastIdx] = data;
        int idx;

        for (idx = H->lastIdx; idx > 0 && data.cost < H->edges[(idx - 1) / 2].cost; idx = (idx - 1) / 2) {
            Edge temp = H->edges[idx];
            H->edges[idx] = H->edges[(idx - 1) / 2];
            H->edges[(idx - 1) / 2] = temp;
        }
    }
}
Edge deleteMin(HEAP *H) {
    Edge res = {-1,{-1,-1}};
    if (H->lastIdx > -1) {
        res = H->edges[0];
        H->edges[0] = H->edges[H->lastIdx];
        H->edges[H->lastIdx--] = res;
        heapify(H, 0);
    }

    return res;
}
void heapify(HEAP *H, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left <= H->lastIdx && H->edges[left].cost < H->edges[smallest].cost) {
        smallest = left;
    }

    if (right <= H->lastIdx && H->edges[right].cost < H->edges[smallest].cost) {
        smallest = right;
    }

    if (smallest != idx) {
        Edge temp = H->edges[idx];
        H->edges[idx] = H->edges[smallest];
        H->edges[smallest] = temp;
        heapify(H, smallest);
    }
}
void displayHeap(HEAP H) {
    int ctr;

    printf("----- HEAP -----\n");
    for (ctr = 0; ctr <= H.lastIdx; ctr++) {
        displayEdge(H.edges[ctr]);
    }
    printf("----------------\n");
}

void displayEdge(Edge e) {
    printf("{\n");
    printf("%10s:", "Cost");
    printf("%5d\n", e.cost);
    printf("%10s:", "From");
    printf("%5d\n", e.path.from);
    printf("%10s:", "To");
    printf("%5d\n", e.path.to);
    printf("}\n");
}