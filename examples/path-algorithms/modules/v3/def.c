#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int *dijkstra(MATRIX matrix, int src) {
    int *costs = (int *)malloc(MAX * sizeof(int));
    if (costs != NULL) {
        int visited[MAX] = {0};
        int node;

        for (node = 0; node < MAX; node++) {
            costs[node] = node == src ? 0 : INF;
        }

        int next, neighbor, currCost, minCost;
        for (node = src; visited[node] == 0; node = next) {
            visited[node] = 1;
            minCost = INF;

            for (neighbor = 0; neighbor < MAX; neighbor++) {
                currCost = costs[node] == INF || matrix[node][neighbor] == INF ? INF : costs[node] + matrix[node][neighbor];
                if (currCost < costs[neighbor]) {
                    costs[neighbor] = currCost;
                }

                if (costs[neighbor] < minCost && visited[neighbor] == 0) {
                    minCost = costs[neighbor];
                    next = neighbor;
                }
            }
        }
    }
    return costs;
}
void floyd(MATRIX res, MATRIX matrix) {
    int node, neighbor, middle;
    for (node = 0; node < MAX; node++) {
        for (neighbor = 0; neighbor < MAX; neighbor++) {
            res[node][neighbor] = node == neighbor ? 0 : matrix[node][neighbor];
        }
    }

    for (middle = 0; middle < MAX; middle++) {
        for (node = 0; node < MAX; node++) {
            for (neighbor = 0; neighbor < MAX; neighbor++) {
                if (res[node][middle] != INF && 
                    res[middle][neighbor] != INF && 
                    res[node][middle] + res[middle][neighbor] < res[node][neighbor]) {
                    res[node][neighbor] = res[node][middle] + res[middle][neighbor];
                }
            }
        }
    }
}
void warshall(MATRIX res, MATRIX matrix) {
    int node, middle, neighbor;
    for (node = 0; node < MAX; node++) {
        for (neighbor = 0; neighbor < MAX; neighbor++) {
            res[node][neighbor] = node != neighbor && matrix[node][neighbor] == INF ? 0 : 1;
        }
    }

    for (middle = 0; middle < MAX; middle++) {
        for (node = 0; node < MAX; node++) {
            for (neighbor = 0; neighbor < MAX; neighbor++) {
                if (res[node][middle] && res[middle][neighbor]) {
                        res[node][neighbor] = 1;
                    }
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
            printf("%11d ", matrix[i][j]);
        }
        printf("]\n");
    }
}
void printArray(int* array) {
    int i;
    printf("\n----- ARRAY -----\n");
    printf("[ ");
    for (i = 0; i < MAX; i++) {
        printf("%11d ", array[i]);
    }
    printf("]\n");
}