#ifndef SPANNINGTREE_V3
#define SPANNINGTREE_V3

#define MAX 6
#define INF __INT_MAX__
typedef int MATRIX[MAX][MAX];

int prim(MATRIX matrix, int src);
int kruskal(MATRIX matrix);

#endif