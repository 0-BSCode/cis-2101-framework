#ifndef GRAPHIMPLEMENTATION_V1
#define GRAPHIMPLEMENTATION_V1

#define MATRIX_MAX 5
#define OPEN_MAX 5
#define VH_MAX 15
#define CLOSE_MAX 5

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

typedef struct {
    VH_Node nodes[VH_MAX];
    int avail;
} *VHeap;

typedef struct {
    int header[CLOSE_MAX];
    int lastNdx;
    VHeap VH;
} CURSOR;

/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void displayMatrix(MATRIX matrix);

//---Problem #2 ---
void populateMatrix(MATRIX matrix);

//---Problem #3 ---
void displayList(LIST list);
void initList(LIST *L);
LIST *convertToList(MATRIX matrix);

//---Problem #4 ---
void displayVHeap(VHeap VH);
void displayCursor(CURSOR cursor);
VHeap initVHeap();
void initCursor(CURSOR *cursor);

//---Problem #5 ---
CURSOR convertToCursor(VHeap *VH);

#endif