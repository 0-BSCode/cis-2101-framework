#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int* DFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));

    if (res != NULL) {
        int visited[MAX] = {0}, ctr = 0;
        dfsHelper(matrix, src, visited, res, &ctr);
    }

    return res;
}

void dfsHelper(MATRIX matrix, int vertex, int *visited, int *res, int *ctr) {
    if (*ctr == MAX) {
        return;
    } else {
        visited[vertex] = 1;
        res[(*ctr)++] = vertex;

        int head;
        for (head = 0; head < MAX; head++) {
            if (matrix[vertex][head] == 1 && visited[head] != 1) {
                dfsHelper(matrix, head, visited, res, ctr);
            }
        }
    }
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