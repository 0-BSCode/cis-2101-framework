#ifndef PATHALGOS_V3
#define PATHALGOS_V3

#define MAX 5
#define INF __INT_MAX__

typedef int MATRIX[MAX][MAX];

int *dijkstra(MATRIX matrix, int src);
void floyd(MATRIX res, MATRIX matrix);
void warshall(MATRIX res, MATRIX matrix);
void printMatrix(MATRIX matrix);
void printArray(int *arr);

#endif
