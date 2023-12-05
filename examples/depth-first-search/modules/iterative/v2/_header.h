#ifndef DFS_ITERATIVE_V2
#define DFS_ITERATIVE_V2

#define MAX 5
typedef int MATRIX[MAX][MAX];

int* DFS(MATRIX matrix, int src);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif