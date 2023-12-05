#include "modules/recursive/v2/_header.h"

int main() {
    int matrix[MAX][MAX] = {
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int matrix2[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int matrix3[MAX][MAX] = {
         {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
     };

    int matrix4[MAX][MAX] = {
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
     };

    printMatrix(matrix);
    int *res = DFS(matrix, 0);

    printArray(res);


    return 0;
}