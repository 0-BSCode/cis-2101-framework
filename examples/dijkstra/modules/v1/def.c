#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int* dijkstra(MATRIX matrix, int src) {
    // Initialize costs
    int *cost = (int *)calloc(MAX, sizeof(int));

    // Initialize set to track visited nodes
    int *visited = (int *)calloc(MAX, sizeof(int));
    
    if (cost != NULL && visited != NULL) {
        int ctr;

        for (ctr = 0; ctr < MAX; ctr++) {
            cost[ctr] = ctr == src ? 0 : INF;
        }

        int currTail, head, nextTail, currCost, minCost;
        for (currTail = src, nextTail = src, minCost = INF; visited[currTail] != 1; currTail = nextTail, minCost = INF) {
            visited[currTail] = 1;
            for (head = 0; head < MAX; head++) {
                // Prevent integer overflows
                if (cost[currTail] != INF && matrix[currTail][head] != INF) {
                    currCost = cost[currTail] + matrix[currTail][head];
                } else {
                    currCost = INF;
                }
                cost[head] = currCost < cost[head] ? currCost : cost[head];
                
                if (cost[head] < minCost && visited[head] == 0) {
                    nextTail = head;
                    minCost = cost[head];
                }
            }
        }
    }

    return cost;
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