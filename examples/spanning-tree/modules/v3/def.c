#include "../util/minHeap/_header.h"
#include "_header.h"

int prim(MATRIX matrix, int src) {
    int res = 0;
    int visited[MAX] = {0};
    HEAP H;
    initialize(&H);

    int node, next, neighbor;
    for (node = src; visited[node] != 1;) {
        visited[node] = 1;

        for (neighbor = 0; neighbor < MAX; neighbor++) {
            int cost = matrix[node][neighbor];
            if (cost != INF && visited[neighbor] != 1) {
                Edge e = {cost, {node, neighbor}};
                insert(&H, e);
            }
        }

        Edge edge = deleteMin(&H);
        if (visited[edge.path.to] != 1) {
            res += edge.cost;
            node = edge.path.to;
        }
    }

    return res;
}

int kruskal(MATRIX matrix) {
    int res = 0;
    int components[MAX] = {0};
    int node, neighbor;

    for (node = 0; node < MAX; node++) {
        components[node] = node;
    }

    HEAP H;
    initialize(&H);

    for (node = 0; node < MAX; node++) {
        for (neighbor = 0; neighbor < MAX; neighbor++) {
            int cost = matrix[node][neighbor];
            if (cost != INF) {
                Edge e = {cost, {node, neighbor}};
                insert(&H, e);
            }
        }
    }

    int compNum;
    Edge e;
    for (compNum = MAX, e = deleteMin(&H); e.cost != -1 && compNum > 1; e = deleteMin(&H))  {
        node = e.path.from;
        neighbor = e.path.to;
        if (components[node] != components[neighbor]) {
            res += e.cost;
            int ctr;

            for (ctr = 0; ctr < MAX; ctr++) {
                if (components[ctr] == components[neighbor]) {
                    components[ctr] = components[node];
                }
            }

            compNum--;
        }
    }
    return res;
}