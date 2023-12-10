#include "_header.h"
#include <stdio.h>
#include <stdlib.h>

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
void displayMatrix(MATRIX matrix) {
    printf("\n\nDetails of the Matrix :: ");
    printf("\n---------------------------");
    printf("\n\n%-7s", "Source");
    printf("%15s", "Cost");
    printf("\n%-7s%15s\n", "------", "--------------------");

    // Insert code here
    int x, y;

    for (x = 0; x < MATRIX_MAX; x++) {
        printf("%-7d", x);
        for (y = 0; y < MATRIX_MAX; y++) {
            printf("%-5d ", matrix[x][y] == INF ? -1 : matrix[x][y]);
        }
        printf("\n");
    }

    printf("\n\n");
    system("Pause");
}

void initializeMatrix(MATRIX matrix) {
    // Code here
    int x, y;

    for (x = 0; x < MATRIX_MAX; x++) {
        for (y = 0; y < MATRIX_MAX; y++) {
            matrix[x][y] = -1;
        }
    }
}

/************************************************************
 *  Problem 2:: Function Definitions                          *
 ************************************************************/
void populateMatrix(MATRIX matrix) {
    MATRIX data = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    // Logic here
    int x, y;
    for (x = 0; x < MATRIX_MAX; x++) {
        for (y = 0; y < MATRIX_MAX; y++) {
            matrix[x][y] = data[x][y];
        }
    }
}

/************************************************************
 *  Problem 3:: Function Definitions                          *
 ************************************************************/
void displayList(LIST list) {
    printf("\n\nDetails of the List :: ");
    printf("\n---------------------------");
    printf("\n\n%-7s", "Source");
    printf("%15s", "Connected Vertices (cost)");
    printf("\n%-7s%15s\n", "------", "--------------------");

    // Insert code here
    int x;
    Node trav;
    for (x = 0; x < OPEN_MAX; x++) {
        printf("%-7d", x);
        for (trav = list[x]; trav != NULL; trav = trav->edge) {
            printf("%-2d (%-3d) | ", trav->vertex, trav->cost == INF ? -1 : trav->cost);
        }
        printf("\n");
    }
    printf("\n\n");
    system("Pause");
}
void initList(LIST *L) {
    int x;

    for (x = 0; x < OPEN_MAX; x++) {
        (*L)[x] = NULL;
    }
}
LIST *convertToList(MATRIX matrix) {
    LIST *L = (LIST *)malloc(sizeof(LIST));
    if (L != NULL) {
        initList(L);
        int x, y;
        
        for (x = 0; x < MATRIX_MAX; x++) {
            for (y = MATRIX_MAX - 1; y > -1; y--) {
                if (matrix[x][y] != INF) {
                    Node temp = (Node)malloc(sizeof(struct node));
                    if (temp != NULL) {
                        temp->vertex = y;
                        temp->cost = matrix[x][y];
                        temp->edge = (*L)[x];
                        (*L)[x] = temp;
                    }
                }
            }
        }
    }

    return L;
}

/************************************************************
 *  Problem 4:: Function Definitions                          *
 ************************************************************/
void displayVHeap(VHeap VH) {
    // Variable Declaration here
    int x;

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", VH->avail); // Complete this statement
    printf("\nVHeap Address    ::  %x", VH);       // Complete this statemet

    printf("\n\n%10s", "Index");
    printf("%10s", "Vertex");
    printf("%10s", "Cost");
    printf("%15s", "Next Field");
    printf("\n%10s%10s%10s%15s\n", "-----", "------", "----", "----------");

    // Write your code here
    for (x = 0; x < VH_MAX; x++) {
        printf("%10d", x);
        printf("%10d", VH->nodes[x].vertex);
        printf("%10d", VH->nodes[x].cost);
        printf("%10d\n", VH->nodes[x].edge);

    }

    printf("\n\n");
    system("Pause");
}
VHeap initVHeap() {
    VHeap VH = (VHeap)malloc(sizeof(struct heap));

    if (VH != NULL) {
        int x;

        for (x = 0; x < VH_MAX; x++) {
            VH->nodes[x].vertex = -1;
            VH->nodes[x].cost = -1;
            VH->nodes[x].edge = x - 1;
        }

        VH->avail = x - 1;
    }

    return VH;
}

/************************************************************
 *  Problem 5:: Function Definitions                          *
 ************************************************************/
void displayCursor(CURSOR cursor) {
    printf("\n\nDetails of the Cursor :: ");
    printf("\n---------------------------");
    printf("\n\n%-7s", "Source");
    printf("%15s", "Connected Vertices (cost)");
    printf("\n%-7s%15s\n", "------", "--------------------");

    // Insert code here
    int group, trav;
    for (group = 0; group < CLOSE_MAX; group++) {
        printf("%-7d", group);
        for (trav = cursor.header[group]; trav != -1; trav = cursor.VH->nodes[trav].edge) {
            printf("%-2d (%-3d) | ", cursor.VH->nodes[trav].vertex, cursor.VH->nodes[trav].cost);
        }
        printf("\n");
    }
    printf("\n\n");
    system("Pause");
}
void initCursor(CURSOR *CS, VHeap VH) {
    CS->VH = VH;

    int x;
    for (x = 0; x < CLOSE_MAX; x++) {
        CS->header[x] = -1;
    }
}

/************************************************************
 *  Problem 6:: Function Definitions                          *
 ************************************************************/
void convertToCursor(LIST *L, CURSOR *CS) {
    int group;
    Node trav;
    for (group = 0; group < OPEN_MAX; group++) {
        int *cTrav = &CS->header[group];
        for (trav = (*L)[group]; trav != NULL; trav = trav->edge) {
            if (CS->VH->avail != -1) {
                int temp = CS->VH->avail;
                CS->VH->avail = CS->VH->nodes[temp].edge;

                CS->VH->nodes[temp].vertex = trav->vertex;
                CS->VH->nodes[temp].cost = trav->cost;
                CS->VH->nodes[temp].edge = -1;
                *cTrav = temp;
                cTrav = &CS->VH->nodes[temp].edge;
            }
        }
    }
}

/************************************************************
 *  Problem 7:: Function Definitions                          *
 ************************************************************/
void convertToMatrix(LIST *L, MATRIX matrix) {
    int group;
    Node trav;
    for (group = 0; group < OPEN_MAX; group++) {
        for (trav = (*L)[group]; trav != NULL; trav = trav->edge) {
            matrix[group][trav->vertex] = trav->cost;
        }
    }
}
