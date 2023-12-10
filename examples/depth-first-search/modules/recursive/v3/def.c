#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int* DFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(sizeof(MAX * sizeof(int)));

    if (res != NULL) {
        int ctr = 0, visited[MAX] = {0};
        dfsHelper(matrix, src, visited, res, &ctr);
    }

    return res;
}
void dfsHelper(MATRIX matrix, int vertex, int *visited, int *res, int *ctr) {
    visited[vertex] = 1;
    res[(*ctr)++] = vertex;

    int neighbor;
    for (neighbor = 0; neighbor < MAX; neighbor++) {
        if (matrix[vertex][neighbor] == 1 && visited[neighbor] == 0) {
            dfsHelper(matrix, neighbor, visited, res, ctr);
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