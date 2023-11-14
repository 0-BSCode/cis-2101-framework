#include "_header.h"
#include <stdio.h>

void initialize(HEAP *H) {
    H->lastNdx = -1;
}

void insert(HEAP *H, int elem) {
    if (H->lastNdx < MAX - 1) {
        int idx, temp;
        H->Elem[++(H->lastNdx)] = elem;
        for (idx = H->lastNdx; idx > 0 && H->Elem[(idx - 1) / 2] > elem; idx = (idx - 1) / 2) {
            temp = H->Elem[idx];
            H->Elem[idx] = H->Elem[(idx - 1) / 2];
            H->Elem[(idx - 1) / 2] = temp;
        }
    }
}

int deleteMin(HEAP *H) {
    int res = -1;
    if (H->lastNdx > -1) {
        res = H->Elem[0];
        H->Elem[0] = H->Elem[H->lastNdx];
        H->Elem[H->lastNdx] = res;
        H->lastNdx--;
        minHeapify(H, 0);
    }
}

void minHeapify(HEAP *H, int idx) {
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int smallestIdx = idx;

    if (left <= H->lastNdx && H->Elem[left] < H->Elem[smallestIdx]) {
        smallestIdx = left;
    }

    if (right <= H->lastNdx && H->Elem[right] < H->Elem[smallestIdx]) {
        smallestIdx = right;
    }

    if (smallestIdx != idx) {
        int temp = H->Elem[idx];
        H->Elem[idx] = H->Elem[smallestIdx];
        H->Elem[smallestIdx] = temp;
        minHeapify(H, smallestIdx);
    }
}

void makeNull(HEAP *H) {
    H->lastNdx = -1;
}

void displayHeap(HEAP H) {
    int ctr;
    printf("[ ");
    for (ctr = 0; ctr <= H.lastNdx; ctr++) {
        printf("%d ", H.Elem[ctr]);
    }
    printf("]\n");
}

void insertList(HEAP *H, int elem) {
    if (H->lastNdx < MAX - 1) {
        H->lastNdx++;
        H->Elem[H->lastNdx] = elem;
    }
}
void buildMinHeap(HEAP *H) {
    int idx;
    for (idx = (H->lastNdx - 1) / 2; idx >= 0; idx--) {
        minHeapify(H, idx);
    }
}

void heapSort(HEAP *H) {
    int len = H->lastNdx, idx;

    for (idx = H->lastNdx; idx >= 0; idx--) {
        deleteMin(H);
    }

    H->lastNdx = len;
}