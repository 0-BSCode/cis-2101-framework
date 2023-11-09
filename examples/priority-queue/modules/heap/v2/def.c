#include "_header.h"
#include <stdio.h>

void initialize(HEAP *H) {
    H->lastNdx = -1;
}
void insert(HEAP *H, int elem) {
    if (H->lastNdx < MAX - 1) {
        H->lastNdx++;
        H->Elem[H->lastNdx] = elem;
        int idx, temp;

        for (idx = H->lastNdx; idx > 0 && H->Elem[idx] < H->Elem[(idx - 1) / 2]; idx = (idx - 1) / 2) {
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
        H->Elem[0] = H->Elem[H->lastNdx--];
        heapify(H, 0);
    }
}
void heapify(HEAP *H, int idx) {
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int smallest = idx;

    if (left <= H->lastNdx && H->Elem[left] < H->Elem[smallest]) {
        smallest = left;
    }

    if (right <= H->lastNdx && H->Elem[right] < H->Elem[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        int temp = H->Elem[idx];
        H->Elem[idx] = H->Elem[smallest];
        H->Elem[smallest] = temp;
        heapify(H, smallest);
    }
}
void makeNull(HEAP *H) {
    H->lastNdx = -1;
}

void displayHeap(HEAP H) {
    int idx;

    printf("[ ");
    for (idx = 0; idx <= H.lastNdx; idx++) {
        printf("%d ", H.Elem[idx]);
    }
    printf("]\n");
}