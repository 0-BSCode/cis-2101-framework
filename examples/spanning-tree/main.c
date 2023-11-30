#include "modules/v1/_header.h"
#include <stdio.h>

int main() {
    MATRIX m1 = {
        { INF, 1, 5, 4, 6, 5 },
        { 1, INF, 5, INF, INF, 6 },
        { 5, 5, INF, 2, INF, INF },
        { 4, INF, 2, INF, 1, INF },
        { 6, INF, INF, 1, INF, 3 },
        { 5, 6, INF, INF, 3, INF }
    };  // 11

    MATRIX m2 = {
        {INF, 2, INF, 6, INF, INF},
        {2, INF, 3, 8, 5, INF},
        {INF, 3, INF, INF, 7, INF},
        {6, 8, INF, INF, 9, INF},
        {INF, 5, 7, 9, INF, 1},
        {INF, INF, INF, INF, 1, INF},
    };  // 17

    MATRIX m3 = {
        {INF, 4, INF, 6, INF, INF},
        {4, INF, 8, INF, 5, INF},
        {INF, 8, INF, 7, INF, 4},
        {6, INF, 7, INF, 9, INF},
        {INF, 5, INF, 9, INF, 1},
        {INF, INF, 4, INF, 1, INF},
    }; // 20

    int minCost;
    minCost = prim(m1, 0);
    printf("Minimum cost: %d\n", minCost);

    return 0;
}