#include "modules/v3/_header.h"

int main() {
    int m1[MAX][MAX] = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    /*
    [           0          10          50          30          60 ]
    [          70           0          50         100          60 ]
    [          20          30           0          50          10 ]
    [          40          50          20           0          30 ]
    [  2147483647  2147483647  2147483647  2147483647           0 ]
    */

    int m2[MAX][MAX] = {
        {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, 2},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, 2, INF, 2, INF}
    };

    /*
    [           0           1           4           3           3 ]
    [           1           0           4           2           2 ]
    [           4           4           0           3           5 ]
    [           3           2           3           0           2 ]
    [           3           2           5           2           0 ]
    */

    int m3[MAX][MAX] = {
         {INF, 1, 4, INF, INF},
        {1, INF, 4, 2, INF},
        {4, 4, INF, 3, INF},
        {INF, 2, 3, INF, 2},
        {INF, INF, INF, 2, INF}
     };

    /*
    [           0           1           4           3           5 ]
    [           1           0           4           2           4 ]
    [           4           4           0           3           5 ]
    [           3           2           3           0           2 ]
    [           5           4           5           2           0 ]
    */

    int m4[MAX][MAX] = {
        {INF, 2, INF, 1, INF},
        {INF, INF, 3, INF, INF},
        {INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, 1},
        {INF, INF, 1, INF, INF}
     };

    /*
    [           0           2           3           1           2 ]
    [  2147483647           0           3           5           6 ]
    [  2147483647  2147483647           0           2           3 ]
    [  2147483647  2147483647           2           0           1 ]
    [  2147483647  2147483647           1           3           0 ]
    */

    // DIJKSTRA'S
    printMatrix(m1);
    int *minCosts = dijkstra(m1, 3);
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