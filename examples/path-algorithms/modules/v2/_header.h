#ifndef PATHALGOS_V2
#define PATHALGOS_V2

#define MAX 5
#define INF __INT_MAX__

typedef int MATRIX[MAX][MAX];

int* dijkstra(MATRIX matrix, int src);
void floyd(MATRIX res, MATRIX matrix);
void warshall(MATRIX res, MATRIX matrix);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif