#include "_header.h"
#include "../util/minHeap/_header.h"
#include <stdio.h>

int prim(MATRIX matrix, int src) {
    int res = 0, visited[MAX] = {0};
    HEAP heap;
    initialize(&heap);

    int currNode, neighbor;
    for (currNode = src; visited[currNode] == 0;) {
        // Mark node as visited
        visited[currNode] = 1;

        // Only add edges that lead to unvisited nodes
        for (neighbor = 0; neighbor < MAX; neighbor++) {
            int cost = matrix[currNode][neighbor];
            if (cost != INF && visited[neighbor] == 0) {
                Edge edge = {cost, {currNode, neighbor}};
                insert(&heap, edge);
            }
        }

        // Update cost based on cheapest edge
        Edge minEdge = deleteMin(&heap);
        if (visited[minEdge.path.from] != 1 || visited[minEdge.path.to] != 1) {
            res += minEdge.cost;
            // If both nodes are visited, currNode gets set to a visited node,
            // terminating the loop
            currNode = minEdge.path.to;        
        }
    }

    return res;
}
int kruskal(MATRIX matrix) {
    int res = 0, components[MAX] = {0}, from, to;
    Edge data;
    HEAP heap;
    initialize(&heap);

    for (from = 0; from < MAX; from++) {
        components[from] = from;
    }

    for (from = 0; from < MAX; from++) {
        for (to = 0; to < MAX; to++) {
            if (matrix[from][to] != INF) {
                data.cost = matrix[from][to];
                data.path.from = from;
                data.path.to = to;
                insert(&heap, data);
            }

        }
    }

    int compNum;
    for (compNum = MAX, data = deleteMin(&heap); compNum > 1; data = deleteMin(&heap)) {
        from = data.path.from;
        to = data.path.to;

        if (components[from] != components[to]) {
            res += data.cost;
            int ctr;
            for (ctr = 0; ctr < MAX; ctr++) {
                if (components[ctr] == components[to]) {
                    components[ctr] = components[from];
                }
            }
            compNum--;
        }
    }

    return res;
}
