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
    
}
