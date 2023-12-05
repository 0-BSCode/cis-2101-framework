#include "_header.h"
#include "../util/queue/_header.h"
#include <stdio.h>
#include <stdlib.h>

int* BFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));

    if (res != NULL) {
        QUEUE q;
        initialize(&q);

        int visited[MAX] = {0}, trav, ctr;
        for (ctr = 0, trav = src, enqueue(trav, &q); !isEmpty(q); dequeue(&q), trav = front(q)) {
            visited[trav] = 1;
            res[ctr++] = trav;

            int head;
            for (head = 0; head < MAX; head++) {
                if (matrix[trav][head] == 1 && visited[head] != 1) {
                    enqueue(head, &q);
                }
            }
        }
    }

    return res;
}

void printMatrix(MATRIX matrix) {
    int i, j;

    printf("\n----- MATRIX -----\n");
    for (i = 0; i < MAX; i++) {
        printf("[ ");
        for (j = 0; j < MAX; j++) {
            printf("%15d ", matrix[i][j]);
        }
        printf("]\n");
    }
}
void printArray(int* array) {
    int i;
    printf("\n----- ARRAY -----\n");
    printf("[ ");
    for (i = 0; i < MAX; i++) {
        printf("%15d ", array[i]);
    }
    printf("]\n");
}