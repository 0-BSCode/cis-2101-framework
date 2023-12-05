#include "modules/v1/_header.h"

int main() {
    int m1[MAX][MAX] = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    int m2[MAX][MAX] = {
        {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, 2},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, 2, INF, 2, INF}
    };

    int m3[MAX][MAX] = {
         {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, INF},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, INF, INF, 2, INF}
     };

    int m4[MAX][MAX] = {
        {INF, 2, INF, 1, INF},
        {INF, INF, 3, INF, INF},
        {INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, 1},
        {INF, INF, 1, INF, INF}
     };

    // DIJKSTRA'S
    printMatrix(m1);
    int *minCosts = dijkstra(m1, 0);
    printArray(minCosts);

    // FLOYD'S
    MATRIX fRes = {};
    floyd(fRes, m1);
    printMatrix(fRes);

    // WARSHALL'S
    MATRIX wRes = {};
    warshall(wRes, m1);
    printMatrix(wRes);

    return 0;
}