#include "_header.h"
#include "../util/stack/_header.h"
#include <stdio.h>
#include <stdlib.h>

int* DFS(MATRIX matrix, int src) {
    int *res = (int*)malloc(MAX * sizeof(int));

    if (res != NULL) {
        STACK s;
        initialize(&s);
        int visited[MAX] = {0};

        int trav, head, ctr;
        for (ctr = 0, trav = src, push(trav, &s); !isEmpty(s); trav = top(s), pop(&s)) {
            visited[trav] = 1;
            res[ctr++] = trav;

            for (head = MAX - 1; head > -1; head--) {
                if (matrix[trav][head] == 1 && visited[head] != 1) {
                    push(head, &s);
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