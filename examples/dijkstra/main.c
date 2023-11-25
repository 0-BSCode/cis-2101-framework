#include "modules/v1/_header.h"

int main() {
    int matrix[MAX][MAX] = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    int matrix2[MAX][MAX] = {
        {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, 2},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, 2, INF, 2, INF}
    };

    int matrix3[MAX][MAX] = {
         {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, INF},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, INF, INF, 2, INF}
     };

    int matrix4[MAX][MAX] = {
        {INF, 2, INF, 1, INF},
        {INF, INF, 3, INF, INF},
        {INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, 1},
        {INF, INF, 1, INF, INF}
     };

    printMatrix(matrix3);
    int *minCosts = dijkstra(matrix3, 0);

    printArray(minCosts);


    return 0;
}