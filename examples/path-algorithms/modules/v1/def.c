#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

int* dijkstra(MATRIX matrix, int src) {
    int *cost = (int *)calloc(MAX, sizeof(int));

    // Initialize set to track visited nodes
    int *visited = (int *)calloc(MAX, sizeof(int));
    
    if (cost != NULL && visited != NULL) {
        int ctr;

        // Initial cost to get to each node from src
        for (ctr = 0; ctr < MAX; ctr++) {
            cost[ctr] = ctr == src ? 0 : INF;
        }

        // currTail = current tail we're considering
        // head = vertices we can get to from currTail
        // nextTail = next tail we'll consider
        // currCost = cost to get from currTail to an unvisited head
        // minCost = smallest cost path from currTail to an unvisited head
        int currTail, head, nextTail, currCost, minCost;
        for (currTail = src, nextTail = src, minCost = INF; visited[currTail] != 1; currTail = nextTail, minCost = INF) {
            visited[currTail] = 1;
            for (head = 0; head < MAX; head++) {
                // Prevent integer overflows
                currCost = cost[currTail] == INF || matrix[currTail][head] == INF ? INF : cost[currTail] + matrix[currTail][head];

                // Update cost to get to a head
                // if we found a cheaper path to it
                if (currCost < cost[head]) {
                    cost[head] = currCost;
                }
                
                // Update cheapest path and next node to visit
                if (cost[head] < minCost && visited[head] == 0) {
                    nextTail = head;
                    minCost = cost[head];
                }
            }
        }
    }

    return cost;
}

void floyd(MATRIX res, MATRIX cost) {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            res[i][j] = cost[i][j];
        }
    }

    for (i = 0; i < MAX; i++) {
        res[i][i] = 0;
    }

    for (k = 0; k < MAX; k++) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (res[i][k] != INF && res[k][j] != INF && res[i][k] + res[k][j] < res[i][j]) {
                    res[i][j] = res[i][k] + res[k][j];
                }
            }
        }
    }
}

void warshall(MATRIX res, MATRIX costs) {
    int i, j, k;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            res[i][j] = costs[i][j] == INF ? 0 : 1;
        }
    }

    for (i = 0; i < MAX; i++) {
        res[i][i] = 1;
    }

    for (k = 0; k < MAX; k++) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (res[i][j] == 0) {
                    res[i][j] = res[i][k] && res[k][j];
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