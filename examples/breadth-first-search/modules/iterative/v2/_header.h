#ifndef BFS_ITERATIVE_V1
#define BFS_ITERATIVE_V1

#define MAX 5
typedef int MATRIX[MAX][MAX];

int* BFS(MATRIX matrix, int src);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif