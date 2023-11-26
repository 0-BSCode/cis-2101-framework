#include "_header.h"
#include "../util/stack/_header.h"
#include <stdio.h>
#include <stdlib.h>

int* DFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));
    int *visited = (int*)calloc(MAX, sizeof(int));

    if (res != NULL && visited != NULL) {
        STACK stack;
        initialize(&stack);
        int node, neighbor, ctr;

        for (ctr = 0, node = src, push(node, &stack); !isEmpty(stack); node = top(stack), pop(&stack)) {
            res[ctr++] = node;
            visited[node] = 1;

            for (neighbor = MAX - 1; neighbor > -1; neighbor--) {
                if (matrix[node][neighbor] == 1 && visited[neighbor] == 0) {
                    push(neighbor, &stack);
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