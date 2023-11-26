#ifndef DFS_RECURSIVE_V1
#define DFS_RECRUSIVE_V1

#define MAX 5
typedef int MATRIX[][MAX];

int* DFS(MATRIX matrix, int src);
void dfsHelper(MATRIX matrix, int vertex, int *visited, int *res, int *ctr);
void printMatrix(MATRIX matrix);
void printArray(int* array);


#endif