#include "../util/queue/_header.h"
#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int* BFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));
    if (res != NULL) {
        int visited[MAX] = {0};
        int queued[MAX] = {0};
        QUEUE q;
        initialize(&q);
        enqueue(src, &q);
        int node, ctr;

        for (ctr = 0; ctr < MAX; ctr++) {
            res[ctr] = -1;
        }

        for (ctr = 0, node = front(q), queued[node] = 1; !isEmpty(q); node = front(q)) {
            printf("Node: %d\n", node);
            dequeue(&q);
            visited[node] = 1;
            res[ctr++] = node;
            int neighbor;
            for (neighbor = 0; neighbor < MAX; neighbor++) {
                printf("Neighbor: %d\n", neighbor);
                if (matrix[node][neighbor] == 1 && visited[neighbor] == 0 && queued[neighbor] == 0) {
                    enqueue(neighbor, &q);
                    queued[neighbor] = 1;
                    printf("Considering!");
                }
                printf("\n");
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