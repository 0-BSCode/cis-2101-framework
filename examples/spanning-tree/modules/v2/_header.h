#ifndef SPANNINGTREE_V2
#define SPANNINGTREE_V2

#define MAX 6
#define INF __INT_MAX__

typedef int MATRIX[MAX][MAX];
int prim(MATRIX matrix, int src);
int kruskal(MATRIX matrix);

#endif