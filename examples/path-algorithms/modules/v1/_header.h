#ifndef PATHALGOS_V1
#define PATHALGOS_V1

#define MAX 5
#define INF __INT_MAX__

typedef int MATRIX[][MAX];
int* dijkstra(MATRIX matrix, int src);
void floyd(MATRIX res, MATRIX costs);
void warshall(MATRIX res, MATRIX costs);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif