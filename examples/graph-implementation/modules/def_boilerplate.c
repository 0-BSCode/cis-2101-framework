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

    printf("\n\n");
    system("Pause");
}

void initializeMatrix(MATRIX matrix) {
    // Insert code here
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

    // Insert code here
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

    printf("\n\n");
    system("Pause");
}
void initList(LIST *L) {
    // Insert code here
}
LIST *convertToList(MATRIX matrix) {
    // Insert code here
}

/************************************************************
 *  Problem 4:: Function Definitions                          *
 ************************************************************/
void displayVHeap(VHeap VH) {
    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", VH->avail); // Complete this statement
    printf("\nVHeap Address    ::  %x", VH);       // Complete this statemet

    printf("\n\n%10s", "Index");
    printf("%10s", "Vertex");
    printf("%10s", "Cost");
    printf("%15s", "Next Field");
    printf("\n%10s%10s%10s%15s\n", "-----", "------", "----", "----------");

    // Insert code here

    printf("\n\n");
    system("Pause");
}
VHeap initVHeap() {
    // Insert code here
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

    printf("\n\n");
    system("Pause");
}
void initCursor(CURSOR *CS, VHeap VH) {
    // Insert code here
}

/************************************************************
 *  Problem 6:: Function Definitions                          *
 ************************************************************/
void convertToCursor(LIST *L, CURSOR *CS) {
    // Insert code here
}

/************************************************************
 *  Problem 7:: Function Definitions                          *
 ************************************************************/
void convertToMatrix(LIST *L, MATRIX matrix) {
    // Insert code here
}
