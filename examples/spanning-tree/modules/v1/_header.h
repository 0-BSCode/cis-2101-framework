#ifndef SPANNINGTREE_V1
#define SPANNINGTREE_V1

#define MAX 5
#define INF __INT_MAX__

typedef int MATRIX[][MAX];
int prim(MATRIX matrix, int src);
int kruskal(MATRIX matrix);

#endif