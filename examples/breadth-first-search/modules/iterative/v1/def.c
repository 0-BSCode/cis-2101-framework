#include "_header.h"
#include "../util/queue/_header.h"
#include <stdio.h>
#include <stdlib.h>

int* BFS(MATRIX matrix, int src) {
    int* res = (int*)malloc(MAX * sizeof(int));
    
    if (res != NULL) {
        QUEUE queue;
        initialize(&queue);
        int *visited = (int*)calloc(MAX, sizeof(int));
        int node, neighbor, ctr;

        for (ctr = 0, node = src, enqueue(node, &queue); !isEmpty(queue); dequeue(&queue), node = front(queue)) {
            res[ctr++] = node;
            visited[node] = 1;

            for (neighbor = 0; neighbor < MAX; neighbor++) {
                if (matrix[node][neighbor] == 1 && visited[neighbor] == 0) {
                    enqueue(neighbor, &queue);
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