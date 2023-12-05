#include "_header.h"
#include <stdio.h>
#include <stdlib.h>


int* dijkstra(MATRIX matrix, int src) {
    int *costs = (int*)malloc(sizeof(MAX));

    if (costs != NULL) {
        int visited[MAX] = {0};
        int tail;

        for (tail = 0; tail < MAX; tail++) {
            costs[tail] = tail == src ? 0 : INF;
        }

        int next, head, minCost, currCost;
        for (tail = src, next = src, minCost = INF; visited[tail] != 1; tail = next, minCost = INF) {
            visited[tail] = 1;

            for (head = 0; head < MAX; head++) {
                currCost = costs[tail] == INF || matrix[tail][head] == INF ? INF : costs[tail] + matrix[tail][head];
                if (currCost < costs[head]) {
                    costs[head] = currCost;
                }

                if (costs[head] < minCost && visited[head] != 1) {
                    minCost = costs[head];
                    next = head;
                }
            }
        }
    }

    return costs;
}

void floyd(MATRIX res, MATRIX matrix) {
    int tail, head, middle;

    for (tail = 0; tail < MAX; tail++) {
        for (head = 0; head < MAX; head++) {
            res[tail][head] = matrix[tail][head];
        }
    }

    for (tail = 0; tail < MAX; tail++) {
        res[tail][tail] = 0;
    }

    for (middle = 0; middle < MAX; middle++) {
        for (tail = 0; tail < MAX; tail++) {
            for (head = 0; head < MAX; head++) {
                if (res[tail][middle] != INF &&
                    res[middle][head] != INF &&
                    res[tail][middle] + res[middle][head] < res[tail][head]) {
                        res[tail][head] = res[tail][middle] + res[middle][head];
                    }
            }
        }
    }
}
void warshall(MATRIX res, MATRIX matrix) {
    int tail, head, mid;

    for (tail = 0; tail < MAX; tail++) {
        for (head = 0; head < MAX; head++) {
            res[tail][head] = matrix[tail][head] != INF || tail == head ? 1 : 0;
        }
    }

    for (mid = 0; mid < MAX; mid++) {
        for (tail = 0; tail < MAX; tail++) {
            for (head = 0; head < MAX; head++) {
                if (res[tail][mid] && res[mid][head]) {
                    res[tail][head] = 1;
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