#ifndef DIJKSTRA_V1
#define DIJKSTRA_V1

#define MAX 5
#define INF __INT_MAX__

typedef int MATRIX[][MAX];
int* dijkstra(MATRIX matrix, int src);
void printMatrix(MATRIX matrix);
void printArray(int* array);

#endif