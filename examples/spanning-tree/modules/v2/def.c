#include "../util/minHeap/_header.h"
#include "_header.h"

int prim(MATRIX matrix, int src) {
    int res = 0, visited[MAX] = {0};
    HEAP heap;
    initialize(&heap);

    int tail;
    for (tail = src; visited[tail] != 1;) {
        visited[tail] = 1;

        int head, cost;
        for (head = 0; head < MAX; head++) {
            cost = matrix[tail][head];
            if (cost != INF && visited[head] != 1) {
                Edge edge = {cost, {tail, head}};
                insert(&heap, edge);
            }
        }

        Edge minEdge = deleteMin(&heap);
        if (visited[minEdge.path.from] == 0 || visited[minEdge.path.to] == 0) {
            res += minEdge.cost;
            tail = minEdge.path.to;
        }

    }

    return res;
}

int kruskal(MATRIX matrix) {
    int res = 0, components[MAX] = {0};
    HEAP heap;
    initialize(&heap);

    int tail, head;
    for (tail = 0; tail < MAX; tail++) {
        components[tail] = tail;
    }

    // Adds links twice (bc matrix is symmetric)
    for (tail = 0; tail < MAX; tail++) {
        for (head = 0; head < MAX; head++) {
            if (matrix[tail][head] != INF) {
                Edge edge = {matrix[tail][head], {tail, head}};
                insert(&heap, edge);         
            }
        }
    }

    Edge trav;
    int compNum;
    for (compNum = MAX, trav = deleteMin(&heap);
         compNum > 1;
         trav = deleteMin(&heap)) {
            tail = trav.path.from;
            head = trav.path.to;

            if (components[tail] != components[head]) {
                res += trav.cost;

                int ctr;
                for (ctr = 0; ctr < MAX; ctr++) {
                    if (components[ctr] == components[head]) {
                        components[ctr] = components[tail];
                    }
                }

                compNum--;
            }
    }

    return res;
}