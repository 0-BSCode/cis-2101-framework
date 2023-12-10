#ifndef GRAPHIMPLEMENTATION_V1
#define GRAPHIMPLEMENTATION_V1

#define MATRIX_MAX 5
#define OPEN_MAX 5
#define VH_MAX 15
#define CLOSE_MAX 5
#define INF __INT_MAX__

// Matrix implementation
typedef int MATRIX[MATRIX_MAX][MATRIX_MAX];

// Open Dictionary implementation
typedef struct node {
    int vertex;
    int cost;
    struct node *edge;
} *Node;

typedef Node LIST[OPEN_MAX];

// Cursor-based implementation
typedef struct {
    int vertex;
    int cost;
    int edge;
} VH_Node;

typedef struct heap {
    VH_Node nodes[VH_MAX];
    int avail;
} *VHeap;

typedef struct {
    int header[CLOSE_MAX];
    VHeap VH;
} CURSOR;

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void displayMatrix(MATRIX matrix);
void initializeMatrix(MATRIX matrix);

//---Problem #2 ---
void populateMatrix(MATRIX matrix);

//---Problem #3 ---
void displayList(LIST list);
void initList(LIST *L);
LIST *convertToList(MATRIX matrix);

//---Problem #4 ---
void displayVHeap(VHeap VH);
VHeap initVHeap();

//---Problem #5 ---
void displayCursor(CURSOR cursor);
void initCursor(CURSOR *cursor, VHeap VH);

//---Problem #6 ---
void convertToCursor(LIST *L, CURSOR *CS);

//---Problem #7 ---
void convertToMatrix(LIST *L, MATRIX matrix);

#endif