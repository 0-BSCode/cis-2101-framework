#include "modules/v1/_header.h"

int main() {
    int matrix[MAX][MAX] = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    printMatrix(matrix);
    int *minCosts = dijkstra(matrix, 0);

    printArray(minCosts);


    return 0;
}