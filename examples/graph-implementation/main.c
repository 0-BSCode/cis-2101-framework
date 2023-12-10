#include "modules/v1/_header.h"
#include <stdio.h>

int main() {
    /*---------------------------------------------------------------------------------
     * 	Problem #1 ::  1) Initializes the matrix * 2)
     *  Displays the content of the matrix         *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #1:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #1
    MATRIX m;

    // Function Calls for Problem #1
    initializeMatrix(m);
    displayMatrix(m);

    /*---------------------------------------------------------------------------------
     * 	Problem #2 ::  1) Populates the matrix * 2)
     *  Displays the content matrix        *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #2:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #2

    // Function Calls for Problem #2
    populateMatrix(m);
    displayMatrix(m);
    /*---------------------------------------------------------------------------------
     * 	Problem #3 ::  1) Converts the matrix into a list * 2)
     *  Displays the list        *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #3:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #3
    LIST *L;
    // Function Calls for Problem #3
    L = convertToList(m);
    displayList(*L);
    /*---------------------------------------------------------------------------------
     * 	Problem #4 ::  1) Initializes the virtual heap and cursor-based graph * 2)
     *  Displays the empty virtual heap       *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #4:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #4
    VHeap VH;

    // Function Calls for Problem #4
    VH = initVHeap();
    displayVHeap(VH);

    /*---------------------------------------------------------------------------------
     * 	Problem #5 ::  1) Initializes the cursor-based graph * 2)
     *  Displays the cursor-based graph        *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #5:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #5
    CURSOR CS;

    // Function Calls for Problem #5
    initCursor(&CS, VH);
    displayCursor(CS);

    /*---------------------------------------------------------------------------------
     * 	Problem #6 ::  1) Converts the list to a cursor-based graph * 2)
     *  Displays the virtual heap and cursor-based graph        *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #6:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #6

    // Function Calls for Problem #6
    convertToCursor(L, &CS);
    displayCursor(CS);
    displayVHeap(CS.VH);

    /*---------------------------------------------------------------------------------
     * 	Problem #7 ::  1) Initializes a new adjacency matrix* 2)
     *  Converts the list into a matrix* 3) Displays the matrix
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #7:: ");
    printf("\n------------\n");
    // Declare variables needed for Problem #7
    MATRIX newMatrix;
    // Function Calls for Problem #7
    initializeMatrix(newMatrix);
    convertToMatrix(L, newMatrix);
    displayMatrix(newMatrix);
    return 0;
}