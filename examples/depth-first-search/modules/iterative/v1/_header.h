#ifndef DFS_ITERATIVE_V1
#define DFS_ITERATIVE_V1

#define MAX 5
typedef int MATRIX[][MAX];

int* DFS(MATRIX matrix, int src);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif