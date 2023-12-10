#include "_header.h"
#include "../util/stack/_header.h"
#include <stdio.h>
#include <stdlib.h>

int* DFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));

    if (res != NULL) {
        int visited[MAX] = {0};
        int stacked[MAX] = {0};
        STACK s;
        initialize(&s);
        int node, neighbor, ctr;

        for (ctr = 0; ctr < MAX; ctr++) {
            res[ctr] = -1;
        }

        for (ctr = 0, node = src, push(node, &s); !isEmpty(s); node = top(s)) {
            pop(&s);
            stacked[node] = 1;
            visited[node] = 1;
            res[ctr++] = node;

            for (neighbor = MAX - 1; neighbor > -1; neighbor--) {
                if (matrix[node][neighbor] == 1 && visited[neighbor] == 0 && stacked[neighbor] == 0) {
                    push(neighbor, &s);
                    stacked[neighbor] = 1;
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